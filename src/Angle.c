/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Angle.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

VPP_real* __VPP__tangentValues;
VPP_range * __VPP__sinValues;

const float __VPP__convRadians = (float) (32768.0 / 3.14159265358979323846);
const float __VPP__convDegrees = (float) (65536.0 / 360.0);
const float __VPP__PI2 = 6.2831853071796f;

void VPP_angleinit() {
    __VPP__tangentValues = (VPP_real*) malloc(sizeof (VPP_real) * 0x10000);
    __VPP__sinValues = (VPP_range*) malloc(sizeof (VPP_range) * 0x10000);

    for (int i = 0; i < 0x10000; i++) {
        float angle = i / __VPP__convRadians;
        //__VPP__tangentValues[i] = tan(angle);
        //__VPP__sinValues[i] = VPP_range_fromReal(sin(angle));
        //printf("%0.4f\t", VPP_range_toReal(__VPP__sinValues[i]));
    }
}

void VPP_anglecleanup() {
    free(__VPP__tangentValues);
    free(__VPP__sinValues);
}

VPP_range VPP_sin(VPP_angle a) {
    return __VPP__sinValues[a];
}

VPP_range VPP_cos(VPP_angle a) {
    return __VPP__sinValues[ (a + 0x4000) % 0x10000];
}

VPP_real VPP_tan(VPP_angle a) {
    return __VPP__tangentValues[a];
}


VPP_angle VPP_asin(VPP_range a) {
   // return VPP_angleFromRadians(asin(VPP_range_toReal(a)));
}

VPP_angle VPP_acos(VPP_range a) {
    //return VPP_angleFromRadians(acos(VPP_range_toReal(a)));
}

VPP_angle VPP_atan(VPP_real a) {
   // return VPP_angleFromRadians(atan(a));
}


void VPP_angleForward(VPP_angle a, VPP_Range2d* out) {
    out->x = VPP_cos(a);
    out->y = VPP_sin(a);
}

VPP_angle VPP_angleFromDegrees(VPP_real degrees) {
    //return (VPP_angle) round(degrees * __VPP__convDegrees);
}

VPP_real VPP_angleToDegrees(VPP_angle a) {
    return (VPP_real) (a / __VPP__convDegrees);
}


VPP_angle VPP_angleFromRadians(VPP_real degrees) {
   // degrees = fmod(degrees, __VPP__PI2);
    if (degrees < 0){
        degrees += __VPP__PI2;
    }
    //return (VPP_angle) round(degrees * __VPP__convRadians);
}

VPP_real VPP_angleToRadians(VPP_angle a) {
    return (VPP_real) (a / __VPP__convRadians);
}


void VPP_angleToString(VPP_angle a, char* out){
    VPP_real dg = VPP_angleToDegrees(a);
    if (dg < 10.0f){
        out[0] = out[1] = ' ';
        out += 2;
    } else if (dg < 100.0f){
        out[0] = ' ';
        out += 1;
    } 
    sprintf(out, "%0.2f°", dg);
}


