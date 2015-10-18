#ifndef incStretchint_h

#define incStretchint_h

#define LMbigint_module 0x0FF2

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "../macros/concat.h"
#include "../macros/min_max.h"
#include "../macros/module.h"
#include <assert.h>
#include <string.h>

typedef struct {
  uint16_t length;
  uint16_t RESERVED;
  uint32_t *data;
}

#endif