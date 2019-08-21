//
//  main.c
//  UNIT_9
//
//  Created by 李环宇 on 2019/7/23.
//  Copyright © 2019 Li Huanyu. All rights reserved.
//

//unit 9
//2019/7/23

//9.1
#include <stdio.h>

double min(double,double);

int main()
{
    double a,b,c;
    printf("Enter two numbers:");
    scanf("%lf %lf",&a,&b);
    c = min(a, b);
    printf("MIN:%.2lf\n",c);
    
    return 0;
}

double min(double a,double b)
{
    return (a<b)?a:b;
}

//9.2 9.3
#include <stdio.h>
#include <ctype.h>

void chline(char,int,int);
char get_first(void);

int main()
{
    char ch;
    int j,i;
    printf("Enter:");
    ch = get_first();
    printf("How many lines?How many columns?\n");
    scanf("%d %d",&j,&i);
    chline(ch,j,i);
    
    return 0;
}

void chline(char ch,int j,int i)
{
    for (int a = 0;a < j;a++)
    {
        for (int b = 0;b < i;b++)
            putchar(ch);
        putchar('\n');
    }
}

char get_first(void)
{
    char ch;
    while (isblank(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    return ch;
}


//9.4
double Harmonic_average(double a,double b)
{
    double c = (1/a + 1/b)/2;
    return 1/c;
}


//9.5
#include <stdio.h>

void larger_of(double*,double*);

int main()
{
    double a,b;
    printf("Enter:");
    scanf("%lf %lf",&a,&b);
    larger_of(&a,&b);
    printf("a:%.2f b:%.2f\n",a,b);
    
    return 0;
}

void larger_of(double *a,double *b)
{
    (*a > *b)?(*b = *a):(*a = *b);
}


//9.6
#include <stdio.h>

void array(double*,double*,double*);

int main()
{
    double a,b,c;
    printf("Enter:");
    scanf("%lf %lf %lf",&a,&b,&c);
    array(&a,&b,&c);
    printf("%.2lf %.2lf %.2lf\n",a,b,c);
    
    return 0;
}

void array(double *a,double *b,double *c)
{
    double temp;
    if (*a<*c)
    {
        temp = *c;
        *c = *a;
        *a = temp;
    }
    if (*b<*c)
    {
        temp = *c;
        *c = *b;
        *b = temp;
    }
    if (*a<*b)
    {
        temp = *b;
        *b = *a;
        *a = temp;
    }
}


//9.7
#include <stdio.h>
#include <ctype.h>

void func1(void);
int func2(char);

int main()
{
    func1();
    
    return 0;
}

void func1()
{
    char ch;
    ch = getchar();
    while (ch != EOF)
    {
        if (isalpha(ch))
            printf("Yes.%d ",func2(ch));
        else if (ch == '\n')
            putchar('\n');
        else
            printf("No.");
        ch = getchar();
    }
}

int func2(char ch)
{
    if (isupper(ch))
        return ch-'A'+1;
    else
        return ch-'a'+1;
}


//9.8
#include <stdio.h>

double power_pro(double,int);
double power_pro_Recursive(double,int);

int main()
{
    double a;
    int b;
    printf("Enter:");
    scanf("%lf %d",&a,&b);
    double c = power_pro_Recursive(a, b);
    printf("%lf\n",c);
    
    return 0;
}

double power_pro(double a,int b)
{
    double s = 1;
    if (b > 0)
        for (int i = 0;i < b;i++)
            s *= a;
    else if (b == 0)
        s = 0;
    else
    {
        b = -b;
        for (int i = 0;i < b;i++)
            s *= a;
        s = 1/s;
    }
    return s;
}
//9.9
double power_pro_Recursive(double a,int b)
{
    double s;
    if (b > 0)
        s = a*power_pro_Recursive(a, --b);
    else if (b == 0)
        s = 1;
    else
        s = (1/a)*power_pro_Recursive(a, ++b);
    
    return s;
}


//9.10
#include <stdio.h>

void to_base_n(int,int);

int main()
{
    int a,b;
    printf("Enter:");
    scanf("%d %d",&a,&b);
    to_base_n(a, b);
    putchar('\n');
    
    return 0;
}

void to_base_n(int a,int b)
{
    int r;
    r = a % b;
    if (a >= b)
        to_base_n(a/b, b);
    printf("%d",r);
}

#include <stdio.h>

int Fibonacci(int);

int main()
{
    int n;
    printf("Enter:");
    scanf("%d",&n);
    int f = Fibonacci(n);
    printf("%d\n",f);
    
    return 0;
}

int Fibonacci(int n)
{
    if (n > 2)
    {
        int a = 1,b = 1,c = 2;
        for (int i = 3;i < n;i++)
        {
            a = b;
            b = c;
            c = a+b;
        }
        return c;
    }
    else
        return 1;
}
