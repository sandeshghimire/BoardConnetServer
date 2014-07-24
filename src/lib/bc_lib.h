#ifndef BC_LIB_H
#define BC_LIB_H

#include "../include/bc_types.h"

int bc_set_param(uint16_t pid, uint16_t ind1, uint16_t ind2, uint16_t ind3, char* val, uint8_t* status);
int bc_get_param(uint16_t pid, uint16_t ind1, uint16_t ind2, uint16_t ind3, char* val, uint8_t* status);
int bc_test_param(uint16_t pid, uint16_t ind1, uint16_t ind2, uint16_t ind3, char* val, uint8_t* status);
int bc_get_param_name(uint16_t pid, uint16_t *flag, char* name);



#endif /*end of BC_LIB_H*/
