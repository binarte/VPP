/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClassMethod.h
 * Author: vanduir
 *
 * Created on 27 de dezembro de 2018, 13:48
 */

#ifndef CLASSMETHOD_H
#define CLASSMETHOD_H

#include "ClassDefinition.h"

#ifdef __cplusplus
extern "C" {
#endif

	struct __VPP__ClassDef;
	struct __VPP__MethodDef;
	struct __VPP__MethodCall;
	struct __VPP__Instruction;
	struct __VPP__Parameter;
	struct __VPP__Variable;
	struct __VPP__VarDef;
	
#define VPP_MethodParams \
			struct __VPP__ClassInstance* This,\
			struct __VPP__Parameter* params\

	typedef void (*VPP_NativeFunction)(VPP_MethodParams);
	
#define VPP_DeclareNative(METHOD) void METHOD (VPP_MethodParams)

	typedef struct __VPP__MethodDef {
		VPP_defflags flags;
		VPP_datatype returnType;
		VPP_DataOptions options;

		struct __VPP__VarDef* parameters;
		VPP_byte parameterCount;

		VPP_bool isNative;

		union {
			struct __VPP__Instruction* instructions;
			VPP_NativeFunction* function;
		} contents;
		VPP_naturalshort instructionCount;

	} VPP_Method;

	typedef struct __VPP__MethodCall {
		int lol;
	} VPP_MethodCall;

	typedef struct __VPP__Parameter {
	} VPP_Parameter;

	typedef struct __VPP__Variable {
	} VPP_Variable;


	/**
	 * Calls a method
	 * @param method     pointer to the method
	 * @param This       object to call the method from. Should be NULL if the method is static.
	 * @param parameters array of parameters. Should be NULL if there are no parameters
	 * @param parameterCount parameter count
	 * @param out        variable to return the output to. 
	 */
	void VPP_methodCall(
			const struct __VPP__MethodDef * method,
			struct __VPP__ClassInstance* This,
			struct __VPP__Parameter* parameters,
			VPP_byte parameterCount,
			struct __VPP__Variable* out	
			);


	void VPP_freeMethod(struct __VPP__Method* ns);

#ifdef __cplusplus
}
#endif

#endif /* CLASSMETHOD_H */

