#ifndef incKeccak
#define incKeccak
#include "keccak.h"
#include <string.h>
#include <assert.h>
#define NumberOfRounds 24

/* SHA3 (Keccak) constants for 24 rounds */
static const uint64_t keccak_round_constants[28] = {
	0x0000000000000001LL, 0x0000000000008082LL, 0x800000000000808ALL, 0x8000000080008000LL,
	0x000000000000808BLL, 0x0000000080000001LL, 0x8000000080008081LL, 0x8000000000008009LL,
	0x000000000000008ALL, 0x0000000000000088LL, 0x0000000080008009LL, 0x000000008000000ALL,
	0x000000008000808BLL, 0x800000000000008BLL, 0x8000000000008089LL, 0x8000000000008003LL,
	0x8000000000008002LL, 0x8000000000000080LL, 0x000000000000800ALL, 0x800000008000000ALL,
	0x8000000080008081LL, 0x8000000000008080LL, 0x0000000080000001LL, 0x8000000080008008LL,
        0x8000000080008082LL, 0x800000008000800aLL, 0x8000000000000003LL, 0x8000000080000009LL
        /*if you want more rounds, you should generate another table using LSFR8650 function*/
};

size_t keccak_determine_l(Sponge_t *Sponge){
  size_t i;
  for(i=Keccak_l_min; i <= Keccak_l_max; i++){
    if(Keccak_b_values[i] == Sponge->size){
      return i;
    }
  }
  return 0;
}

static void keccak_transformation_pi(void * data, size_t size, size_t block_size){
  
}
static void keccak_transformation_theta(void * data, Keccak_lane_size lane_size){
  
}

void keccak_f (Sponge_t *Sponge){///reimplement this function for general case
  size_t i,l;
  for(i=0; i < Keccak_l_max+1; i++){
    if(Keccak_b_values[i] == Sponge->size) break;
  }
  if(i == (Keccak_l_max+1)){
    return;     //maybe it's better to return erro code?
  }
  l = keccak_determine_l(Sponge);
  if(Keccak_w_values[l] <= 64){
    for(i=0; i<Keccak_nr_values[l]; i++){
      keccak_round(Sponge, l ,keccak_round_constants[i] & Keccak_w_values[l]);
    }
  } else if(Keccak_w_values[l] == 128) {
    for(i=0; i<Keccak_nr_values[l]; i++){
      uint128_t _RC; 
      _RC.data[0] = 0;
      //keccak_round128(*Sponge, l, _RC);
    }
  }
  
  for(i=0; i<Sponge->size;i++);
  
}

static void keccak_round(void *Sponge, size_t l,  uint64_t RC){
  
}  

static void keccak_theta(void *state, Keccak_lane_size lane_size){  
	unsigned int x;
        uint64_t *A;
        
	uint64_t C[5], D[5];

	for (x = 0; x < 5; x++) {
		C[x] = A[x] ^ A[x + 5] ^ A[x + 10] ^ A[x + 15] ^ A[x + 20];
	}
	D[0] = ROTL64(C[1], 1) ^ C[4];
	D[1] = ROTL64(C[2], 1) ^ C[0];
	D[2] = ROTL64(C[3], 1) ^ C[1];
	D[3] = ROTL64(C[4], 1) ^ C[2];
	D[4] = ROTL64(C[0], 1) ^ C[3];

	for (x = 0; x < 5; x++) {
		A[x]      ^= D[x];
		A[x + 5]  ^= D[x];
		A[x + 10] ^= D[x];
		A[x + 15] ^= D[x];
		A[x + 20] ^= D[x];
	}
}

