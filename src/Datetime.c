/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Datetime.h"
#include <time.h>
#include <sys/time.h>


#define _LEAP_4 ((365 * 4) + 1)
#define _LEAP_100 ((_LEAP_4 * (100/4)) - 1)
#define _LEAP_400 ((_LEAP_100 * 4) + 1)
#define _MILLIS (24 * 60 * 60 * 1000)

const unsigned int __VPP__DATETIME__LEAP4__ = _LEAP_4;
const unsigned int __VPP__DATETIME__LEAP100__ = _LEAP_100;
const unsigned int __VPP__DATETIME__LEAP400__ = _LEAP_400;

const unsigned int __VPP__DATETIME__LEAP4MILLIS__ = _LEAP_4 * _MILLIS;
const unsigned int __VPP__DATETIME__LEAP100MILLIS__ = _LEAP_100 * _MILLIS;
const unsigned int __VPP__DATETIME__LEAP400MILLIS__ = _LEAP_400 * _MILLIS;

#define leap4 __VPP__DATETIME__LEAP4__
#define leap100 __VPP__DATETIME__LEAP100__
#define leap400 __VPP__DATETIME__LEAP400__

#define leap4millis __VPP__DATETIME__LEAP4MILLIS__
#define leap100millis __VPP__DATETIME__LEAP100MILLIS__
#define leap400millis __VPP__DATETIME__LEAP400MILLIS__

void VPP_Gregorian_init(VPP_Gregorian* This) {
    time_t rawtime;
    struct tm * timeinfo;
    struct timeval tval;

    time(&rawtime);
    gettimeofday(&tval, NULL);

    timeinfo = localtime(&rawtime);

    This->year = timeinfo->tm_year + 1900;
    This->month = timeinfo->tm_mon + 1;
    This->day = timeinfo->tm_mday + 1;
    This->hour = timeinfo->tm_hour;
    This->minute = timeinfo->tm_min;
    This->millisecond = (timeinfo->tm_sec * 1000) + (tval.tv_usec / 1000);
}

void VPP_Gregorian_setValue(
        VPP_Gregorian* This,
        VPP_integer year, VPP_byte month, VPP_byte day,
        VPP_byte hours, VPP_byte minutes, VPP_natural milliseconds) {
    month--;
    day--;

    This->year = year + (year < 0 ? 1 : 0);
    This->month = month % 12;
    This->day = day % VPP_Gregorian_monthLength(This);
    This->hour = hours % 24;
    This->minute = minutes % 60;
    This->millisecond = milliseconds % 60000;

    VPP_DateInterval intv;
    VPP_DateInterval_set(&intv, VPP_positive, 0,
            month - This->month,
            day - This->day,
            hours - This->hour,
            minutes - This->minute,
            milliseconds - This->millisecond
            );

    VPP_Gregorian_add(This, &intv);
}

VPP_naturalshort VPP_Gregorian_yearLength(const VPP_Gregorian* This) {
    return VPP_Gregorian_isLeap(This) ? 366 : 365;
}

VPP_byte VPP_Gregorian_monthLength(const VPP_Gregorian* This) {
    switch (This->month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return VPP_Gregorian_isLeap(This) ? 29 : 28;
    }
    return 0;
}

VPP_bool VPP_Gregorian_isLeap(const VPP_Gregorian* This) {
    int y = This->year;
    if (y < 0) {
        y += 10001;
    }
    if ((y % 400) == 0) {
        return VPP_true;
    }
    if ((y % 100) == 0) {
        return VPP_false;
    }
    if ((y % 4) == 0) {
        return VPP_true;
    }
    return VPP_false;
}

VPP_sign VPP_Gregorian_compare(const VPP_Gregorian* first, const VPP_Gregorian* second) {
    if (first->year > second->year) return VPP_positive;
    if (first->year < second->year) return VPP_negative;

    if (first->month > second->month) return VPP_positive;
    if (first->month < second->month) return VPP_negative;

    if (first->day > second->day) return VPP_positive;
    if (first->day < second->day) return VPP_negative;

    if (first->hour > second->hour) return VPP_positive;
    if (first->hour < second->hour) return VPP_negative;

    if (first->minute > second->minute) return VPP_positive;
    if (first->minute < second->minute) return VPP_negative;

    if (first->millisecond > second->millisecond) return VPP_positive;
    if (first->millisecond < second->millisecond) return VPP_negative;

    return 0;
}

