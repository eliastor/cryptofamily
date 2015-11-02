#include "stretchint.h"
int uintx_add(uintx_t a, uintx_t b, uintx_t *r){
  if(MAX(a.length, b.length) > r->length+1){
#ifndef __ALLOC_ON
    return uintx_code_invalid_r_length;
#else
    uint32_t *data = realloc(r->data, (MAX(a.length, b.length) + 1) * sizeof(uint32_t));
    if(data == NULL){
      return uintx_code_unable_to_realloc;
    }
#endif
  }
  
  uint32_t *_a;
  uint32_t *_b;
  
  
  
  return 1;
}
int uintx_sub(uintx_t a, uintx_t b, uintx_t *r){ 
  return 1;
}
int uintx_mul(uintx_t a, uintx_t b, uintx_t *r){ 
  return 1;
}
int uintx_mod(uintx_t a, uintx_t m, uintx_t *r){ 
  return 1;
}
int uintx_mulmod(uintx_t a, uintx_t b, uintx_t m, uintx_t *r){ 
  return 1;`
}
int uintx_invmod(uintx_t a, uintx_t m, uintx_t *r){ 
  return 1;
}
int uintx_divmod(uintx_t a, uintx_t b, uintx_t m, uintx_t *remainder, uintx_t *quotient){ 
  return 1;
}
int uintx_revmod(uintx_t a, uintx_t m, uintx_t *r){ 
  return 1;
}
int uintx_cmp(uintx_t a, uintx_t b){
  register size_t i;
  int32_t _a = (int32_t) a.length;
  int32_t _b = (int32_t) b.length;
  int32_t _c = _a - _b;
  
  if(_c != 0){//we should check concatenate zero to the MSB
    uint32_t *c;
    int return_flag;
    register size_t border;
    if(_c>0){
      i = a.length-1;
      border = b.length-1;
      c = a.data;
      return_flag = 1;
    }else{
      i = b.length-1;
      border = a.length-1;
      c = b.data;
      return_flag = -1;
    }
    do{
      if(c[i] > 0UL)
        return return_flag;
    }while( i-- > border);
  }else{
    i = a.length;
  }
  do{
    if(a.data[i] > b.data[i])
      return 1;
    else if(a.data[i] < b.data[i])
      return -1;
  }while(i--);
  return 0;
}
int uintx_ge(uintx_t a, uintx_t b){
  register size_t i;
  int32_t _a = (int32_t) a.length;
  int32_t _b = (int32_t) b.length;
  int32_t _c = _a - _b;
  
  if(_c != 0){//we should check concatenate zero to the MSB
    uint32_t *c;
    int return_flag;
    register size_t border;
    if(_c>0){
      i = a.length-1;
      border = b.length-1;
      c = a.data;
      return_flag = 1;
    }else{
      i = b.length-1;
      border = a.length-1;
      c = b.data;
      return_flag = 0;
    }
    do{
      if(c[i] > 0UL)
        return return_flag;
    }while( i-- > border);
  }else{
    i = a.length;
  }
  do{
    if(a.data[i] > b.data[i])
      return 1;
    else if(a.data[i] < b.data[i])
      return 0;
  }while(i--);
  return 1;
}
int uintx_le(uintx_t a, uintx_t b){
  register size_t i;
  int32_t _a = (int32_t) a.length;
  int32_t _b = (int32_t) b.length;
  int32_t _c = _a - _b;
  
  if(_c != 0){//we should check concatenate zero to the MSB
    uint32_t *c;
    int return_flag;
    register size_t border;
    if(_c>0){
      i = a.length-1;
      border = b.length-1;
      c = a.data;
      return_flag = 0;
    }else{
      i = b.length-1;
      border = a.length-1;
      c = b.data;
      return_flag = 1;
    }
    do{
      if(c[i] > 0UL)
        return return_flag;
    }while( i-- > border);
  }else{
    i = a.length;
  }
  do{
    if(a.data[i] > b.data[i])
      return 0;
    else if(a.data[i] < b.data[i])
      return 1;
  }while(i--);
  return 1;
}
int uintx_eq(uintx_t a, uintx_t b){
  register size_t i;
  int32_t _a = (int32_t) a.length;
  int32_t _b = (int32_t) b.length;
  int32_t _c = _a - _b;
  
  if(_c != 0){//we should check concatenate zero to the MSB
    uint32_t *c;
    int return_flag;
    register size_t border;
    if(_c>0){
      i = a.length-1;
      border = b.length-1;
      c = a.data;
      return_flag = 0;
    }else{
      i = b.length-1;
      border = a.length-1;
      c = b.data;
      return_flag = 0;
    }
    do{
      if(c[i] > 0UL)
        return return_flag;
    }while( i-- > border);
  }else{
    i = a.length;
  }
  do{
    if(a.data[i] > b.data[i])
      return 0;
    else if(a.data[i] < b.data[i])
      return 0;
  }while(i--);
  return 1;
}