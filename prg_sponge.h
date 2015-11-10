#ifndef incprgSponge_h
#define incSponge_h
  #include <inttypes.h>
  #include <stdlib.h>
  #include <stdint.h>
#include "sponge.h"
  
  #define prg_sponge 0xD001


#define Keccak_code_l_out_of_range RETURN_CODE(Keccak_module, -20);
#define Keccak_code_invalid_state_size RETURN_CODE(Keccak_module, -21);

