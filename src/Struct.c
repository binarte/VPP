#include "Struct.h"
#include <stddef.h>

VPP_Struct __VPP_RootStruct;

#define STRBUFSIZE 256
#define DICTBUFSIZE 16


void __VPP__Struct_init(VPP_Struct* This){
	This->inherits = NULL;

	This->items = (VPP_Struct*) malloc(
			sizeof(VPP_Struct) * STRBUFSIZE);
	This->itemCount = 0;
	This->itemBufferSize = STRBUFSIZE;

	This->dictionary = (VPP_DictionaryEntry*) malloc(
			sizeof(VPP_DictionaryEntry) * DICTBUFSIZE);
	This->dictionaryBufferSize = DICTBUFSIZE;
	This->dictionarySize = 0;
}
void __VPP_StructItem_free(VPP_StructItem* This){
	VPP_itemIndex i;
	VPP_Struct* stru;
	switch (This->type){
		case VPP_SIT_Struct:
			stru = This->content.structt;
			for (i = 0; i < stru->itemCount; i++){
				__VPP_StructItem_free(&stru->items[i]);
			}
			for (i = 0; i < stru->dictionarySize; i++){
				free(stru->dictionary[i].name);
			}
			free(stru->dictionary);
			free(stru->items);
			break;
	}
}

void VPP_StructInit() {
	__VPP_RootStruct.container = NULL;
	__VPP__Struct_init(&__VPP_RootStruct);
}
void VPP_StructCleanup() {

}

VPP_StructItem* VPP_Struct_add(VPP_Struct* This) {
	if (This->itemCount >= This->itemBufferSize) {
		VPP_Struct* oldBuf = This->items;
		VPP_itemIndex oldSize = This->itemBufferSize;
		This->itemBufferSize += STRBUFSIZE;
		This->items = (VPP_Struct*) malloc(
				sizeof(VPP_Struct) * This->itemBufferSize);

		memcpy(This->items, oldBuf, sizeof(VPP_Struct) * oldSize);
		free(oldBuf);
	}
	VPP_StructItem* out = &This->items[This->itemCount];
	out->index = This->itemCount;
	out->parent = This;
	out->type = 0;
	out->content.ptr = 0;
	This->itemCount++;
	return out;
}

VPP_Struct* VPP_Struct_new(VPP_Struct* parent) {
	VPP_Struct* out = (VPP_Struct*) malloc(sizeof(VPP_Struct));
	VPP_StructItem* it;
	if (parent == NULL){
		it = VPP_Struct_add(&__VPP_RootStruct);
	} else {
		it = VPP_Struct_add(parent);
	}
	it->content.structt = out;
	it->type = VPP_SIT_Struct;
	out->container = it;
	__VPP__Struct_init(out);

	return out;
}

void VPP_Struct_addDict(VPP_Struct* This, const char* name){
	VPP_Struct* parent = This->container->parent;
	VPP_itemIndex idx = This->container->index;

	if (parent->dictionarySize >= parent->dictionaryBufferSize) {
		VPP_DictionaryEntry* oldBuf = parent->dictionary;
		VPP_itemIndex oldSize = parent->dictionaryBufferSize;
		parent->dictionaryBufferSize += STRBUFSIZE;
		parent->dictionary = (VPP_DictionaryEntry*) malloc(
				sizeof(VPP_DictionaryEntry) * parent->itemBufferSize);

		memcpy(parent->dictionary, oldBuf, sizeof(VPP_DictionaryEntry) * oldSize);
		free(oldBuf);
	}
	if (This->dictionarySize >= This->dictionaryBufferSize) {
		VPP_DictionaryEntry* oldBuf = This->dictionary;
		VPP_sdictEntryIndex oldSize = This->dictionaryBufferSize;
		This->dictionaryBufferSize += DICTBUFSIZE;
		This->dictionary = (VPP_DictionaryEntry*) malloc(
				sizeof(VPP_DictionaryEntry) * This->itemBufferSize);

		memcpy(This->dictionary, oldBuf, sizeof(VPP_DictionaryEntry) * oldSize);
		free(oldBuf);
	}


	parent->dictionary[parent->dictionarySize].name = (char*) malloc(sizeof(char) * (strlen(name) + 1) );
	parent->dictionary[parent->dictionarySize].index = idx;

	strcpy(parent->dictionary[parent->dictionarySize].name, name);
	parent->dictionarySize++;
}

VPP_StructItem* VPP_Struct_get(VPP_Struct* This, const char* name){
	if (This == NULL){
		This = &__VPP_RootStruct;
	}

	for (VPP_itemIndex i; i < This->itemCount; i++){
		if(strcmp(name, This->dictionary[i].name) == 0){
			return &This->items[This->dictionary[i].index];
		}
	}
	return NULL;
}
