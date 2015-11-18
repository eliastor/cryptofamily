#ifndef incSHA3_h
#define incSHA3_h
  #include <inttypes.h>
  #include <stdlib.h>
  #include <stdint.h>
#include "sponge.h"
#include "littlemorelongint.h"
  
  #define SHA3_module 0xC011

/*we will define only 256bit, 384bit and 512bit hashes. it covers all security necessaries*/
typedef enum{
  SHA3_256 = 256,
  SHA3_384 = 384,
  SHA3_512 = 512
}SHA3_hash_length;

void SHA3(void *data, size_t length);

#define SHA3_code_l_out_of_range RETURN_CODE(SHA3_module, -20);

#endif