/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ClassDefinition.h"
#include "ClassMethod.h"
#include <string.h>
#include <stdlib.h>
//#include <bsd/string.h>
#include <stdio.h>

struct __VPP__Namespace __VPP__MainNamespace;

void VPP_initNamespace() {
	__VPP__MainNamespace.first = NULL;
	__VPP__MainNamespace.last = NULL;
	__VPP__MainNamespace.parent = NULL;
}

VPP_Namespace* VPP_getNamespace(char* ns, VPP_Namespace* parent) {
	if (parent == NULL) {
		parent = &__VPP__MainNamespace;
	}

	VPP_LanguageObject* cur = parent->first;
	while (cur != NULL) {
		if (strcmp(ns, cur->name) == 0) {
			if (cur->isClass) {
				return NULL;
			}
			return cur->data._namespace;
		}

		cur = cur->next;
	}

	cur = malloc(sizeof (VPP_LanguageObject));
	cur->isClass = VPP_false;
	cur->nameLength = (VPP_byte) strlen(ns);
	cur->name = malloc(sizeof (char) * (cur->nameLength + 1));
	cur->name[cur->nameLength] = 0;
	strcpy(cur->name, ns);
	cur->next = NULL;

	cur->data._namespace = malloc(sizeof (VPP_Namespace));
	cur->data._namespace->last = NULL;
	cur->data._namespace->first = NULL;
	cur->data._namespace->parent = NULL;

	if (parent->first == NULL) {
		parent->first = parent->last = cur;
		cur->prev = NULL;
	} else {
		cur->prev = parent->last;
		parent->last->next = cur;
		parent->last = cur;
	}

	return cur->data._namespace;
}

void __VPP__freeNsInner__(VPP_Namespace* ns) {
	VPP_LanguageObject* cur = ns->first;
	while (cur != NULL) {
		VPP_LanguageObject* del = cur;
		cur = cur->next;

		if (del->isClass) {

		} else {
			VPP_freeNamespace(del->data._namespace);
		}
		free(del);
	}
}

void __VPP__freeVarInner__(VPP_Variable* ns) {
	//free(ns->name);
}

void __VPP__freeInstInner__(VPP_Instruction* ns) {
}

void __VPP__freeMethodInner__(VPP_Method* ns) {
	int i;
	for (i = 0; i < ns->parameterCount; i++) {
		__VPP__freeVarInner__(&ns->parameters[i]);
	}
	for (i = 0; i < ns->instructionCount; i++) {
		//__VPP__freeInstInner__(&ns->instructions[i]);
	}
}

void VPP_closeNamespace() {
	__VPP__freeNsInner__(&__VPP__MainNamespace);
}

void VPP_freeNamespace(VPP_Namespace* ns) {
	__VPP__freeNsInner__(ns);
	free(ns);
}
/*
void VPP_freeVariable(VPP_VarRef* ns) {
	//__VPP__freeVarInner__(ns);
	//free(ns);
}*/

void VPP_freeInstruction(VPP_Instruction* ns) {
	__VPP__freeInstInner__(ns);
	free(ns);
}

void VPP_freeMethod(struct __VPP__Method* ns) {
	__VPP__freeMethodInner__(ns);
	free(ns);
}