/* Keccak pi() transformation */
static void keccak_pi8(void *state){
	uint8_t A1;
        uint8_t *A = (uint8_t *) state;
        //1-6-9-22-14-20-2-12-13-19-23-15-4-24-21-8-16-5-3-18-17-11-7-10-1*
	A1    = A[ 1];
	A[ 1] = A[ 6];
	A[ 6] = A[ 9];
	A[ 9] = A[22];
	A[22] = A[14];
	A[14] = A[20];
	A[20] = A[ 2];
	A[ 2] = A[12];
	A[12] = A[13];
	A[13] = A[19];
	A[19] = A[23];
	A[23] = A[15];
	A[15] = A[ 4];
	A[ 4] = A[24];
	A[24] = A[21];
	A[21] = A[ 8];
	A[ 8] = A[16];
	A[16] = A[ 5];
	A[ 5] = A[ 3];
	A[ 3] = A[18];
	A[18] = A[17];
	A[17] = A[11];
	A[11] = A[ 7];
	A[ 7] = A[10];
	A[10] = A1;
	/* note: A[ 0] is left as is */
}
static void keccak_pi16(void *state){
	uint16_t A1;
        uint16_t *A = (uint16_t *) state;
        //1-6-9-22-14-20-2-12-13-19-23-15-4-24-21-8-16-5-3-18-17-11-7-10-1*
	A1    = A[ 1];
	A[ 1] = A[ 6];
	A[ 6] = A[ 9];
	A[ 9] = A[22];
	A[22] = A[14];
	A[14] = A[20];
	A[20] = A[ 2];
	A[ 2] = A[12];
	A[12] = A[13];
	A[13] = A[19];
	A[19] = A[23];
	A[23] = A[15];
	A[15] = A[ 4];
	A[ 4] = A[24];
	A[24] = A[21];
	A[21] = A[ 8];
	A[ 8] = A[16];
	A[16] = A[ 5];
	A[ 5] = A[ 3];
	A[ 3] = A[18];
	A[18] = A[17];
	A[17] = A[11];
	A[11] = A[ 7];
	A[ 7] = A[10];
	A[10] = A1;
	/* note: A[ 0] is left as is */
}
static void keccak_pi32(void *state){
	uint32_t A1;
        uint32_t *A = (uint32_t *) state;
        //1-6-9-22-14-20-2-12-13-19-23-15-4-24-21-8-16-5-3-18-17-11-7-10-1*
	A1    = A[ 1];
	A[ 1] = A[ 6];
	A[ 6] = A[ 9];
	A[ 9] = A[22];
	A[22] = A[14];
	A[14] = A[20];
	A[20] = A[ 2];
	A[ 2] = A[12];
	A[12] = A[13];
	A[13] = A[19];
	A[19] = A[23];
	A[23] = A[15];
	A[15] = A[ 4];
	A[ 4] = A[24];
	A[24] = A[21];
	A[21] = A[ 8];
	A[ 8] = A[16];
	A[16] = A[ 5];
	A[ 5] = A[ 3];
	A[ 3] = A[18];
	A[18] = A[17];
	A[17] = A[11];
	A[11] = A[ 7];
	A[ 7] = A[10];
	A[10] = A1;
	/* note: A[ 0] is left as is */
}
static void keccak_pi64(void *state){
	uint64_t A1;
        uint64_t *A = (uint64_t *) state;
        //1-6-9-22-14-20-2-12-13-19-23-15-4-24-21-8-16-5-3-18-17-11-7-10-1*
	A1    = A[ 1];
	A[ 1] = A[ 6];
	A[ 6] = A[ 9];
	A[ 9] = A[22];
	A[22] = A[14];
	A[14] = A[20];
	A[20] = A[ 2];
	A[ 2] = A[12];
	A[12] = A[13];
	A[13] = A[19];
	A[19] = A[23];
	A[23] = A[15];
	A[15] = A[ 4];
	A[ 4] = A[24];
	A[24] = A[21];
	A[21] = A[ 8];
	A[ 8] = A[16];
	A[16] = A[ 5];
	A[ 5] = A[ 3];
	A[ 3] = A[18];
	A[18] = A[17];
	A[17] = A[11];
	A[11] = A[ 7];
	A[ 7] = A[10];
	A[10] = A1;
	/* note: A[ 0] is left as is */
}



/* Keccak chi() transformation */
static void keccak_chi(uint64_t *A)
{
	int i;
	for (i = 0; i < 25; i += 5) {
		uint64_t A0 = A[0 + i], A1 = A[1 + i];
		A[0 + i] ^= ~A1 & A[2 + i];
		A[1 + i] ^= ~A[2 + i] & A[3 + i];
		A[2 + i] ^= ~A[3 + i] & A[4 + i];
		A[3 + i] ^= ~A[4 + i] & A0;
		A[4 + i] ^= ~A0 & A1;
	}
}

