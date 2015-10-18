#ifndef incLitte_more_big_int_h

#define incLitte_more_big_int_h

#define LMbigint_module 0x0FF1

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "../macros/concat.h"
#include "../macros/min_max.h"
#include "../macros/module.h"
#include <assert.h>
#include <string.h>

typedef uint32_t[4] uint128_t;
typedef uint32_t[8] uint256_t;
typedef uint32_t[16] uint512_t;

#endif