#ifndef incEC
#define inEC

#define EC_module 0x1001

#include "stretchint.h"

#include "stdarg.h"
#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "macros/concat.h"
#include "macros/min_max.h"
#include "macros/module.h"
#include "helper/binary.c"
#include <assert.h>
#include <string.h>

typedef enum{
    EC_Weierstrass = 0x01,
    EC_Montgomery = 0x02,
    EC_Edwards = 0x3,
} ec_curve_type_t;

typedef struct{
  uintx_t a;
  uintx_t b;
  uintx_t m;
  ec_curve_type_t type;
} ec_curve_t;

typedef enum{
    EC_POINT_BASIS_AFFINE = 0x01,
    EC_POINT_BASIS_PROJECTIVE = 0x02,
    EC_POINT_BASIS_INVERTED = 0x03
} ec_basis_t;

typedef struct {
  ec_basis_t basis;
  uintx_t x;
  uintx_t y;
  uintx_t z;
  uintx_t RESERVED;
}ec_point_t;

typedef struct{
  ec_curve_t curve;
  ec_point_t base;
  uint32_t cofactor;
  uint32_t RESERVED[16];
}ec_domain_t;

#define EC_code_invalid_a_parameter RETURN_CODE(EC_module,-10)

#endif