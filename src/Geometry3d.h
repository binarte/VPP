/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Geometry3d.h
 * Author: vanduir
 *
 * Created on 19 de dezembro de 2018, 08:22
 */

#ifndef GEOMETRY3D_H
#define GEOMETRY3D_H

#ifdef __cplusplus
extern "C" {
#endif

	
	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real z;
	} VPP_Point3d;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real z;
		VPP_real xofs;
		VPP_real yofs;
		VPP_real zofs;
	} VPP_LineSegment3d;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real z;
		VPP_real width;
		VPP_real height;
		VPP_real depth;
	} VPP_Box;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real z;
		VPP_real r;
	} VPP_Sphere;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real z;
		VPP_real xofs1;
		VPP_real yofs1;
		VPP_real zofs1;
		VPP_real xofs2;
		VPP_real yofs2;
		VPP_real zofs2;
	} VPP_Triangle3d;


#ifdef __cplusplus
}
#endif

#endif /* GEOMETRY3D_H */

