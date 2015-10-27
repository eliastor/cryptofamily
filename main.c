#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "sponge.h"
  uint64_t buf[128];

void T(Sponge_t *Sponge){
  
}

int main()
{

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
