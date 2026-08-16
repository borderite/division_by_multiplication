#define DIVISOR 21
#define BITWIDTH 64

#define concat2_helper(param1, param2) param1##param2
#define concat2(param1, param2) concat2_helper(param1, param2)
#define INT_MAX concat2(INT, BITWIDTH)
INT_MAX
    

