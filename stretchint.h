#ifndef incStretchint_h

#define incStretchint_h

#define LMbigint_module 0x0FF2

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "macros/concat.h"
#include "macros/min_max.h"
#include "macros/module.h"
#include <assert.h>
#include <string.h>
#include <math.h>

#ifndef __ALLOC_ON
  #warning "UINTx: No HEAP allocation is defined. only staticly defined numbers are valid."
#else

#endif

typedef struct {
  uint16_t length;
  uint16_t RESERVED;
  uint32_t *data;
} uintx_t;

int uintx_add(uintx_t a, uintx_t b, uintx_t *r);
int uintx_sub(uintx_t a, uintx_t b, uintx_t *r);
int uintx_mul(uintx_t a, uintx_t b, uintx_t *r);
int uintx_mod(uintx_t a, uintx_t m, uintx_t *r);
int uintx_revmod(uintx_t a, uintx_t m, uintx_t *r);
int uintx_cmp(uintx_t a, uintx_t b);
int uintx_ge(uintx_t a, uintx_t b);
int uintx_le(uintx_t a, uintx_t b);
int uintx_eq(uintx_t a, uintx_t b);
int uintx_mulmod(uintx_t a, uintx_t b, uintx_t m, uintx_t *r);
int uintx_invmod(uintx_t a, uintx_t m, uintx_t *r);
int uintx_divmod(uintx_t a, uintx_t b, uintx_t m, uintx_t *remainder, uintx_t *quotient);



/*----------------------------------------------------------------------------*/
///implement pow

#define uintx_code_invalid_r_length RETURN_CODE(LMbigint_module,-10)

#endif