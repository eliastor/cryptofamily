#ifndef incBinary
#define incBinary 
#include "binary.h"
static inline uint64_t ROL64(uint64_t a, uint32_t b){
  return (a << b) | (a >> ((sizeof(a)*8)-b));
} 

static inline uint64_t ROR64(uint32_t a, uint32_t b){
  return (a >> b) | (a << ((sizeof(a)*8)-b));
} 

static inline uint32_t ROR32(uint32_t a, uint32_t b)
{
  return (a >> b) | (a << ((sizeof(a)*8)-b));
}

static inline uint32_t ROL32(uint32_t a, uint32_t b)
{
  return (a << b) | (a >> ((sizeof(a)*8)-b));
}
#endif