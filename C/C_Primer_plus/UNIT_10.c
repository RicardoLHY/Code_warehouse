//
//  main.c
//  UNIT_10
//
//  Created by RicardoLHY on 2019/8/19.
//  Copyright © 2019 RicardoLHY. All rights reserved.
//

//unit 10
//2019/8/20

//10.1
 //rain.c  -- finds yearly totals, yearly average, and monthly faverage for several years of rainfall data
#include <stdio.h>
#define MONTHS 12    // number of months in a year
#define YEARS   5    // number of years of data
int main(void)
{
    // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    int year, month;
    float subtot, total;
    
    printf(" YEAR    RAINFALL  (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++)
    {             // for each year, sum rainfall for each month
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += *(*(rain + year) + month);
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot; // total for all years
    }
    printf("\nThe yearly average is %.1f inches.\n\n",
           total/YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");
    
    for (month = 0; month < MONTHS; month++)
    {             // for each month, sum rainfall over years
        for (year = 0, subtot =0; year < YEARS; year++)
            subtot += *(*(rain + year) + month);
        printf("%4.1f ", subtot/YEARS);
    }
    printf("\n");
    
    return 0;
}

//10.2
#include "stdio.h"

void copy_arr(double *,const double *,int);
void copy_ptr(double *,const double *,int);
void copy_ptrs(double *,const double *,const double *);
void print(double*,int);

int main()
{
    const double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    print(source,5);
    copy_arr(target1,source,5);
    copy_ptr(target2,source,5);
    copy_ptrs(target3,source,source+5);
 
    return 0;
}

void print(double array[],int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%.2lf ",array[i]);
    }
    printf("\n");
}

void copy_arr(double *target1,const double *source,int num)
{
    for (int i = 0;i < num;i++)
    {
        target1[i] = source[i];
    }
    print(target1,num);
}

void copy_ptr(double *target2,const double *source,int num)
{
    for (int i = 0;i < num;i++)
    {
        *target2 = *source;
        source++;
        target2++;
    }
    source -= num;
    target2 -= num;
    print(target2,num);
}

void copy_ptrs(double *target3,const double *source,const double *end)
{
    int num = 0;
    for (long i = end - source;i > 0;i--)
    {
        *target3 = *source;
        source++;
        target3++;
        num++;
    }
    source -= num;
    target3 -= num;
    print(target3,num);
}

//10.3
#include <stdio.h>

int return_max(int *,int);

int main()
{
    int array[]={1,2,3,4,5};
    int len = sizeof(array)/sizeof(array[0]);
    int num = return_max(array,len);
    printf("The largest number is %d.\n",num);
    
    return 0;
}

int return_max(int array[],int len)
{
    int max = array[0];
    for (int i = 0;i < len;i++)
    {
        if (max < array[i])
            max = array[i];
    }
    
    return max;
}

//10.4
#include <stdio.h>

int re_max(double *,int);

int main()
{
    double array[] = {1.1,2.2,3.3,4.4,5.5};
    int len = sizeof(array)/sizeof(array[0]);
    int num = re_max(array,len);
    printf("%d\n",num);
    
    return 0;
}

int re_max(double * array,int len)
{
    int max = array[0];
    int n = 0;
    for (int i = 0;i < len;i++)
    {
        if (max < array[i])
        {
            max = array[i];
            n = i;
        }
    }
    
    return n;
}

//10.5
#include <stdio.h>

double subtracting(double *,int);

int main()
{
    double array[] ={1.1,2.2,3.3,4.4,5.5};
    int len = sizeof(array)/sizeof(array[0]);
    double value = subtracting(array,len);
    printf("%.2lf\n",value);
    
    return 0;
}

double subtracting(double array[],int len)
{
    double min = array[0];
    double max = array[0];
    for (int i =0;i < len;i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
        if (min > array[i])
        {
            min = array[i];
        }
    }
    
    return max - min;
}

//10.6
#include <stdio.h>

void Reverse_order(const double *,double *,int);
void print(const double *,int);

int main()
{
    const double array[] ={1.1,2.2,3.3,4.4,5.5};
    int len = sizeof(array)/sizeof(array[0]);
    double Reverse_array[len];
    Reverse_order(array,Reverse_array,len);
    print(Reverse_array,len);
    
    return 0;
}

//不需要也不太可能返回一个数组，只需要用这个函数改变主函数里面的空数组
void Reverse_order(const double * array,double *Reverse_array,int len)
{
    for (int i = 0; i < len; i++)
    {
        Reverse_array[i] = array[len - i -1];
    }
}

void print(const double * Reverse_array,int len)
{
    for (int i = 0;i < len;i++)
    {
        printf("%.2lf ",Reverse_array[i]);
    }
    printf("\n");
}

//10.7
#include <stdio.h>
#define ROW 3
#define COLUMN 2

void copy_arr(double other_array[],const double array[]);
void print(double other_array[ROW][COLUMN]);

int main()
{
    const double array[ROW][COLUMN] = {{1.1,2.2},{3.3,4.4},{5.5,6.6}};
    double other_array[ROW][COLUMN];
    for (int i = 0;i < ROW;i++)
    {
        copy_arr(other_array[i],array[i]);
    }
    print(other_array);
}

//这里的实参是一维数组，代入到形参当中，将One_dimensional_other_array替换成other_array[i]，相当于other_array[i][j]
void copy_arr(double One_dimensional_other_array[],const double One_dimensional_array[])
{
    for (int j = 0;j < COLUMN;j++)
    {
        One_dimensional_other_array[j] = One_dimensional_array[j];
    }
}

void print(double other_array[ROW][COLUMN])
{
    for (int i = 0;i < ROW;i++)
    {
        for (int j = 0;j < COLUMN;j++)
        {
            printf("%.1lf ",other_array[i][j]);
        }
        putchar('\n');
    }
}

//2019.8.21
//10.8
#include <stdio.h>
#define SEVEN 7
#define THREE 3

void copy_arr(double* pt1,double* pt2,int num);
void print(double* pt2,int num);

int main()
{
    double array1[SEVEN] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7};
    double array2[THREE];
    double* pt1 = &array1[2];
    double* pt2 = &array2[0];
    copy_arr(pt1, pt2, THREE);
    print(pt2,THREE);
    
    return 0;
}

