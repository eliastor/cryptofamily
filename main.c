#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "sponge.h"
  uint64_t buf[128];
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
  
  Sponge_init(&Sponge);
  
  return 0;
}
