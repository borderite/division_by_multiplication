#ifndef MACRO_TOOLS_H
#define MACRO_TOOLS_H

#define concat2_helper(p1, p2) p1##p2
#define concat2(p1, p2) concat2_helper(p1, p2)
#define concat3_helper(p1, p2, p3) p1##p2##p3
#define concat3(p1, p2, p3) concat3_helper(p1, p2, p3)
#define concat4_helper(p1, p2, p3, p4) p1##p2##p3##p4
#define concat4(p1, p2, p3, p4) concat4_helper(p1, p2, p3, p4)

#endif
