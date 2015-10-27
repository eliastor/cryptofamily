#ifndef incLitte_more_big_int_h

#define incLitte_more_big_int_h

#define LMbigint_module 0x0FF1

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "macros/concat.h"
#include "macros/min_max.h"
#include "macros/module.h"
#include <assert.h>
#include <string.h>

typedef union {
  uint32_t data[4];
  struct {
    uint32_t data[4];
  } s;
} uint128_t;
typedef struct {
  uint32_t data[8];
} uint256_t;

typedef struct {
  uint32_t data[16];
} uint512_t;

int lml_add128(uint128_t a, uint128_t b, uint128_t *r, uint32_t *c);
int lml_add256(uint256_t a, uint256_t b, uint256_t *r, uint32_t *c);
int lml_add512(uint512_t a, uint512_t b, uint512_t *r, uint32_t *c);

int lml_sub128(uint128_t a, uint128_t b, uint128_t *r, uint32_t *c);
int lml_sub256(uint256_t a, uint256_t b, uint256_t *r, uint32_t *c);
int lml_sub512(uint512_t a, uint512_t b, uint512_t *r, uint32_t *c);

int lml_mod128(uint128_t a, uint128_t b, uint128_t *r);
int lml_mod256(uint256_t a, uint256_t b, uint256_t *r);
int lml_mod512(uint512_t a, uint512_t b, uint512_t *r);

int lml_mulmod128(uint128_t a, uint128_t b, uint128_t mod, uint128_t *remainder, uint128_t quotient);
int lml_mulmod256(uint256_t a, uint256_t b, uint256_t mod, uint256_t *remainder, uint256_t quotient);
int lml_mulmod512(uint512_t a, uint512_t b, uint256_t mod, uint512_t *remainder, uint256_t quotient);


#endif