static void rhash_sha3_permutation(uint64_t *state)
{
	int round;
	for (round = 0; round < NumberOfRounds; round++)
	{
		//keccak_theta(state);
		/* apply Keccak rho() transformation */
		state[ 1] = ROTL64(state[ 1],  1);
		state[ 2] = ROTL64(state[ 2], 62);
		state[ 3] = ROTL64(state[ 3], 28);
		state[ 4] = ROTL64(state[ 4], 27);
		state[ 5] = ROTL64(state[ 5], 36);
		state[ 6] = ROTL64(state[ 6], 44);
		state[ 7] = ROTL64(state[ 7],  6);
		state[ 8] = ROTL64(state[ 8], 55);
		state[ 9] = ROTL64(state[ 9], 20);
		state[10] = ROTL64(state[10],  3);
		state[11] = ROTL64(state[11], 10);
		state[12] = ROTL64(state[12], 43);
		state[13] = ROTL64(state[13], 25);
		state[14] = ROTL64(state[14], 39);
		state[15] = ROTL64(state[15], 41);
		state[16] = ROTL64(state[16], 45);
		state[17] = ROTL64(state[17], 15);
		state[18] = ROTL64(state[18], 21);
		state[19] = ROTL64(state[19],  8);
		state[20] = ROTL64(state[20], 18);
		state[21] = ROTL64(state[21],  2);
		state[22] = ROTL64(state[22], 61);
		state[23] = ROTL64(state[23], 56);
		state[24] = ROTL64(state[24], 14);
		
		keccak_pi(state);
		keccak_chi(state);

		/* apply iota(state, round) */
		*state ^= keccak_round_constants[round];
	}
}

/**
 * The core transformation. Process the specified block of data.
 *
 * @param hash the algorithm state
 * @param block the message block to process
 * @param block_size the size of the processed block in bytes
 */
static void rhash_sha3_process_block(uint64_t hash[25], const uint64_t *block, size_t block_size)
{
	/* expanded loop */
	hash[ 0] ^= le2me_64(block[ 0]);
	hash[ 1] ^= le2me_64(block[ 1]);
	hash[ 2] ^= le2me_64(block[ 2]);
	hash[ 3] ^= le2me_64(block[ 3]);
	hash[ 4] ^= le2me_64(block[ 4]);
	hash[ 5] ^= le2me_64(block[ 5]);
	hash[ 6] ^= le2me_64(block[ 6]);
	hash[ 7] ^= le2me_64(block[ 7]);
	hash[ 8] ^= le2me_64(block[ 8]);
	/* if not sha3-512 */
	if (block_size > 72) {
		hash[ 9] ^= le2me_64(block[ 9]);
		hash[10] ^= le2me_64(block[10]);
		hash[11] ^= le2me_64(block[11]);
		hash[12] ^= le2me_64(block[12]);
		/* if not sha3-384 */
		if (block_size > 104) {
			hash[13] ^= le2me_64(block[13]);
			hash[14] ^= le2me_64(block[14]);
			hash[15] ^= le2me_64(block[15]);
			hash[16] ^= le2me_64(block[16]);
			/* if not sha3-256 */
			if (block_size > 136) {
				hash[17] ^= le2me_64(block[17]);
#ifdef FULL_SHA3_FAMILY_SUPPORT
				/* if not sha3-224 */
				if (block_size > 144) {
					hash[18] ^= le2me_64(block[18]);
					hash[19] ^= le2me_64(block[19]);
					hash[20] ^= le2me_64(block[20]);
					hash[21] ^= le2me_64(block[21]);
					hash[22] ^= le2me_64(block[22]);
					hash[23] ^= le2me_64(block[23]);
					hash[24] ^= le2me_64(block[24]);
				}
#endif
			}
		}
	}
	/* make a permutation of the hash */
	rhash_sha3_permutation(hash);
}

#define SHA3_FINALIZED 0x80000000

/**
 * Calculate message hash.
 * Can be called repeatedly with chunks of the message to be hashed.
 *
 * @param ctx the algorithm context containing current hashing state
 * @param msg message chunk
 * @param size length of the message chunk
 */
#endif