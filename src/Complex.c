/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Complex.h"
#include <math.h>
#include <stdio.h>

void VPP_Complex_init(VPP_Complex* This) {
    This->i = 0;
    This->r = 0;
}

void VPP_Complex_set(VPP_Complex* This, VPP_real r, VPP_real i) {
    This->i = i;
    This->r = r;
}

void VPP_Complex_toPolar(const VPP_Complex* This, VPP_ComplexPolar* out) {
    if (This->i == 0) {
        if (This->r >= 0) {
            out->a = 0;
            out->r = This->r;
        } else {
            out->a = 0x8000;
            out->r = -This->r;
        }
        return;
    } else if (This->r == 0) {
        if (This->i >= 0) {
            out->a = 0x4000;
            out->r = This->i;
        } else {
            out->a = 0xC000;
            out->r = -This->i;
        }
        return;
    }

   // out->r = sqrt((This->i * This->i) + (This->r * This->r));
    if (This->i > 0) {
        out->a = VPP_acos(VPP_range_fromReal(This->r / out->r));
    } else {
        out->a = VPP_asin(VPP_range_fromReal(This->r / out->r)) + 0xC000;
    }
}

void VPP_Complex_conjugate(const VPP_Complex* This, VPP_Complex* out) {
    out->r = This->r;
    out->i = -This->i;
}

void VPP_Complex_add(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out) {
    out->r = n1->r + n2->r;
    out->i = n1->i + n2->i;
}

void VPP_Complex_subtract(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out) {
    out->r = n1->r - n2->r;
    out->i = n1->i - n2->i;
}

void VPP_Complex_multiply(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out) {
    out->r = (n1->r * n2->r) - (n1->i * n2->i);
    out->i = (n1->r * n2->i) + (n1->i * n2->r);
}

void VPP_Complex_divide(const VPP_Complex* n1, const VPP_Complex* n2, VPP_Complex* out) {
    VPP_real div = (n2->r * n2->r) + (n2->i * n2->i);
    out->r = ((n1->r * n2->r) + (n1->i * n2->i)) / div;
    out->i = ((n1->i * n2->r) - (n1->r * n2->i)) / div;
}

void VPP_Complex_addTo(VPP_Complex* This, const VPP_Complex* n2) {
    This->r += n2->r;
    This->i += n2->i;
}

void VPP_Complex_subtractTo(VPP_Complex* This, const VPP_Complex* n2) {
    This->r -= n2->r;
    This->i -= n2->i;
}

void VPP_Complex_multiplyTo(VPP_Complex* This, const VPP_Complex* n2) {
    VPP_real r = This->r, i = This->i;
    This->r = (r * n2->r) - (i * n2->i);
    This->i = (r * n2->i) + (i * n2->r);
}

void VPP_Complex_divideTo(VPP_Complex* This, const VPP_Complex* n2) {
    VPP_real div = (n2->r * n2->r) + (n2->i * n2->i), r = This->r, i = This->i;
    This->r = ((r * n2->r) + (i * n2->i)) / div;
    This->i = ((i * n2->r) - (r * n2->i)) / div;
}

void VPP_ComplexPolar_toRectangular(const VPP_ComplexPolar* This, VPP_Complex* out) {
    out->r = VPP_range_toReal(VPP_cos(This->a)) * This->r;
    out->i = VPP_range_toReal(VPP_sin(This->a)) * This->r;

    //out->r = VPP_range_toReal(VPP_sin(This->a));
    //out->i = This->a;
}
//ρφ

void VPP_ComplexPolar_toString(const VPP_ComplexPolar* This, char * out) {
    sprintf(out, "(ρ%0.3e φ%0.2f°)", This->r, VPP_angleToDegrees(This->a));
}

void VPP_Complex_toString(const VPP_Complex* This, char * out) {
    if (This->i >= 0) {
        sprintf(out, "(%0.3e +%0.3ei)", This->r, This->i);
    } else {
        sprintf(out, "(%0.3e %0.3ei)", This->r, This->i);
    }
}
