/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vector.h
 * Author: jack
 *
 * Created on 9 de dezembro de 2018, 08:18
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        VPP_real x;
        VPP_real y;
    } VPP_2dVector;

    typedef struct {
        VPP_realdouble x;
        VPP_realdouble y;
    } VPP_2dVectorPrec;
     
    void VPP_2dVector_init(VPP_2dVector * This);
    VPP_real VPP_2dVector_length(const VPP_2dVector * This);

    typedef struct {
        VPP_real x;
        VPP_real y;
        VPP_real z;
    } VPP_3dVector;


#ifdef __cplusplus
}
#endif

#endif /* VECTOR_H */

