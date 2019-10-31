/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Range.h
 * Author: jack
 *
 * Created on 9 de dezembro de 2018, 09:56
 */

#ifndef RANGE_H
#define RANGE_H

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif
    
    typedef signed short VPP_fraction;

    VPP_fraction VPP_fraction_fromReal(VPP_real r);
    VPP_real VPP_fraction_toReal(VPP_fraction r);
    void VPP_fraction_toString(VPP_fraction r, char* out);
    
    typedef signed short VPP_range;

    VPP_range VPP_range_fromReal(VPP_real r);
    VPP_real VPP_range_toReal(VPP_range r);
    void VPP_range_toString(VPP_range r, char* out);

    
    typedef struct  {
        VPP_range x;
        VPP_range y;
    } VPP_Range2d;
    
    void VPP_Range2d_init(VPP_Range2d* This);
    VPP_real VPP_Range2d_length(const VPP_Range2d* This);
    


#ifdef __cplusplus
}
#endif

#endif /* RANGE_H */

