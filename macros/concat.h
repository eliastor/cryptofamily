#ifndef incCONCAT_MACRO
#define incCONCAT_MACRO
#define __CONCAT(a, b) a ## b
#define CONCAT(a, b) __CONCAT(a,b)
#define _RESERVED CONCAT(reserved, __LINE__)
#endif