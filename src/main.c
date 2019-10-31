/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vanduir
 *
 * Created on 5 de Dezembro de 2018, 16:40
 */

#include <stdio.h>
#include <stdlib.h>
#include "Datetime.h"
#include "Angle.h"
#include "Complex.h"
#include <string.h>

#include "ClassDefinition.h"
#include "ClassMethod.h"

#include "MathExpression.h"
#include "Struct.h"

VPP_DeclareNative(helloWorld) {
	printf("Hello World!\n");
}

/*
 * 
 */
int main(int argc, char** argv) {
	VPP_StructInit();
	
	VPP_Struct* str = VPP_Struct_new(NULL);
	printf("Id1 é %i\n",str->container->index);
	VPP_Struct_addDict(str,"en:HelloWorld");

	str = VPP_Struct_new(NULL);
	printf("Id2 é %i\n",str->container->index);
	VPP_Struct_addDict(str,"en:FooBar");
	
str = VPP_Struct_get(NULL,"en:HelloWorld")->content.structt;
printf("Id3 é %i\n",str->container->index);

	VPP_StructCleanup();
    return (EXIT_SUCCESS);
}

