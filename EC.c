#include "EC.h"

int ec_curve_init(ec_curve_t *curve){
  if(uintx_cmp(curve->m, curve->a) <= 0)
    return EC_code_invalid_a_parameter;
  return 1;
}
int ec_curve_set_base(ec_curve_t *curve, ec_point_t *base){
  return 1;
}

int ec_point_set(uintx_t x, uintx_t y){
  
  return 1;
}
int ec_point_set_in_basis(uintx_t m, uintx_t y, ec_basis_t basis, ...){
  volatile va_list var;
  
  return 1;
}
int ec_point_add(ec_point_t *a, ec_point_t *b){
  return 1;
}