//
//  pe12-3b.c
//  UNIT_12
//
//  Created by 李环宇 on 2019/9/18.
//  Copyright © 2019 Li Huanyu. All rights reserved.
//
/*
#include "pe12-3a.h"

int main(void)
{
    int mode;
    double* array = (double*)calloc(2,sizeof(double));
    
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d",&mode);
    while (mode >= 0)
    {
        mode = set_mode(mode);
        get_info(mode,array);
        show_info(mode,array);
        printf("Enter 0 for metric mode, 1 for US mode: ");
        printf("(-1 to quit): ");
        scanf("%d",&mode);
    }
    printf("Done.\n");
    
    return 0;
}
*/
