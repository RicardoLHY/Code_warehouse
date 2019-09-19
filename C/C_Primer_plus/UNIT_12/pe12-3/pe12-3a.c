//
//  pe12-3a.c
//  UNIT_12
//
//  Created by 李环宇 on 2019/9/18.
//  Copyright © 2019 Li Huanyu. All rights reserved.
//
/*
#include "pe12-3a.h"


int set_mode(int b_mode)
{
    static int mode;
    mode = b_mode;
    static int last_mode = 0;
    if ((mode > 1) && (last_mode == 1))
    {
        printf("Invalid mode specified. Mode 1(US) used.\n");
        mode = 1;
    }
    if ((mode > 1) && (last_mode == 0))
    {
        printf("Invalid mode specified. Mode 0(metric) used.\n");
        mode = 0;
    }
    last_mode = mode;
    
    return mode;
}

void get_info(int mode,double* array)
{
    static double distance;
    static double fuel;
    if (mode == 0)
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf",&distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf",&fuel);
    }
    else
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf",&distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf",&fuel);
    }
    *array++ = distance;
    *array-- = fuel;
}

void show_info(int mode,double* array)
{
    double distance = *array++;
    double fuel = *array--;
    if (mode == 0)
        printf("Fuel consumption is %.2lf liters per 100km.\n",100*fuel/distance);
    else
        printf("Fuel consumption is %.2lf miles per gallon.\n",distance/fuel);
}
*/
