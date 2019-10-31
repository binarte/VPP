/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Complex.h
 * Author: jack
 *
 * Created on 9 de dezembro de 2018, 14:29
 */

#ifndef COMPLEX_H
#define COMPLEX_H

#include "types.h"
#include "Angle.h"


#ifdef __cplusplus
extern "C" {
#endif

    typedef struct {
        VPP_real r;
        VPP_real i;
    } VPP_Complex;

    typedef struct {
        VPP_real r;
        VPP_angle a;
    } VPP_ComplexPolar;

    void VPP_Complex_init(VPP_Complex* This);
    void VPP_Complex_set(VPP_Complex* This, VPP_real r, VPP_real i);
    void VPP_Complex_toPolar(const VPP_Complex* This, VPP_ComplexPolar* out);
 
    void VPP_Complex_conjugate(const VPP_Complex* This, VPP_Complex* out);

    void VPP_Complex_add(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out);
    void VPP_Complex_subtract(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out);
    void VPP_Complex_multiply(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out);
    void VPP_Complex_divide(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out);

    void VPP_Complex_addTo(VPP_Complex* This, const VPP_Complex* n2);
    void VPP_Complex_subtractTo(VPP_Complex* This, const VPP_Complex* n2);
    void VPP_Complex_multiplyTo(VPP_Complex* This, const VPP_Complex* n2);
    void VPP_Complex_divideTo(VPP_Complex* This, const VPP_Complex* n2);
 
    void VPP_Complex_toString(const VPP_Complex* This, char * out);
     
    void VPP_ComplexPolar_init(VPP_ComplexPolar* This);
    void VPP_ComplexPolar_set(VPP_ComplexPolar* This, VPP_real r, VPP_angle a);
    void VPP_ComplexPolar_toRectangular(const VPP_ComplexPolar* This, VPP_Complex* out);

    void VPP_ComplexPolar_toString(const VPP_ComplexPolar* This, char * out);
 
    
#ifdef __cplusplus
}
#endif

#endif /* COMPLEX_H */

