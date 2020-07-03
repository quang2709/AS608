#include "xor.h"

u8 XOR_Caculator(uint8_t* data, uint8_t ofset, uint8_t length)
{
    uint8_t retVal = 0;

	for(uint8_t i = ofset; i < length; i++){
		retVal ^= data[i];
	}
	return retVal;
}