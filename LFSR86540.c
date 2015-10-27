#include "LFSR86540.h"
bool LFSR86540(uint8_t *state)
{
    bool result = (*state & 0x01) != 0;
    if ((*state & 0x80) != 0)
        *state = (*state << 1) ^ 0x71;
    else
        *state <<= 1;
    return result;
}
void lsfr86540_initialize_RC(uint64_t *RC, size_t size){
  uint8_t LFSRstate = 0x01;
  register size_t i;
  for(i=0; i<size; i++) {
    uint64_t c = 0;
    for(unsigned int j=0; j<7; j++) {
      if (LFSR86540(&LFSRstate)){
        unsigned int bitPosition = (1<<j)-1; //2^j-1
        c^= (uint64_t)1<<bitPosition;
      }
    }
    RC[i]= c;
  }
  return;
}