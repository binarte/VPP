/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>

#include "MathExpression.h"

VPP_MathExpression* VPP_MathExpression_prepare(VPP_byte componentCount, VPP_bool isMultiply, VPP_datatype type) {
	VPP_MathExpression* out = (VPP_MathExpression*) malloc(sizeof (VPP_MathExpression));
	out->componentCount = componentCount;
	out->type = type;

	if (componentCount == 0) {
		out->components = NULL;
	}

	out->components = (VPP_MathValue*) malloc(sizeof (VPP_MathValue) * componentCount);

	for (VPP_byte i = 0; i < componentCount; i++) {
		out->components[i].sign = VPP_nosign;
		out->components[i].data.ilong = 0;
	}

	return out;
}

void VPP_MathExpression_free(VPP_MathExpression* exp) {
	if (exp->components != NULL) {
		free(exp->components);
	}
	free(exp);
}

VPP_MathValue __VPP_MathExpression_run_add__(const VPP_MathExpression* exp) {
	VPP_MathValue out;
	switch (exp->type) {
		case VPP_DT_integershort:
			out.ishort = 0;
			break;
		case VPP_DT_integer:
			out.imedium = 0;
			break;
		case VPP_DT_integerlong:
			out.ilong = 0;
			break;
		case VPP_DT_naturalshort:
			out.nshort = 0;
			break;
		case VPP_DT_natural:
			out.nmedium = 0;
			break;
		case VPP_DT_naturallong:
			out.nlong = 0;
			break;
		case VPP_DT_real:
			out.real = 0;
			break;
		case VPP_DT_realdouble:
			out.realdouble = 0;
			break;
	}
	for (VPP_byte i; i < exp->componentCount; i++) {
		switch (exp->components[i].sign) {
			case VPP_positive:
				switch (exp->type){
					case VPP_DT_integer:
						out.imedium += exp->components[i].data.imedium;
						break;
					case VPP_DT_integerlong:
						out.ilong += exp->components[i].data.ilong;
						break;
					case VPP_DT_integershort:
						out.ishort += exp->components[i].data.ishort;
						break;
					case VPP_DT_natural:
						out.nmedium += exp->components[i].data.nmedium;
						break;
					case VPP_DT_naturallong:
						out.nlong += exp->components[i].data.nlong;
						break;
					case VPP_DT_naturalshort:
						out.nshort += exp->components[i].data.nshort;
						break;
					case VPP_DT_real:
						out.real += exp->components[i].data.real;
						break;
					case VPP_DT_realdouble:
						out.realdouble += exp->components[i].data.realdouble;
						break;
				}
				break;
			case VPP_negative:
				switch (exp->type){
					case VPP_DT_integer:
						out.imedium -= exp->components[i].data.imedium;
						break;
					case VPP_DT_integerlong:
						out.ilong -= exp->components[i].data.ilong;
						break;
					case VPP_DT_integershort:
						out.ishort -= exp->components[i].data.ishort;
						break;
					case VPP_DT_natural:
						out.nmedium -= exp->components[i].data.nmedium;
						break;
					case VPP_DT_naturallong:
						out.nlong -= exp->components[i].data.nlong;
						break;
					case VPP_DT_naturalshort:
						out.nshort -= exp->components[i].data.nshort;
						break;
					case VPP_DT_real:
						out.real -= exp->components[i].data.real;
						break;
					case VPP_DT_realdouble:
						out.realdouble -= exp->components[i].data.realdouble;
						break;
				}
				break;
		}
	}
}

VPP_MathValue __VPP_MathExpression_run_mul__(const VPP_MathExpression* exp) {
	VPP_MathValue out;
	switch (exp->type) {
		case VPP_DT_integershort:
			out.ishort = 0;
			break;
		case VPP_DT_integer:
			out.imedium = 0;
			break;
		case VPP_DT_integerlong:
			out.ilong = 0;
			break;
		case VPP_DT_naturalshort:
			out.nshort = 0;
			break;
		case VPP_DT_natural:
			out.nmedium = 0;
			break;
		case VPP_DT_naturallong:
			out.nlong = 0;
			break;
		case VPP_DT_real:
			out.real = 0;
			break;
		case VPP_DT_realdouble:
			out.realdouble = 0;
			break;
	}
	for (VPP_byte i; i < exp->componentCount; i++) {
		switch (exp->components[i].sign) {
			case VPP_positive:
				switch (exp->type){
					case VPP_DT_integer:
						out.imedium *= exp->components[i].data.imedium;
						break;
					case VPP_DT_integerlong:
						out.ilong *= exp->components[i].data.ilong;
						break;
					case VPP_DT_integershort:
						out.ishort *= exp->components[i].data.ishort;
						break;
					case VPP_DT_natural:
						out.nmedium *= exp->components[i].data.nmedium;
						break;
					case VPP_DT_naturallong:
						out.nlong *= exp->components[i].data.nlong;
						break;
					case VPP_DT_naturalshort:
						out.nshort *= exp->components[i].data.nshort;
						break;
					case VPP_DT_real:
						out.real *= exp->components[i].data.real;
						break;
					case VPP_DT_realdouble:
						out.realdouble *= exp->components[i].data.realdouble;
						break;
				}
				break;
			case VPP_negative:
				switch (exp->type){
					case VPP_DT_integer:
						out.imedium /= exp->components[i].data.imedium;
						break;
					case VPP_DT_integerlong:
						out.ilong /= exp->components[i].data.ilong;
						break;
					case VPP_DT_integershort:
						out.ishort /= exp->components[i].data.ishort;
						break;
					case VPP_DT_natural:
						out.nmedium /= exp->components[i].data.nmedium;
						break;
					case VPP_DT_naturallong:
						out.nlong /= exp->components[i].data.nlong;
						break;
					case VPP_DT_naturalshort:
						out.nshort /= exp->components[i].data.nshort;
						break;
					case VPP_DT_real:
						out.real /= exp->components[i].data.real;
						break;
					case VPP_DT_realdouble:
						out.realdouble /= exp->components[i].data.realdouble;
						break;
				}
				break;
		}
	}
}

VPP_MathValue VPP_MathExpression_run(const VPP_MathExpression* exp) {
	if (exp->isMultiply) {
		return __VPP_MathExpression_run_mul__(exp);
	}
	return __VPP_MathExpression_run_add__(exp);
}