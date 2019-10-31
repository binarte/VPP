#include "Number.h"

void VCC_NumberAdd(VCC_NumberTypeDef *oType, void *out, VCC_NumberTypeDef *type1, void *data1, VCC_NumberTypeDef *type2,
		void *data2){


	if (type1->flags == type2->flags){
		VCC_ApplyFlagsShort(oType, out, data1 + data2);
	}
}
