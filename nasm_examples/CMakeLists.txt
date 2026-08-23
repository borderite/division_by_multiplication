add_library(div_by_mult STATIC)
target_sources(div_by_mult
  PRIVATE
  unsigned_div_by_3_32.asm
  unsigned_div_by_7_32.asm
  signed_div_by_3_32.asm
  signed_div_by_7_32.asm
  signed_div_by_neg_5_32.asm
  signed_div_by_neg_3_32.asm
  unsigned_div_by_3_64.asm
  unsigned_div_by_21_64.asm
  signed_div_by_3_64.asm
  signed_div_by_21_64.asm
  signed_div_by_neg_5_64.asm
  signed_div_by_neg_3_64.asm
  INTERFACE
  div_by_mult.h
)
