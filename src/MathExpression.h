/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MathExpression.h
 * Author: vanduir
 *
 * Created on 24 de janeiro de 2019, 11:01
 */

#ifndef MATHEXPRESSION_H
#define MATHEXPRESSION_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef union {
		VPP_integershort ishort;
		VPP_integer imedium;
		VPP_integerlong ilong;

		VPP_naturalshort nshort;
		VPP_natural nmedium;
		VPP_naturallong nlong;

		VPP_real real;
		VPP_realdouble realdouble;

	} VPP_MathValue;

	typedef struct {
		VPP_MathValue data;
		VPP_sign sign;
	} VPP_MathVariable;

	typedef struct {
		VPP_bool isMultiply;
		VPP_datatype type;
		VPP_MathVariable* components;
		VPP_byte componentCount;
	} VPP_MathExpression;
	
	VPP_MathValue VPP_MathExpression_run(const VPP_MathExpression* exp);
	VPP_MathExpression* VPP_MathExpression_prepare(VPP_byte componentCount, VPP_bool isMultiply, VPP_datatype type);
	void VPP_MathExpression_free(VPP_MathExpression* exp);

#ifdef __cplusplus
}
#endif

#endif /* MATHEXPRESSION_H */

