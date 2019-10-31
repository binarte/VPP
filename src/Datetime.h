/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Datetime.h
 * Author: vanduir
 *
 * Created on 5 de Dezembro de 2018, 16:41
 */

#ifndef DATETIME_H
#define DATETIME_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * 
     */
    typedef struct {
        VPP_integer year;
        VPP_byte month;
        VPP_byte day;
        VPP_byte hour;
        VPP_byte minute;
        VPP_naturalshort millisecond;
    } VPP_Gregorian;

    typedef struct {
        VPP_sign sign;
        VPP_natural years;
        VPP_natural months;
        VPP_natural weeks;
        VPP_natural days;
        VPP_natural hours;
        VPP_natural minutes;
        VPP_natural milliseconds;
    } VPP_DateInterval;


    void VPP_Gregorian_init(VPP_Gregorian* This);
    void VPP_Gregorian_setValue(VPP_Gregorian* This,
            VPP_integer year,
            VPP_byte month,
            VPP_byte day,
            VPP_byte hours,
            VPP_byte minutes,
            VPP_natural milliseconds
            );
    VPP_timestamp VPP_Gregorian_toTimestamp(const VPP_Gregorian* This);
    void VPP_Gregorian_setTimestamp(const VPP_timestamp ts);
    void VPP_Gregorian_add(VPP_Gregorian* This, const VPP_DateInterval* interval);
    void VPP_Gregorian_set(VPP_Gregorian* This, const VPP_Gregorian* Other);
    VPP_bool VPP_Gregorian_isLeap(const VPP_Gregorian* This);
    VPP_sign VPP_Gregorian_compare(const VPP_Gregorian* first, const VPP_Gregorian* second);
    VPP_byte VPP_Gregorian_monthLength(const VPP_Gregorian* This);
    VPP_naturalshort VPP_Gregorian_yearLength(const VPP_Gregorian* This);

    void VPP_DateInterval_set(VPP_DateInterval* This,
            VPP_sign sign,
            VPP_natural years,
            VPP_natural months,
            VPP_natural days,
            VPP_natural hours,
            VPP_natural minutes,
            VPP_natural milliseconds
            );
    void VPP_DateInterval_setDifference(VPP_DateInterval* This, const VPP_Gregorian* first, const VPP_Gregorian* second);


#ifdef __cplusplus
}
#endif

#endif /* DATETIME_H */