void VPP_Gregorian_set(VPP_Gregorian* This, const VPP_Gregorian* Other) {
    This->year = Other->year;
    This->month = Other->month;
    This->day = Other->day;
    This->hour = Other->hour;
    This->minute = Other->minute;
    This->millisecond = Other->millisecond;
}

void VPP_Gregorian_add(VPP_Gregorian* This, const VPP_DateInterval* interval) {
    if (interval->sign == VPP_nosign) {
        return;
    }
    signed long long int aux, aux2;
    if (interval->sign == VPP_positive) {
        aux =
                This->month + interval->months +
                ((This->year + interval->years) * 12);
        This->month = aux % 12;
        aux -= This->month;
        aux /= 12;
        This->year = aux;

        aux =
                This->millisecond + interval->milliseconds +
                ((This->minute + interval->minutes) * 60000) +
                ((This->hour + interval->hours) * 3600000) +
                ((This->day + interval->days) * 86400000);
        This->millisecond = aux % 60000;
        aux -= This->millisecond;
        aux /= 60000;
        This->minute = aux % 60;
        aux -= This->minute;
        aux /= 60;
        This->hour = aux % 24;
        aux -= This->hour;
        aux /= 24;

        //Subtract leap year groups from days
        aux2 = aux % leap400;
        This->year += ((aux - aux2) / leap400) * 400;
        aux = aux2;

        aux2 = aux % leap100;
        This->year += ((aux - aux2) / leap100) * 100;
        aux = aux2;

        aux2 = aux % leap4;
        This->year += ((aux - aux2) / leap4) * 4;
        aux = aux2;

        //Subtract years from days
        while (aux >= VPP_Gregorian_yearLength(This)) {
            aux -= VPP_Gregorian_yearLength(This);
            This->year++;
        }

        //Subtract months from days
        while (aux >= VPP_Gregorian_monthLength(This)) {
            aux -= VPP_Gregorian_monthLength(This);
            This->month++;
            if (This->month == 12) {
                This->month = 0;
                This->year++;
            }
        }
        This->day = aux;
    } else {
        aux =
                This->month - interval->months +
                ((This->year - interval->years) * 12);
        This->month = aux % 12;
        aux -= This->month;
        aux /= 12;
        This->year = aux;

        aux =
                This->millisecond - interval->milliseconds +
                ((This->minute - interval->minutes) * 60000) +
                ((This->hour - interval->hours) * 3600000) +
                ((This->day - interval->days) * 86400000);


        if (aux >= 0) {
            //The value didn't turn out negative, no day correction necessary
            This->millisecond = aux % 60000;
            aux -= This->millisecond;
            aux /= 60000;
            This->minute = aux % 60;
            aux -= This->minute;
            aux /= 60;
            This->hour = aux % 24;
            aux -= This->hour;
            aux /= 24;
            This->day = aux;
            return;
        }

        aux2 = aux % 86400000;
        if (aux2 != 0) {
            aux -= aux2;
            aux -= 86400000;
            aux2 = 86400000 - aux2;
        }
        This->millisecond = aux2 % 60000;
        aux2 -= This->millisecond;
        aux2 /= 60000;
        This->minute = aux2 % 60;
        aux2 -= This->minute;
        aux2 /= 60;
        This->hour = aux2 % 24;
        aux /= 86400000;


        //Subtract leap year groups from days
        aux2 = aux % leap400;
        This->year += ((aux - aux2) / leap400) * 400;
        aux = aux2;

        aux2 = aux % leap100;
        This->year += ((aux - aux2) / leap100) * 100;
        aux = aux2;

        aux2 = aux % leap4;
        This->year += ((aux - aux2) / leap4) * 4;
        aux = aux2;

        //Subtract years from days
        while (-aux >= VPP_Gregorian_yearLength(This)) {
            aux += VPP_Gregorian_yearLength(This);
            This->year--;
        }

        //Subtract months from days
        while (aux < 0) {
            aux += VPP_Gregorian_monthLength(This);
            if (This->month == 0) {
                This->month = 12;
                This->year--;
            }
            This->month--;
        }
        This->day = aux;
    }
}

VPP_DateInterval_set(VPP_DateInterval* This, VPP_sign sign, VPP_natural years, VPP_natural months, VPP_natural days, VPP_natural hours, VPP_natural minutes, VPP_natural milliseconds){
    This->years = years;
    This->months = months;
    This->days = days;
    This->hours = hours;
    This->minutes = minutes;
    This->milliseconds = milliseconds;
    
    if (years == 0 && months == 0 && days == 0 && hours == 0 && minutes == 0 && milliseconds == 0){
        This->sign = VPP_nosign;
    } else {
        This->sign = sign;
    }
}