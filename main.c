#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "sponge.h"
#include "keccak.h"

  static uint64_t buf[128];
  uint32_t sponge_PRNG_state[1600/32]; /*idealy it shouldn't be initialized.*/
  Sponge_t sponge_PRNG;

void T(Sponge_t *Sponge){
  
}

int rnd_init(){
  
  //we should seed initial state by following code:
  sponge_PRNG.padding_callback = Sponge_default_padding;
  sponge_PRNG.state = (void *) sponge_PRNG_state;
  sponge_PRNG.transformation_callback = keccak_f;
  sponge_PRNG.r = 32;
  sponge_PRNG.size = 1600;
  if(Sponge_init(&sponge_PRNG)){
    //eggog;
  }
#define Total_entropy 1024
  size_t i;
  for(i=0;i<Total_entropy/32; i++){
    uint32_t entropy = (0xDEADBEAF); // here you should write your entropy i've get somewhere(for example hardware true random generator) 
    Sponge_PRNG_add_seed(&sponge_PRNG, &entropy);
  }
  return 1;
}

uint32_t rnd(){
  uint32_t data;
  Sponge_PRNG_tick(&sponge_PRNG, &data);
  return data;
}

int main(){
  
  
  //if we want to get random number just make Sponge_PRNG_tick()
  
  register uint32_t i;
  
  for(i=0; i<128*8; i+=0){
    char *ptr = &((char *)buf)[i];
    ptr[0]= (char) i++;
    ptr[1]= (char) i++;
    ptr[2]= (char) i++;
    ptr[3]= (char) i++;
    ptr[4]= (char) i++;
    ptr[5]= (char) i++;
    ptr[6]= (char) i++;
    ptr[7]= (char) i++;
  }
  
  
  
  Sponge_t Sponge = Sponge_null;
  Sponge.state = (void *) &buf;
  Sponge.padding_callback = (Sponge_padding_callback_t) Sponge_pad_data_null;
  Sponge.transformation_callback = (Sponge_transformation_callback_t) T;
  Sponge.size = 1600;
  Sponge.r = 64;
  
  Sponge_init(&Sponge);
  
  
  return 0;
}
