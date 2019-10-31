/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ClassDefinition.h
 * Author: jack
 *
 * Created on 12 de dezembro de 2018, 13:08
 */

#ifndef CLASSDEFINITION_H
#define CLASSDEFINITION_H

#include "types.h"
#include "Complex.h"
#include "Datetime.h"

#ifdef __cplusplus
extern "C" {
#endif
	
	struct __VPP__MethodDef;
	struct __VPP__MethodCall;
	struct __VPP__ClassInstance;

	typedef enum {
		VPP_DF_static = 0x1,
		VPP_DF_const = 0x2,
		VPP_DF_abstract = 0x4,
		VPP_DF_final = 0x8,
		VPP_DF_loop = 0x10,
		VPP_DF_private = 0x20,
		VPP_DF_protected = 0x40
	} VPP_defflags;

	typedef enum {
		VPP_VO_none,
		VPP_VO_set,
		VPP_VO_add,
		VPP_VO_subtract,
		VPP_VO_multiply,
		VPP_VO_divide,
		VPP_VO_pow
	} VPP_varOperation;

	typedef enum {
		VPP_OG_none,
		VPP_OG_add,
		VPP_OG_multiply,
		VPP_OG_pow,
		VPP_OG_equals,
		VPP_OG_xor,
		VPP_OG_greater,
		VPP_OG_lesser,
	} VPP_operationType;

	typedef enum {
		VPP_VT_constant,
		VPP_VT_variable,
		VPP_VT_return
	} VPP_valueType;

	struct __VPP__ClassDef;
	struct __VPP__Namespace;
	struct __VPP__LanguageObject;
	struct __VPP__Operation;
	struct __VPP__OperationComponent;
	struct __VPP__Value;

	typedef union {
		struct __VPP__ClassDef* classDef;

		struct {
			VPP_integerlong min;
			VPP_integerlong max;
		} integer;

		struct {
			VPP_naturallong min;
			VPP_naturallong max;
		} natural;

		struct {
			VPP_real min;
			VPP_real max;
		} real;
	} VPP_DataOptions;

	typedef struct __VPP__Value {
		VPP_valueType type;
		VPP_defflags flags;
		VPP_datatype datatype;
		struct __VPP__ClassDef* classDef;
		union {			
			VPP_integer integer;
			VPP_integerlong integerL;
			VPP_integershort integerS;
			VPP_natural natural;
			VPP_naturallong naturalL;
			VPP_naturalshort naturalS;
			VPP_sign sign;
			VPP_bool boolean;
			VPP_real real;
			VPP_angle angle;
			VPP_fraction fraction;
			VPP_range range;
			void* structValue;
		} value;
	} VPP_Value;

	typedef struct __VPP__OperationComponent {
		VPP_bool invert;
		struct __VPP__Value value;
	} VPP_OperationComponent;

	typedef struct __VPP__Operation {
		VPP_operationType type;
		VPP_OperationComponent* components;
		VPP_byte componentCount;
	} VPP_Operation;

	typedef struct __VPP__LanguageObject {
		VPP_bool isClass;
		struct __VPP__Namespace* ns;

		union {
			struct __VPP__Namespace* _namespace;
			struct __VPP__ClassDef* _class;
		} data;
		char * name;
		VPP_byte nameLength;
		struct __VPP__LanguageObject* next;
		struct __VPP__LanguageObject* prev;
	} VPP_LanguageObject;

	typedef struct __VPP__Namespace {
		struct __VPP__Namespace* parent;
		struct __VPP__LanguageObject* first;
		struct __VPP__LanguageObject* last;
	} VPP_Namespace;


	typedef struct __VPP__VarDef {
		VPP_datatype type;

		VPP_defflags flags;
		VPP_DataOptions options;
		char* name;
		VPP_byte nameLength;
	} VPP_VarRef;

	typedef struct __VPP__Instruction {
	} VPP_Instruction;

	typedef struct __VPP__ClassDef {
		struct __VPP__Namespace* parent;
		struct __VPP__ClassDef* inheritance;
		VPP_defflags flags;

		VPP_byte varCount;
		VPP_VarRef* vars;

		VPP_byte methodCount;
		struct __VPP__Method* methods;
	} VPP_Class;
	
	typedef struct __VPP__ClassInstance {
		
	} VPP_ClassInstance;

	void VPP_freeNamespace(VPP_Namespace* ns);
	void VPP_freeInstruction(VPP_Instruction* ns);
	void VPP_freeVariable(VPP_VarRef* ns);
	void VPP_freeClass(VPP_Class* ns);

	void VPP_initNamespace();
	void VPP_closeNamespace();
	/**
	 * Gets a namespace 
	 * @param ns name of the namespace to get
	 * @param parent 
	 * @return 
	 */
	VPP_Namespace* VPP_getNamespace(char * ns, VPP_Namespace* parent);

#ifdef __cplusplus
}
#endif

#endif /* CLASSDEFINITION_H */

