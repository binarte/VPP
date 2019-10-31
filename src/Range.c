/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Range.h"
#include <math.h>


VPP_range VPP_range_fromReal(VPP_real r){
    if (r <= -1.0f) {
        return 0x8001;
    }
    if (r >= 1.0f) {
        return 0x7FFF;
    }
    //return (VPP_range) round(r * 32767.0f);
}

VPP_real VPP_range_toReal(VPP_range r) {
    return r / 32767.0f;
}


VPP_fraction VPP_fraction_fromReal(VPP_real r){
    if (r <= 0.0f) {
        return 0;
    }
    if (r >= 1.0f) {
        return 0xffff;
    }
    //return (VPP_fraction) round(r * 65535.0f);
}

VPP_real VPP_fraction_toReal(VPP_fraction r){
    return r / 65535.0f;    
}
