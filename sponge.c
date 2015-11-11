#include "sponge.h"



/// rewrite initialization and limitations. 
int Sponge_init(Sponge_t *Sponge){
  if((Sponge->size > Sponge_size_max) || (Sponge->size < Sponge_size_min)){ //maybe it's better to use assert, but we haven't stderr
    return Sponge_code_size_out_of_range;
  }
  if((Sponge->size % 8) !=0){
    return Sponge_code_invalid_size;
  }
  if(Sponge->state == NULL){
    return Sponge_code_null_state;
  }
  
  if((Sponge->size < Sponge->r)|((Sponge->size % 8)!= 0)){
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
  //does we need to allocate automatically
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


int Sponge_absorb(Sponge_t *Sponge, void *data){///rewrite: use ladder 64->32->8 bit transfer sequently.
  //we expect that data is valid and have apropriate length
  size_t i;
  
  ///we can use wise transfer: at first 64bit transfer as much data as possible. then use 8bit transfer for tail data.
  if((Sponge->r % (sizeof(uint64_t)) == 0)){//determine can we use 64bit transfer
    for(i = 0; i < Sponge->r / (sizeof(uint64_t)*8); i++){
      ((uint64_t *)Sponge->state)[i] ^= ((uint64_t *)data)[i];
    }
  } else if((Sponge->r % (sizeof(uint32_t)) == 0)){//determine can we use 32bit transfer
    for(i = 0; i < Sponge->r / (sizeof(uint32_t)*8); i++){
      ((uint32_t *)Sponge->state)[i] ^= ((uint32_t *)data)[i];
    }
  } else{//otherwise we use 8bit transfer
    for(i = 0; i < Sponge->r / (sizeof(uint8_t)*8); i++){
      ((uint8_t *)Sponge->state)[i] ^= ((uint8_t *)data)[i];
    }
  }
  (Sponge->transformation_callback)(Sponge);
  return (int) Sponge->size;
}

int Sponge_squeeze(Sponge_t *Sponge, void *data){///rewrite: use ladder 64->32->8 bit transfer sequently.
  //we expect that data is a chunk of valid size.
    size_t i;
  if((Sponge->r % (sizeof(uint64_t)) == 0)){//determine can we use 64bit transfer
    for(i = 0; i < Sponge->r / (sizeof(uint64_t)*8); i++){
      ((uint64_t *)data)[i] = ((uint64_t *)Sponge->state)[i];
    }
  } else if((Sponge->r % (sizeof(uint32_t)) == 0)){//determine can we use 32bit transfer
    for(i = 0; i < Sponge->r / (sizeof(uint32_t)*8); i++){
      ((uint32_t *)Sponge->state)[i] ^= ((uint32_t *)data)[i];
    }
  } else{//otherwise we use 8bit transfer
    for(i = 0; i < Sponge->r / (sizeof(uint8_t)*8); i++){
      ((uint8_t *)Sponge->state)[i] ^= ((uint8_t *)data)[i];
    }
  }
  (Sponge->transformation_callback)(Sponge);
  return 1;
}
inline int Sponge_PRNG_add_seed(Sponge_t *Sponge, void *data){
  return Sponge_absorb(Sponge, data);
}
inline int Sponge_PRNG_tick(Sponge_t *Sponge, void *data){
  return Sponge_squeeze(Sponge, data);
}
