/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Geometry2d.h
 * Author: vanduir
 *
 * Created on 11 de dezembro de 2018, 11:25
 */

#ifndef GEOMETRY2D_H
#define GEOMETRY2D_H

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif

	//primitives

	typedef struct {
		VPP_real x;
		VPP_real y;
	} VPP_Point;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real xofs;
		VPP_real yofs;
	} VPP_LineSegment;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real xofs;
	} VPP_LineSegmentHorizontal;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real yofs;
	} VPP_LineSegmentVertical;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real width;
		VPP_real height;
	} VPP_Rectangle;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real r;
	} VPP_Circle;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real xofs;
		VPP_real yofs;
	} VPP_Slope;

	typedef struct {
		VPP_real x;
		VPP_real y;
		VPP_real xofs1;
		VPP_real yofs1;
		VPP_real xofs2;
		VPP_real yofs2;
	} VPP_Triangle;

	void VPP_Point_init(VPP_Point* This);
	void VPP_Point_set(VPP_Point* This, VPP_real x, VPP_real y);
	void VPP_Point_move(VPP_Point* This, VPP_real x, VPP_real y, VPP_real delta);

	void VPP_LineSegment_init(VPP_LineSegment* This);
	void VPP_LineSegment_set(VPP_LineSegment* This, VPP_real x, VPP_real y);
	void VPP_LineSegment_move(VPP_LineSegment* This, VPP_real x, VPP_real y, VPP_real xofs, VPP_real yofs);

	void VPP_LineSegmentHorizontal_init(VPP_LineSegmentHorizontal* This);
	void VPP_LineSegmentHorizontal_set(VPP_LineSegmentHorizontal* This, VPP_real x, VPP_real y);
	void VPP_LineSegmentHorizontal_move(VPP_LineSegmentHorizontal* This, VPP_real x, VPP_real y, VPP_real xofs);

	void VPP_LineSegmentVertical_init(VPP_LineSegmentVertical* This);
	void VPP_LineSegmentVertical_set(VPP_LineSegmentVertical* This, VPP_real x, VPP_real y);
	void VPP_LineSegmentVertical_move(VPP_LineSegmentVertical* This, VPP_real x, VPP_real y, VPP_real yofs);

	void VPP_Rectangle_init(VPP_Rectangle* This);
	void VPP_Rectangle_set(VPP_Rectangle* This, VPP_real x, VPP_real y, VPP_real width, VPP_real height);
	void VPP_Rectangle_move(VPP_Rectangle* This, VPP_real x, VPP_real y, VPP_real delta);

	void VPP_Circle_init(VPP_Circle* This);
	void VPP_Circle_set(VPP_Circle* This, VPP_real x, VPP_real y, VPP_real radius);
	void VPP_Circle_move(VPP_Circle* This, VPP_real x, VPP_real y, VPP_real delta);

	void VPP_Slope_init(VPP_Slope* This);
	void VPP_Slope_set(VPP_Slope* This, VPP_real x, VPP_real y);
	void VPP_Slope_move(VPP_Slope* This, VPP_real x, VPP_real y, VPP_real xofs, VPP_real yofs);

	void VPP_Triangle_init(VPP_Triangle* This);
	void VPP_Triangle_set(VPP_Triangle* This, VPP_real x, VPP_real y, VPP_real radius);
	void VPP_Triangle_move(VPP_Triangle* This, VPP_real x, VPP_real y, VPP_real delta);

	VPP_bool VPP_Point_intersect_Rectangle(const VPP_Point* This, const VPP_Rectangle* Other);
	VPP_bool VPP_Point_intersect_Circle(const VPP_Point* This, const VPP_Rectangle* Other);
	VPP_bool VPP_Point_intersect_Slope(const VPP_Point* This, const VPP_Rectangle* Other);
	VPP_bool VPP_Point_intersect_Triangle(const VPP_Point* This, const VPP_Rectangle* Other);

	VPP_bool VPP_LineSegment_intersect_LineSegment(const VPP_LineSegment* This, const VPP_LineSegment* Other);
	VPP_bool VPP_LineSegment_intersect_LineSegmentHorizontal(const VPP_LineSegment* This, const VPP_LineSegmentHorizontal* Other);
	VPP_bool VPP_LineSegment_intersect_LineSegmentVertical(const VPP_LineSegment* This, const VPP_LineSegmentVertical* Other);
	VPP_bool VPP_LineSegment_intersect_Rectangle(const VPP_LineSegment* This, const VPP_Rectangle* Other);
	VPP_bool VPP_LineSegment_intersect_Circle(const VPP_LineSegment* This, const VPP_Rectangle* Other);
	VPP_bool VPP_LineSegment_intersect_Slope(const VPP_LineSegment* This, const VPP_Rectangle* Other);
	VPP_bool VPP_LineSegment_intersect_Triangle(const VPP_LineSegment* This, const VPP_Rectangle* Other);

	VPP_bool VPP_LineSegmentHorizontal_intersect_LineSegmentVertical(const VPP_LineSegment* This, const VPP_LineSegmentVertical* Other);
	VPP_bool VPP_LineSegmentHorizontal_intersect_Rectangle(const VPP_LineSegment* This, const VPP_Rectangle* Other);
	VPP_bool VPP_LineSegmentHorizontal_intersect_Circle(const VPP_LineSegment* This, const VPP_Rectangle* Other);
	VPP_bool VPP_LineSegmentHorizontal_intersect_Slope(const VPP_LineSegment* This, const VPP_Rectangle* Other);
	VPP_bool VPP_LineSegmentHorizontal_intersect_Triangle(const VPP_LineSegment* This, const VPP_Rectangle* Other);

	VPP_bool VPP_LineSegmentVertical_intersect_Rectangle(const VPP_LineSegment* This, const VPP_Rectangle* Other);
	VPP_bool VPP_LineSegmentVertical_intersect_Circle(const VPP_LineSegment* This, const VPP_Circle* Other);
	VPP_bool VPP_LineSegmentVertical_intersect_Slope(const VPP_LineSegment* This, const VPP_Slope* Other);
	VPP_bool VPP_LineSegmentVertical_intersect_Triangle(const VPP_LineSegment* This, const VPP_Triangle* Other);

	VPP_bool VPP_Rectangle_intersect_Rectangle(const VPP_Rectangle* This, const VPP_Rectangle* Other);
	VPP_bool VPP_Rectangle_intersect_Circle(const VPP_Rectangle* This, const VPP_Circle* Other);
	VPP_bool VPP_Rectangle_intersect_Slope(const VPP_Rectangle* This, const VPP_Slope* Other);
	VPP_bool VPP_Rectangle_intersect_Triangle(const VPP_Rectangle* This, const VPP_Triangle* Other);

	VPP_bool VPP_Circle_intersect_Circle(const VPP_Circle* This, const VPP_Circle* Other);
	VPP_bool VPP_Circle_intersect_Slope(const VPP_Circle* This, const VPP_Slope* Other);
	VPP_bool VPP_Circle_intersect_Triangle(const VPP_Circle* This, const VPP_Triangle* Other);

	VPP_bool VPP_Slope_intersect_Slope(const VPP_Slope* This, const VPP_Slope* Other);
	VPP_bool VPP_Slope_intersect_Triangle(const VPP_Slope* This, const VPP_Triangle* Other);

	VPP_bool VPP_Triangle_intersect_Triangle(const VPP_Triangle* This, const VPP_Triangle* Other);

#ifdef __cplusplus
}
#endif

#endif /* GEOMETRY2D_H */

