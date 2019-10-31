/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   types.h
 * Author: jack
 *
 * Created on 8 de dezembro de 2018, 17:32
 */

#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * Boolean value, true or false
	 */
	typedef unsigned char VPP_bool;
	/**
	 * True boolean value
	 */
	const VPP_bool VPP_true;
	/**
	 * False boolean value
	 */
	const VPP_bool VPP_false;

	/**
	 * Numeric sign value
	 */
	typedef signed char VPP_sign;
	/**
	 * Positive nuberic sign
	 */
	#define VPP_positive 1
	/**
	 * No numeric sign
	 */
	#define VPP_nosign 0
	/**
	 * Negative numeric sign
	 */
	#define VPP_negative -1

	/**
	 * A timestamp, with the zero being the beginning of holocene year zero.
	 */
	typedef unsigned long long int VPP_timestamp;


	typedef unsigned char VPP_byte;

	typedef signed short VPP_integershort;
	typedef signed int VPP_integer;
	typedef signed long long int VPP_integerlong;

	typedef unsigned short VPP_naturalshort;
	typedef unsigned int VPP_natural;
	typedef unsigned long long int VPP_naturallong;

	typedef float VPP_real;
	typedef double VPP_realdouble;

	typedef unsigned short VPP_itemIndex;
	typedef unsigned int VPP_dictEntryIndex;
	typedef unsigned char VPP_sdictEntryIndex;

	typedef enum {
		VPP_DT_void,

		//primitive numbers
		VPP_DT_real,
		VPP_DT_realdouble,
		VPP_DT_integershort,
		VPP_DT_integer,
		VPP_DT_integerlong,
		VPP_DT_naturalshort,
		VPP_DT_natural,
		VPP_DT_naturallong,

		//booleans
		VPP_DT_bool,
		VPP_DT_sign,

		//text
		VPP_DT_string,

		//object
		VPP_DT_object,

		//special numbers
		VPP_DT_complex,
		VPP_DT_complexPolar,
		VPP_DT_quaternion,
		VPP_DT_angle,
		VPP_DT_range,
		VPP_DT_fraction,

		//geometric
		VPP_DT_point,
		VPP_DT_circle,
		VPP_DT_line,
		VPP_DT_linehorizontal,
		VPP_DT_linevertical,
		VPP_DT_rectangle,
		VPP_DT_slope,
		VPP_DT_triangle,

		//time
		VPP_DT_timestamp,
		VPP_DT_gregorian,
	} VPP_datatype;




#ifdef __cplusplus
}
#endif

#endif /* TYPES_H */

