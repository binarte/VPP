/*
 * Copyright 2019 Jack Mcslay
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of
 * conditions and the following disclaimer in the documentation and/or other materials provided
 * with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef STRUCT_H_
#define STRUCT_H_

#include "types.h"

struct _VPP_Struct;
struct _VPP_StructItem;
struct _VPP_DictionaryEntry;

typedef enum  {
	VPP_SIT_Struct,
	VPP_SIT_Instance,
	VPP_SIT_String,
} VPP_StructItemType;

typedef struct _VPP_DictionaryEntry {
	VPP_itemIndex index;
	char* name;
} VPP_DictionaryEntry;

typedef struct _VPP_Struct {
	struct _VPP_StructItem* container;
	struct _VPP_Struct* inherits;
	struct _VPP_Struct* items;
	VPP_itemIndex itemCount;
	VPP_itemIndex itemBufferSize;
	VPP_DictionaryEntry* dictionary;
	VPP_dictEntryIndex dictionarySize;
	VPP_dictEntryIndex dictionaryBufferSize;
} VPP_Struct;

/**
 *
 */
typedef struct _VPP_StructItem {
	VPP_StructItemType type;
	VPP_itemIndex index;
	VPP_Struct* parent;

	union {
		VPP_Struct* structt;
		void* ptr;
	} content;
} VPP_StructItem;

VPP_Struct* VPP_Struct_new(VPP_Struct* parent);
void VPP_Struct_addDict(VPP_Struct* This, const char* name);
VPP_StructItem* VPP_Struct_get(VPP_Struct* This, const char* name);


VPP_StructItem* VPP_StructItem_new(VPP_StructItemType type);

void VPP_StructInit();
void VPP_StructCleanup();

#endif /* STRUCT_H_ */
