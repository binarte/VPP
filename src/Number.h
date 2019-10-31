/*
 * Number.h
 *
 *  Created on: 28 de out de 2019
 *      Author: jack
 */

#ifndef NUMBER_H_
#define NUMBER_H_

/**
 * Number is unsigned
 */
#define VCC_FL_Unsigned 0x1
/**
 * Number has a minimum and maximum value
 */
#define VCC_FL_MinMax 0x2
/**
 * Number loops around it's minimum and maximum even when minimum and maximum are defined
 */
#define VCC_FL_Loop 0x4
/**
 * Number is bit-shifted
 */
#define VCC_FL_Shift 0x8
/**
 * Number is divided
 */
#define VCC_FL_Divisor 0x18
#define VCC_FL_Multiplier 0x28

typedef struct {
	unsigned char size;
	unsigned char flags;
	signed short shift;
	signed long long int max;
	signed long long int min;
} VCC_NumberTypeDef;

void VCC_NumberAdd(VCC_NumberTypeDef *oType, void *out, VCC_NumberTypeDef *type1, void *data1, VCC_NumberTypeDef *type2,
		void *data2);

#endif /* NUMBER_H_ */