void copy_arr(double* pt1,double* pt2,int num)
{
    for (int i = 0; i < num; i++)
    {
        * pt2 = * pt1;
        pt1++;
        pt2++;
    }
    pt2 -= num;
}

void print(double* pt2,int num)
{
    for (int i = 0;i < num;i++)
    {
        printf("%.2lf ",*pt2);
        pt2++;
    }
    putchar('\n');
}

//10.9
#include <stdio.h>
#define ROWS 3
#define COLS 5

void copy_arr(int rs,int cs,const double array1[rs][cs],double array2[rs][cs]);
void print(int rs,int cs,double array[rs][cs]);

int main()
{
    double array1[ROWS][COLS] = {
        {1.1,2.2,3.3,4.4,5.5},
        {6.6,2.2,3.3,4.4,5.5},
        {8.8,2.2,3.3,4.4,5.5}};
    double array2[ROWS][COLS];
    copy_arr(ROWS,COLS,array1,array2);
    print(ROWS,COLS,array1);
    print(ROWS,COLS,array2);
}

void copy_arr(int rs,int cs,const double array1[rs][cs],double array2[rs][cs])
{
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < cs;j++)
        {
            array2[i][j] = array1[i][j];
        }
    }
}

void print(int rs,int cs,double array[rs][cs])
{
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < cs;j++)
        {
            printf("%.2lf ",array[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

//10.10
#include <stdio.h>
#define NUM 4

void addArray(const double*,const double*,double*,int);
void printArray(double*,int);

int main()
{
    double array1[NUM] = {1,2,3,4};
    double array2[NUM] = {2,4,6,8};
    double array3[NUM];
    addArray(array1, array2, array3, NUM);
    printArray(array3, NUM);
    
    return 0;
}

void addArray(const double* array1,const double* array2,double* array3,int num)
{
    for (int i = 0;i < num;i++)
    {
        *array3 = *array1 + *array2;
        array3++;array2++;array1++;
    }
}

void printArray(double* array,int num)
{
    for (int i = 0;i < num;i++)
    {
        printf("%.2lf ",array[i]);
    }
    putchar('\n');
}

//10.11
#include <stdio.h>
#define RAWS 3
#define COLS 5

void printArray(int[][COLS],int);
void multiplyArray(int[][COLS],int);

int main()
{
    int array[RAWS][COLS] =
    {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };
    printArray(array,RAWS);
    multiplyArray(array,RAWS);
    printArray(array,RAWS);
    
    return 0;
}

void printArray(int array[][COLS],int rs)
{
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < COLS;j++)
        {
            printf("%d ",array[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void multiplyArray(int array[][COLS],int rs)
{
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < COLS;j++)
        {
            array[i][j] *= 2;
        }
    }
}

//10.12
#include <stdio.h>
#define ROW 3
#define COLUMN 2

void copy_arr(double other_array[][COLUMN],const double array[][COLUMN],int rs);
void print(double other_array[ROW][COLUMN]);

int main()
{
    const double array[ROW][COLUMN] = {{1.1,2.2},{3.3,4.4},{5.5,6.6}};
    double other_array[ROW][COLUMN];
    copy_arr(other_array,array,ROW);
    print(other_array);
}

void copy_arr(double One_dimensional_other_array[][COLUMN],const double One_dimensional_array[][COLUMN],int rs)
{
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < COLUMN;j++)
        {
            One_dimensional_other_array[i][j] = One_dimensional_array[i][j];
        }
    }
}

void print(double other_array[ROW][COLUMN])
{
    for (int i = 0;i < ROW;i++)
    {
        for (int j = 0;j < COLUMN;j++)
        {
            printf("%.1lf ",other_array[i][j]);
        }
        putchar('\n');
    }
}

//10.13
#include <stdio.h>
#define RAWS 3
#define COLS 5

void fillDataIntoArray(double array[][COLS],int rs);
double calculateAverageOfGroup(double array[]);
double calculateTotalAverage(double array[][COLS],int rs);
double findMaximum(double array[][COLS],int rs);
void printResult(double AverageOfGroup[],double TotalAverage,double Maximum);

int main()
{
    double array[RAWS][COLS];
    double AverageOfGroup[RAWS];
    fillDataIntoArray(array,RAWS);
    for (int i = 0;i < RAWS;i++)
    {
        AverageOfGroup[i] = calculateAverageOfGroup(array[i]);
    }
    double TotalAverage = calculateTotalAverage(array,RAWS);
    double Maximum = findMaximum(array,RAWS);
    printResult(AverageOfGroup,TotalAverage, Maximum);
    
    return 0;
}

void fillDataIntoArray(double array[][COLS],int rs)
{
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < COLS;j++)
        {
            printf("Please enter the number of Raw %d,Column %d:",i,j);
            scanf("%lf",&array[i][j]);
        }
    }
}

