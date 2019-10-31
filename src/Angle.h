/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Angle.h
 * Author: jack
 *
 * Created on 9 de dezembro de 2018, 08:58
 */

#ifndef ANGLE_H
#define ANGLE_H

#include "types.h"
#include "Range.h"

#ifdef __cplusplus
extern "C" {
#endif
    void VPP_angleinit();
    void VPP_anglecleanup();

    typedef unsigned short VPP_angle;
    VPP_range VPP_cos(VPP_angle a);
    VPP_range VPP_sin(VPP_angle a);
    VPP_real VPP_tan(VPP_angle a);

    VPP_angle VPP_acos(VPP_range a);
    VPP_angle VPP_asin(VPP_range a);
    VPP_angle VPP_atan(VPP_real a);

    VPP_angle VPP_angleFromDegrees(VPP_real degrees);
    VPP_real VPP_angleToDegrees(VPP_angle a);
 
    VPP_angle VPP_angleFromRadians(VPP_real degrees);
    VPP_real VPP_angleToRadians(VPP_angle a);
    
    void VPP_angleForward(VPP_angle a, VPP_Range2d* out);

    void VPP_angleToString(VPP_angle a, char* out);

#ifdef __cplusplus
}
#endif

#endif /* ANGLE_H */

