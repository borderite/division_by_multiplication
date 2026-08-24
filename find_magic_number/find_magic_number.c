#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <gmp.h>

void usage(char* cmd) {
  fprintf(stderr, "Usage: %s [-h] [-u] [-v] [--] <bitwidth> <divisor>\n", cmd);
  fprintf(stderr, "\n");
  fprintf(stderr, "  -h: Help\n");
  fprintf(stderr, "  -u: Unsigned division\n");
  fprintf(stderr, "  -v: Verbose output\n");
  fprintf(stderr, "\n  * If the divisor is negative, \"--\" must be put in the parameter list.\n\n");
}

int parse_parameters(int argc, char* argv[], bool* is_signed, uint32_t* W,
                     mpz_t d, bool* verbose) {
  *is_signed = true;
  *verbose = false;
  int opt;
  while ((opt = getopt(argc, argv, "huv")) != -1) {
    switch (opt) {
    case 'h':
      usage(argv[0]);
      return 1;
    case 'u':
      *is_signed = false;
      break;
    case 'v':
      *verbose = true;
      break;
    case '?':
      usage(argv[0]);
      return 1;
    default:
      usage(argv[0]);
      abort();
    }
  }
  if (argc - optind < 2) {
    fprintf(stderr, "Error: The bitwidth and/or the divisor are missing.\n\n");
    usage(argv[0]);
    return 1;
  }
  if (argv[optind][0] == '-') {
    fprintf(stderr, "Error: The bitwidth cannot be negative.\n\n");
    usage(argv[0]);
    return 1;
  }  
  if (sscanf(argv[optind], "%u", W) != 1) {
    fprintf(stderr, "Error: Invalid bitwidth.\n\n");
    usage(argv[0]);
    return 1;
  }
  if (*W <= 2) {
    fprintf(stderr, "Error: The bitwidth must be greater than two.\n\n");
    return 1;
  }
  ++optind;
  if (mpz_set_str(d, argv[optind], 10) != 0) {
    fprintf(stderr, "Error: Invalid divisor.\n\n");
    usage(argv[0]);
    return 1;
  }
  int d_sign = mpz_sgn(d);
  if (d_sign == 0) {
    fprintf(stderr, "Error: The divisor must be nonzero.\n\n");
    return 1;
  }
  if (!*is_signed && d_sign < 0) {
    fprintf(stderr, "Error: The divisor cannot be negative in unsigned division.\n\n");
    usage(argv[0]);
    return 1;
  }
  return 0;
}

void find_row_params(mpz_t N, mpz_t d, uint32_t* p, mpz_t m) {
  mpz_t N_half;
  mpz_t nbar;
  mpz_t rhs_factor;
  mpz_t d_minus_1;
  mpz_t two_to_p;
  mpz_t one;
  mpz_t lhs;
  mpz_t rhs;
  mpz_inits(N_half, nbar, rhs_factor, d_minus_1, two_to_p, one, lhs, rhs, NULL);
  mpz_set_si(one, 1);
  // nbar = N - (N mod d) - 1
  mpz_fdiv_r(nbar, N, d); // nbar = N mod d
  mpz_sub(nbar, N, nbar); // nbar = N - (N mod d)
  mpz_sub_ui(nbar, nbar, 1); // nbar = N - (N mod d) - 1
  // rhs_factor = (nbar + 1) / d
  mpz_add_ui(rhs_factor, nbar, 1); // rhs_factor = nbar + 1
  mpz_divexact(rhs_factor, rhs_factor, d);
  // d_minus_1 = d - 1
  mpz_sub_ui(d_minus_1, d, 1);
  // *p = floor(log2(floor(N/2))) + 1
  mpz_fdiv_q_2exp(N_half, N, 1);  // N_half = floor(N/2)
  *p = mpz_sizeinbase(N_half, 2); // *p = floor(log2(floor(N/2)) + 1
  // two_to_p = 2 ** *p
  mpz_mul_2exp(two_to_p, one, *p);
  for (;;) {
    // m = ceil(2 ** p / d)
    mpz_add(m, two_to_p, d_minus_1); // m = 2 ** p + d - 1
    mpz_div(m, m, d);                // m = (2 ** p + d - 1) / d
    // lhs = nbar * m
    mpz_mul(lhs, nbar, m);
    // rhs = rhs_factor * 2 ** p
    mpz_mul(rhs, rhs_factor, two_to_p);
    if (mpz_cmp(lhs, rhs) < 0)
      break;
    ++*p;
    mpz_mul_2exp(two_to_p, two_to_p, 1);
  }
  mpz_clears(N_half, nbar, rhs_factor, d_minus_1, two_to_p, one, lhs, rhs, NULL);
}