double calculateAverageOfGroup(double array[])
{
    double s = 0;
    for (int j = 0;j < COLS;j++)
    {
        s += array[j];
    }
    
    return s/COLS;
}

double calculateTotalAverage(double array[][COLS],int rs)
{
    double s = 0;
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < COLS;j++)
        {
            s += array[i][j];
        }
    }
    
    return s/(rs*COLS);
}

double findMaximum(double array[][COLS],int rs)
{
    double max = array[0][0];
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < COLS;j++)
        {
            if (max < array[i][j])
            {
                max = array[i][j];
            }
        }
    }
    
    return max;
}

void printResult(double AverageOfGroup[],double TotalAverage,double Maximum)
{
    for (int i = 0;i < RAWS;i++)
    {
        printf("The average of Raw %d is %.2lf.\n",i,AverageOfGroup[i]);
    }
    printf("The total average is %.2lf.\n",TotalAverage);
    printf("The maximun of numbers is %.2lf.\n",Maximum);
}

#include <stdio.h>
#define RAWS 3
#define COLS 5

void fillDataIntoArray(int rs,int cs,double array[rs][cs]);
double calculateAverageOfGroup(int cs,double array[cs]);
double calculateTotalAverage(int rs,int cs,double array[rs][cs]);
double findMaximum(int rs,int cs,double array[rs][cs]);
void printResult(int rs,double AverageOfGroup[],double TotalAverage,double Maximum);

int main()
{
    double array[RAWS][COLS];
    double AverageOfGroup[RAWS];
    fillDataIntoArray(RAWS,COLS,array);
    for (int i = 0;i < RAWS;i++)
    {
        AverageOfGroup[i] = calculateAverageOfGroup(COLS,array[i]);
    }
    double TotalAverage = calculateTotalAverage(RAWS,COLS,array);
    double Maximum = findMaximum(RAWS,COLS,array);
    printResult(RAWS,AverageOfGroup,TotalAverage, Maximum);
    
    return 0;
}

void fillDataIntoArray(int rs,int cs,double array[rs][cs])
{
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < cs;j++)
        {
            printf("Please enter the number of Raw %d,Column %d:",i,j);
            if (scanf("%lf",&array[i][j]) != 1)
            {
                printf("Wrong!Try again.\n");
                scanf("%*s");
                j--;
            }
        }
    }
    putchar('\n');
}

double calculateAverageOfGroup(int cs,double array[cs])
{
    double s = 0;
    for (int j = 0;j < cs;j++)
    {
        s += array[j];
    }
    
    return s/cs;
}

double calculateTotalAverage(int rs,int cs,double array[rs][cs])
{
    double s = 0;
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < cs;j++)
        {
            s += array[i][j];
        }
    }
    
    return s/(rs*cs);
}

double findMaximum(int rs,int cs,double array[rs][cs])
{
    double max = array[0][0];
    for (int i = 0;i < rs;i++)
    {
        for (int j = 0;j < cs;j++)
        {
            if (max < array[i][j])
            {
                max = array[i][j];
            }
        }
    }
    
    return max;
}

void printResult(int rs,double AverageOfGroup[],double TotalAverage,double Maximum)
{
    for (int i = 0;i < rs;i++)
    {
        printf("The average of Raw %d is %.2lf.\n",i,AverageOfGroup[i]);
    }
    putchar('\n');
    printf("The total average is %.2lf.\n\n",TotalAverage);
    printf("The maximun of numbers is %.2lf.\n\n",Maximum);
}
