#include "memtools.h"
int memtools_memcpy(void *out, const void* in, size_t size){
  size_t i;
  //because we made code for ARM it's better to use multiply store and load registers functions. it can give us 128bit access
  
  for(i=0; i < size / (sizeof(uint64_t)); i+=8){
    const uint64_t *_in = &((const uint64_t *) in)[i>>3];
    uint64_t *_out = &((uint64_t *) out)[i>>3];    
    *_out = *_in;
  }
  for(; i < size; i++){
    const uint8_t *_in = &((const uint8_t *) in)[i];
    uint8_t *_out = &((uint8_t *) out)[i];
    *_out = *_in;
  }
  return 1;
}