int main(int argc, char* argv[]) {
  bool is_signed = true;
  bool verbose = false;
  uint32_t W;
  mpz_t d;
  mpz_init(d);
  if (parse_parameters(argc, argv, &is_signed, &W, d, &verbose) != 0) {
    mpz_clear(d);
    return 1;
  }    
  uint32_t p;
  uint32_t s = 0;
  bool is_m_large = false;
  mpz_t m;
  mpz_t M;
  mpz_t N;
  mpz_t one;
  mpz_inits(m, M, N, one, NULL);
  mpz_set_ui(one, 1);
  if (verbose) {
    printf("========== Inputs ==========\n");
    printf("is_signed = %s\n", is_signed ? "true" : "false");
    printf("W = %d\n", W);
    printf("d = ");
    mpz_out_str(stdout, 10, d);
    printf("\n");
  }
  // Debugging end
  if (is_signed) {
    if (mpz_sgn(d) > 0) {
      mpz_mul_2exp(N, one, W - 1); // N = 2 **（W - 1)
      find_row_params(N, d, &p, m);
      if (mpz_cmp(m, N) >= 0) {
        is_m_large = true;
        s = p - W;
        mpz_mul_2exp(N, N, 1); // N = 2 ** W
        mpz_sub(M, m, N);      // M = m - 2 ** W
      } else {
        mpz_set(M, m);
      }
    } else {
      mpz_mul_2exp(N, one, W - 1); // N = 2 **（W - 1)
      mpz_add_ui(N, N, 1);         // N = 2 **（W - 1) + 1
      mpz_neg(d, d);               // d = -d
      find_row_params(N, d, &p, m);
      if (mpz_cmp(m, N) >= 0) {
        is_m_large = true;
        s = p - W;
        mpz_mul_2exp(N, one, W); // N = 2 ** W
        mpz_sub(M, m, N);        // M = m - 2 ** W
      } else {
        mpz_set(M, m);
      }
    }
  } else {
    mpz_mul_2exp(N, one, W);
    find_row_params(N, d, &p, m);
    if (mpz_cmp(m, N) >= 0) {
      is_m_large = true;
      s = p - W;
      mpz_sub(M, m, N); // M = m - 2 ** W
    } else {
      mpz_set(M, m);
    }
  }
  if (verbose)
    printf("========== Outputs ==========\n");
  printf("p = %u\n", p);
  size_t bitlen = mpz_sizeinbase(m, 2);
  printf("m = ");
  mpz_out_str(stdout, 10, m);
  printf(" (%lu bits)\n", bitlen);
  if (is_m_large) {
    printf("The magic number m does not fit in %u bits. ", W);
    printf("You need to use the modified formula with the following numbers.\n");
    bitlen = mpz_sizeinbase(M, 2);
    printf("M = m - 2 ** %u = ", W);
    mpz_out_str(stdout, 10, M);
    printf(" (%lu bits)\n", bitlen);
    printf("s = p - %u = %u\n", W, s);
    mpz_clears(d, m, M, N, one, NULL);
  }    
  return 0;
}
