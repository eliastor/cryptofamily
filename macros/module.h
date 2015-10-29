#ifndef MACRO_module
#define MACRO_module
#include "concat.h"
#define RETURN_CODE(module,code) ((int) ( ( ((uint16_t) code) <<  ((sizeof(int)*8)-16)) | (uint16_t) module) )

#endif