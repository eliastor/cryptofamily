#ifndef incKeccak_h
#define incKeccak_h
  #include <inttypes.h>
  #include <stdlib.h>
  #include <stdint.h>
#include "sponge.h"
  
  #define Keccak_module 0xC001

#define sha3_224_hash_size  28
#define sha3_256_hash_size  32
#define sha3_384_hash_size  48
#define sha3_512_hash_size  64
#define sha3_max_permutation_size 25
#define sha3_max_rate_in_qwords 24

#ifdef CPU_BIG_ENDIAN
# define be2me_32(x) (x)
# define be2me_64(x) (x)
# define le2me_32(x) bswap_32(x)
# define le2me_64(x) bswap_64(x)

# define be32_copy(to, index, from, length) memcpy((to) + (index), (from), (length))
# define le32_copy(to, index, from, length) rhash_swap_copy_str_to_u32((to), (index), (from), (length))
# define be64_copy(to, index, from, length) memcpy((to) + (index), (from), (length))
# define le64_copy(to, index, from, length) rhash_swap_copy_str_to_u64((to), (index), (from), (length))
# define me64_to_be_str(to, from, length) memcpy((to), (from), (length))
# define me64_to_le_str(to, from, length) rhash_swap_copy_u64_to_str((to), (from), (length))

#else /* CPU_BIG_ENDIAN */
# define be2me_32(x) bswap_32(x)
# define be2me_64(x) bswap_64(x)
# define le2me_32(x) (x)
# define le2me_64(x) (x)

# define be32_copy(to, index, from, length) rhash_swap_copy_str_to_u32((to), (index), (from), (length))
# define le32_copy(to, index, from, length) memcpy((to) + (index), (from), (length))
# define be64_copy(to, index, from, length) rhash_swap_copy_str_to_u64((to), (index), (from), (length))
# define le64_copy(to, index, from, length) memcpy((to) + (index), (from), (length))
# define me64_to_be_str(to, from, length) rhash_swap_copy_u64_to_str((to), (from), (length))
# define me64_to_le_str(to, from, length) memcpy((to), (from), (length))
#endif /* CPU_BIG_ENDIAN */

/* ROTL/ROTR macros rotate a 32/64-bit word left/right by n bits */
#define ROTL32(dword, n) ((dword) << (n) ^ ((dword) >> (32 - (n))))
#define ROTR32(dword, n) ((dword) >> (n) ^ ((dword) << (32 - (n))))
#define ROTL64(qword, n) ((qword) << (n) ^ ((qword) >> (64 - (n))))
#define ROTR64(qword, n) ((qword) >> (n) ^ ((qword) << (64 - (n))))
#define IS_ALIGNED_32(p) (0 == (3 & ((const char*)(p) - (const char*)0)))
#define IS_ALIGNED_64(p) (0 == (7 & ((const char*)(p) - (const char*)0)))

//note: we allow to use l in range 3 to 8 due to convinienvce of datatypes usage
#define Keccak_l_min 3
#define Keccak_l_max 8

typedef enum{
  Keccak_lane_size_8,
  Keccak_lane_size_16,
  Keccak_lane_size_32,
  Keccak_lane_size_64,
  Keccak_lane_size_128,
  Keccak_lane_size_256
} Keccak_lane_size;


/*Keccak_b_values - values of b parameters in dependence of l{0,..8}*/
static const size_t Keccak_b_values[Keccak_l_max+1] = {25,50,100,200,400,800,1600,3200,6400};
static const size_t Keccak_nr_values[Keccak_l_max+1] = {12,14,16,18,20,22,24,26,28};
static const size_t Keccak_w_values[Keccak_l_max+1] = {1,2,4,8,16,32,64,128,256};

//container size in bytes. note that we define only l >=3
static const size_t Keccak_container_calues[Keccak_l_max+1] = {0,0,0,1,2,4,8,8,8};

static void keccak_transformation_theta(void * data, Keccak_lane_size);



#define Keccak_code_l_out_of_range RETURN_CODE(Keccak_module, -20);
#define Keccak_code_invalid_state_size RETURN_CODE(Keccak_module, -21);


#define Keccak_b_max Keccak_b_values[Keccak_l_max+1]
#define Keccak_b_min Keccak_b_values[Keccak_l_min]

#define Keccak_nr_max Keccak_nr_values[Keccak_l_max+1]
#define Keccak_nr_min Keccak_nr_values[Keccak_l_min]

#define Keccak_w_max Keccak_w_values[Keccak_l_max+1]
#define Keccak_w_min Keccak_w_values[Keccak_l_min]

#define Keccak_state_size(l) (Keccak_b_values[l]>>3)    

#endif