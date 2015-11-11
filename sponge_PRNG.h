#ifndef incRNG_h

#define incRNG_h

#define PRNG_module 0xF001

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "macros/concat.h"
#include "macros/min_max.h"
#include "macros/module.h"
#include "macros/depreceted.h"
#include "helper/binary.c"
#include <assert.h>
#include <string.h>

typedef struct {
  
} Random_generator_t

typedef int (*block_cipher_transformation_t)(void *data, size_t blocksize, void *key size_t keysize);
typedef int (*block_cipher_initialization_t)(void *data, size_t blocksize, void *key size_t keysize, void *iv, size_t iv_size);
typedef enum{
  block_cipher_mode_ECB; // 
  block_cipher_mode_CBC;
  block_cipher_mode_CFB;
  DEPRECATED block_cipher_mode_OFB; 
  block_cipher_mode_CTR;
} block_cipher_mode_t 

typedef struct{
  block_cipher_initialization_t ciphen_init;
  block_cipher_transformation_t iteration;
  block_cipher_transformation_t cipher_crypt;
  block_cipher_transformation_t cipher_decrypt;
  block_cipher_mode_t mode;
  uint32_t *state;
  size_t state_size;
  size_t block_size;
  size_t key_size;
}block_cipher_t

#endif