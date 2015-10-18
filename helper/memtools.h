#ifndef incMemTools_h

#define incMemTools_h

#define Sponge_module 0xFFFE

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "../macros/concat.h"
#include "../macros/min_max.h"
#include "../macros/module.h"
#include <assert.h>
#include <string.h>

int memtools_memcpy(void *out, const void* in, size_t size);

#endif