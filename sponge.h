#ifndef incSponge_h

#define incSponge_h

#define Sponge_module 0xACCA

#include <inttypes.h>
#include <stdlib.h>
#include <stdint.h>
#include "macros/concat.h"
#include "macros/min_max.h"
#include "macros/module.h"
#include "helper/binary.c"
#include <assert.h>
#include <string.h>


#ifndef __ALLOC_ON
  #warning "Sponge: No HEAP allocation is defined. only staticly defined states are valid.";
#else
  
#endif

#define Sponge_size_max (6400)
#define Sponge_size_min (200)

/*========Don't edit further if you don't understand what you're doing========*/

//this construction is used because of transformation_callback's arguments need to be defined to declare if without warning
typedef struct Spong_t Sponge_t;

typedef void (*Sponge_transformation_callback_t) (Sponge_t *Sponge);
typedef void (*Sponge_padding_callback_t) (Sponge_t Sponge, const void* input, void* output, size_t output_size);

struct Spong_t {
   void *state;                                                                 //state of the sponge
   Sponge_transformation_callback_t transformation_callback;                     //callback for sponge transformation function.
   Sponge_padding_callback_t padding_callback;                                  //callback for sponge padding function
   uint16_t size;                                                                //size of state
   uint16_t r;                                                                   //bitrate
};

#define Sponge_null (Sponge_t){NULL,NULL,0,0}

#define CAST_STATE_TO_TYPE(a,b) b* a##_state_##b = (b*) a->state
#define cast_type(a,b) ((b) (a))
#define CAST(a,b) cast_type(a,b)


#define Sponge_code_null_state RETURN_CODE(Sponge_module, -11)
#define Sponge_code_size_out_of_range RETURN_CODE(Sponge_module, -21)
#define Sponge_code_invalid_r RETURN_CODE(Sponge_module, -22)
#define Sponge_code_null_callback RETURN_CODE(Sponge_module, -23)
#define Sponge_code_data_too_big RETURN_CODE(Sponge_module, -24)
#define Sponge_code_invalid_size RETURN_CODE(Sponge_module,-25)

int Sponge_init(Sponge_t *Sponge);
int Sponge_pad_data_null(Sponge_t Sponge, const void* input, void* output, size_t output_size);
int Sponge_absorb(Sponge_t *Sponge, void *data);
int Sponge_squeeze(Sponge_t *Sponge, void *data);
#else

#endif