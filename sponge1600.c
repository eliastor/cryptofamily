#include "sponge1600.h"



/// rewrite initialization and limitations. 
int Sponge_init(Sponge_t *Sponge){
  if(Sponge->state == NULL){
    return Sponge_code_null_state;
  }
  
  if((Sponge_x_current_size < Sponge->r)|((Sponge->size % 8)!= 0)){
    return Sponge_code_invalid_r;
  }
  
  if(((Sponge->size / Sponge->r) == 0) || ((Sponge->size % Sponge->r) != 0)){
    return Sponge_code_invalid_r;
  }
  
  if(Sponge->transformation_callback == (Sponge_transformation_callback_t) NULL){
    return Sponge_code_null_callback;
  }
  if(Sponge->padding_callback == (Sponge_padding_callback_t) NULL){
    return Sponge_code_null_callback;
  }
#ifndef __ALLOC_ON
  //does we need to allocate automatically?
#else
#endif
  
      /*
    uint64_t *state =((uint64_t *) (Sponge->state));
    size_t state_size = Sponge_b_values[Sponge->l];
    for(i=0; i<state_size;i++){
      //correst//uint64_t value =  ((uint64_t*) (Sponge->state))[i];// cast pointer of array to uint64_t* then count i elements and return i-th element.
      state[i] = 0ULL;
    }*/
 
  
  if((Sponge->state != NULL)){
    //register size_t i;
    Sponge->state = memset(Sponge->state, 0, Sponge->size / 8);
  }
  return 1;
}


int Sponge_pad_data_null(Sponge_t Sponge, const void* input, void* output, size_t output_size){
  size_t input_size = Sponge.r / (sizeof(uint8_t)*8);
  if(input_size > output_size){
    return Sponge_code_data_too_big;
  }  
  
  size_t i;
  memcpy(output, input, input_size);
  for(i=input_size; i<output_size; i++){
    *((char*)output) = 0x00;
  }
  
  return 1;
}

int Sponge_default_padding(Sponge_t Sponge, const void* input, void* output, size_t output_size){
  
  return 1;
}


inline int Sponge_absorb_block(Sponge_t *Sponge, void *data){///rewrite: use ladder 128->64->32->8 bit transfer sequently.
  //we expect that data is valid and have apropriate length
  size_t i;
  for(i = 0; i < Sponge->r / (sizeof(uint64_t)*8); i++){
    ((uint64_t *)Sponge->state)[i] ^= ((uint64_t *)data)[i];
  }
  (Sponge->transformation_callback)(Sponge);
  return (int) Sponge->size;
}

inline int Sponge_squeeze_block(Sponge_t *Sponge, void *data){
  //we expect that data is a chunk of valid size.
  memcpy(data, (const void *) Sponge->state), Sponge->r / sizeof(uint8_t)*8);
  (Sponge->transformation_callback)(Sponge);
  return 1;
}
inline int Sponge_PRNG_add_seed(Sponge_t *Sponge, void *data){
  return Sponge_absorb(Sponge, data);
}
inline int Sponge_PRNG_tick(Sponge_t *Sponge, void *data){
  return Sponge_squeeze(Sponge, data);
}
