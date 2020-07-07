//
//  main.c
//  UNIT_1to8
//
//  Created by RicardoLHY on 2019/7/23.
//  Copyright © 2019 RicardoLHY. All rights reserved.
//


#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

//unit 2
//2.1
#include "stdio.h"

int main()
{
    printf("Li Huanyu\n");
    printf("Li\nHuanyu\n");
    printf("Li ");
    printf("Huanyu\n");
    return 0;
}

//2.2
#include "stdio.h"

int main()
{
    printf("Li Huanyu\nAnhui Province Bengbu City\n");
    return 0;
}

//2019/7/1

//2.3
#include "stdio.h"

int main()
{
    int year;
    printf("Please write your age: ");
    scanf("%d",&year);
    int day = year*365;
    printf("Year:%d\n",year);
    printf("Day:%d\n",day);
    return 0;
}

//2.4
#include "stdio.h"

void jolly()
{
    int i;
    for(i=1;i<=3;i++)//const n=3; while(i<=n)
        printf("For he is a jolly good fellow.\n");
}

void deny()
{
    printf("Which nobody can deny!\n");
}

int main()
{
    jolly();
    deny();
}

//2.5
#include "stdio.h"

void br()
{
    printf("Brazil,Russia");
}

void ic()
{
    printf("India,China");
}

int main()
{
    br();printf(",");ic();
    printf("\n");ic();
    printf("\n");br();
    printf("\n");
    
    return 0;
}

//2.6
#include "stdio.h"

int main()
{
    const int toes = 10;
    printf("toes=%d\n",toes);
    printf("toes的两倍=%d\n",toes*2);
    printf("toes的平方=%d\n",toes*toes);
    return 0;
}

//2.7
#include "stdio.h"
void sm()
{
    printf("Smile!");
}

int main()
{
    sm();sm();sm();printf("\n");
    sm();sm();printf("\n");
    sm();printf("\n");
    return 0;
}

//2.8
#include "stdio.h"

void two();

void one_three()
{
    printf("one\n");
    two();
    printf("three\n");
}

void two()
{
    printf("two\n");
}

int main()
{
    printf("starting now:\n");
    one_three();
    printf("done!\n");
    return 0;
}

//unit 3
//3.2
#include "stdio.h"

int main()
{
    int num;
    printf("Please write:");
    scanf("%d",&num);
    char a = num;
    printf("%c\n",num);
    return 0;
}

//3.3
#include "stdio.h"

int main()
{
    printf("\a");
    printf("Startled by the sudden sound, Sally shouted,\n\"By the Great Pumpkin, wht was that!\"\n");
    return 0;
}

//3.4
#include "stdio.h"

int main()
{
    float num;
    printf("Enter a floating-point value: ");
    scanf("%f",&num);
    printf("fixed-point notation: %.6f\n",num);
    printf("enponential notation: %e\n",num);
    printf("p notation: %a\n",num);
}

//3.5
#include "stdio.h"

int main()
{
    int age;
    printf("Please write your age:");
    scanf("%d",&age);
    float sec = age*3.156e+7;
    printf("Your second: %e\n",sec);
    return 0;
}

//3.6
#include "stdio.h"

int main()
{
    float quart;
    printf("How many quarts:");
    scanf("%f",&quart);
    float num = 950*quart/3.0e-23;
    printf("The N of water is %e\n",num);
    return 0;
}

//3.7
#include "stdio.h"

int main()
{
    float inch;
    printf("Please write your height(inch):");
    scanf("%f",&inch);
    float cm = inch*2.54;
    printf("Your height is %.2f cm.\n",cm);
    return 0;
}

//3.8
#include "stdio.h"

int main()
{
    float cup;
    printf("Please write the number of cups:");
    scanf("%f",&cup);
    float pint = cup/2;
    float ounce = cup*8;
    float spoon = cup*16;
    float tea = cup*48;
    printf("%.2fpint = %.2fcup = %.2founce = %.2fspoon = %.2ftea\n",pint,cup,ounce,spoon,tea);
    return 0;
}

//unit 4
//2019/7/8

//4.1
#include "stdio.h"

int main()
{
    char first[10];
    char last[10];
    printf("Please write your name:");
    scanf("%s %s",first,last);
    printf("“%s,%s”\n",first,last);
    
    return 0;
}

//4.2
#include "stdio.h"

int main()
{
    char name[10];
    printf("Please write your name:");
    scanf("%s",name);
    printf("“%s”\n",name);
    printf("“%20s”\n",name);
    printf("“%-20s”\n",name);
    printf("“   %s”\n",name);
    
    return 0;
}

//4.3
#include "stdio.h"

int main()
{
    float num;
    printf("Please write the number:");
    scanf("%f",&num);
    printf("a. The input is %.1f or %.1e. \n",num,num);
    printf("b. The input is %+.3f or %.3e. \n",num,num);
    
    return 0;
}

//4.4
#include "stdio.h"

int main()
{
    char name[10];
    float height;
    printf("Please enter your name and height:");
    scanf("%s %f",name,&height);
    printf("%s, you are %f m tall.\n",name,(height/100));
    return 0;
}

//2019/7/9
//4.5
#include "stdio.h"

int main()
{
    float speed,size,time;
    printf("Please enter download speed and file size:");
    scanf("%f %f",&speed,&size);
    time = size*8/speed;
    printf("At %.2f megabits per secord, a file of %.2f magebytes\n",speed,size);
    printf("downloads in %.2f secords.\n",time);
    
    return 0;
}

//4.6
#include "stdio.h"
#include "string.h"

int main()
{
    char first[10],last[10];
    printf("Please enter your first name:\n");
    scanf("%s",first);
    printf("Please enter your last name:\n");
    scanf("%s",last);
    int first_length=strlen(first);
    int last_length=strlen(last);
    printf("%-10s %s\n",first,last);
    printf("%-10d %d",first_length,last_length);
    
    return 0;
}

//4.7
#include "stdio.h"
#include "float.h"

int main()
{
    double d = 1.0/3.0;
    float f = 1.0/3.0;
    printf("%.6f %.6f\n",d,f);
    printf("%.12f %.12f\n",d,f);
    printf("%.16f %.16f\n",d,d);
    printf("double precious = %d digits\n",DBL_DIG);
    printf("float precious = %d digits\n",FLT_DIG);
    
    return 0;
}

//4.8
#include "stdio.h"
#define GALLON 3.785
#define MILE 1.609

int main()
{
    float gallon,mile,liter,kilometer,US,EU;
    printf("Please enter the gallons and miles:");
    scanf("%f %f",&gallon,&mile);
    liter = gallon*GALLON;
    kilometer = mile*MILE;
    US = kilometer/liter;
    EU = liter/kilometer;
    printf("US = %.1f EU= %.1f\n",US,EU);
    
    return 0;
}

//unit 5
//5.1
#include "stdio.h"

int main()
{
    const int k = 60;
    int minute;
    printf("Enter:");
    scanf("%d",&minute);
    while (minute>0)
    {
        int hour = minute/k;
        minute = minute%k;
        printf("%d:%d\n",hour,minute);
        printf("Enter:");
        scanf("%d",&minute);
    }
    
    return 0;
}

//5.2
#include "stdio.h"

int main()
{
    int num;
    printf("Please enter a number:");
    scanf("%d",&num );
    for (int i=0;i<=10;i++)
    {
        printf("%d ",num++);
    }
    printf("\n");
    
    return 0;
}

//5.3
#include "stdio.h"

int main()
{
    int day,week,newday;
    printf("How many days?\n");
    scanf("%d",&day);
    while (day>0)
    {
        week = day/7;
        newday = day%7;
        printf("%d days are %d weeks, %d days.\n",day,week,newday);
        printf("How many days?\n");
        scanf("%d",&day);
    }
    
    printf("Done.\n");
    return 0;
}

//5.4
#include "stdio.h"
#define k 2.54

int main()
{
    float height,inch;
    int feet;
    printf("Enter a height in centimeters:");
    scanf("%f",&height);
    while (height>0)
    {
        inch = height/k;
        feet = inch/12;
        inch = inch-feet*12;
        printf("%.1f cm = %d feet, %.1f inches\n",height,feet,inch);
        printf("Enter a height in centimeters(<=0 to quit):");
        scanf("%f",&height);
    }
    printf("bye\n");
    
    return 0;
}

//2019/7/10
//5.5
#include "stdio.h"

int main()
{
    int day,i,s=0;
    printf("Please enter:");
    scanf("%d",&day);
    for (i=1;i<=day;i++)
    {
        s = s+i;
    }
    printf("%d\n",s);
    
    return 0;
}

//5.6
#include "stdio.h"

int main()
{
    int day,i,s=0;
    printf("Please enter:");
    scanf("%d",&day);
    for (i=1;i<=day;i++)
    {
        s = s + i*i;
    }
    printf("%d\n",s);
    
    return 0;
}

//5.7
#include "stdio.h"

void tocube(double i)
{
    printf("%lf\n",i*i*i);
}

int main()
{
    double n;
    printf("Please enter:");
    scanf("%lf",&n);
    tocube(n);
}

//5.8
#include "stdio.h"

int main()
{
    int a,b;
    printf("This program computes moduli\n");
    printf("Enter an integer to serve as the second operand:");
    scanf("%d",&b);
    printf("Now enter the first operand:");
    scanf("%d",&a);
    while (a>0)
    {
        printf("%d %% %d is %d\n",a,b,a%b);
        printf("Enter the next number for first operand(<= 0 to quit):");
        scanf("%d",&a);
    }
    printf("Done.\n");
    
    return 0;
}

//5.9
#include "stdio.h"

void Temperature(double F)
{
    double C,K;
    const float k = 5/9;
    const float b = -32;
    const float c = 273.15;
    C = k*(F-b);
    K = C + c;
    printf("F = %.2lf ; C = %.2lf ; K = %.2lf\n",F,C,K);
}

int main()
{
    double f;
    printf("Enter:");
    int x = scanf("%lf",&f);
    while (x==1)
    {
        Temperature(f);
        printf("Enter:");
        x = scanf("%lf",&f);
    }
    printf("Done.\n");
    
    return 0;
}

//2019/7/11
//unit 6

//ASCII
#include "stdio.h"

int main()
{
    char x;
    for (int i=33;i<128;i++)
    {
        x = i;
        printf("%d %c\n",x,x);
    }
    
    return 0;
}

//6.1
#include "stdio.h"

int main()
{
    char letter[26];
    char ch = 'a';
    for (int i=0;i<26;i++)
    {
        letter[i] = ch;
        printf("%c",letter[i]);
        ch++;
    }
    printf("\n");
    
    return 0;
}

//6.2
#include "stdio.h"

int main()
{
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<=i;j++)
        {
            printf("$");
        }
        printf("\n");
    }
    
    return 0;
}

//6.3
#include "stdio.h"

int main()
{
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<=i;j++)
        {
            char x = 'F'-j;
            printf("%c",x);
        }
        printf("\n");
    }
    
    return 0;
}

//6.4
#include "stdio.h"

int main()
{
    int n = 0;
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<=i;j++)
        {
            char x = 'A' + n++;
            printf("%c",x);
            
        }
        printf("\n");
    }
    
    return 0;
}

//6.5
#include "stdio.h"

int main()
{
    char x;
    printf("Please enter an uppercase letter:");
    scanf("%c",&x);
    int n = x - 'A';
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            printf(" ");
        }
        for (int k=0;k<=i;k++)
        {
            printf("%c",'A'+k);
        }
        for (int l=i;l>0; l--)
        {
            printf("%c",'A'+l-1);
        }
        printf("\n");
    }
    
    return 0;
}

//6.6
#include "stdio.h"

int main()
{
    int x,y;
    printf("Enter:");
    scanf("%d %d",&x,&y);
    for (int i=x;i<y+1;i++)
    {
        printf("%-10d%-10d%-10d\n",i,i*i,i*i*i);
    }
    
    return 0;
}

//6.7
#include "stdio.h"
#include "string.h"

int main()
{
    char word[15];
    printf("Enter a word:");
    scanf("%s",word);
    unsigned long n =strlen(word);
    for(unsigned long i=0;i<n;i++)
    {
        printf("%c",word[n-i-1]);
    }
    printf("\n");
    
    return 0;
}

//6.8
#include "stdio.h"

int main()
{
    float a,b;
    printf("Please enter 2 numbers:");
    int x = scanf("%f %f",&a,&b);
    while (x == 2)
    {
        printf("%f\n",(a-b)/(a*b));
        printf("Please enter 2 number:");
        x = scanf("%f %f",&a,&b);
    }
    
    return 0;
}

//6.9
#include "stdio.h"

float calculate(float a,float b)
{
    return (a-b)/(a*b);
}

int main()
{
    float a,b;
    printf("Please enter 2 numbers:");
    int x = scanf("%f %f",&a,&b);
    while (x == 2)
    {
        printf("%f\n",calculate(a, b));
        printf("Please enter 2 numbers:");
        x = scanf("%f %f",&a,&b);
    }
    
    return 0;
}

//6.10
#include "stdio.h"

int main()
{
    int a,b;
    printf("Enter lower and upper integer limits:");
    scanf("%d %d",&a,&b);
    while (a<b)
    {
        int s = 0;
        for (int i=a;i<=b;i++)
        {
            s += i*i;
        }
        printf("The sums of the squares from %d to %d is %d\n",a*a,b*b,s);
        printf("Enter lower and upper integer limits:");
        scanf("%d %d",&a,&b);
    }
    printf("Done.\n");
    
    return 0;
}

//2019/7/12
//6.11
#include "stdio.h"

int main()
{
    int x[8],y;
    for (int i=0;i<8;i++)
    {
        printf("Enter:");
        scanf("%d",&y);
        x[i] = y;
    }
    for (int i=7;i>=0;i--)
    {
        printf("%d ",x[i]);
    }
    printf("\n");
    
    return 0;
}

//6.12
#include "stdio.h"
#include "math.h"

int main()
{
    float x,y,n,s=0,r=0;
    printf("Enter:");
    scanf("%f",&n);
    for (x=1;x<=n;x++)
    {
        y = 1.0/x;
        s += y;
        r += pow(-1,x+1)*y;
    }
    printf("%f %f\n",s,r);
    
    return 0;
}

//6.13
#include "stdio.h"

int main()
{
    int x[8],y=1,j=0;
    for (int i=0;i<8;i++)
    {
        y *= 2;
        x[i] = y;
    }
    do
    {
        printf("%d ",x[j++]);
    }
    while (j<8);
    printf("\n");
    
    return 0;
}

//6.14
#include "stdio.h"

int main()
{
    double a[8],b[8],t,s=0;
    for (int i=0;i<8;i++)
    {
        printf("Enter:");
        scanf("%lf",&t);
        s += t;
        a[i] = t;
        b[i] = s;
    }
    for (int i=0; i<8; i++)
    {
        printf("%-6.2lf",a[i]);
    }
    printf("\n");
    for (int i=0; i<8; i++)
    {
        printf("%-6.2lf",b[i]);
    }
    printf("\n");
    
    return 0;
}

//倒序打印
//6.15
#include "stdio.h"

int main()
{
    char str[255],x;
    int i = 0;
    printf("Enter:");
    scanf("%c",&x);
    while (x!='\n')
    {
        str[i++]=x;
        scanf("%c",&x);
    }
    for (int j=i-1;j>=0;j--)
    {
        printf("%c",str[j]);
    }
    printf("\n");
    
    return 0;
}

//6.16
#include "stdio.h"

int main()
{
    float Daphne=100,Deirdre=100,i=0;
    while (Daphne>=Deirdre)
    {
        Daphne += 100*0.1;
        Deirdre *= (1+0.05);
        i++;
    }
    printf("%.0f\n",i);
    
    return 0;
}

//6.17
#include "stdio.h"

int main()
{
    float Chuckie = 100;
    int i = 0;
    while (Chuckie>0)
    {
        Chuckie *= 1.08;
        Chuckie -= 10;
        i++;
    }
    printf("%d\n",i);
    
    return 0;
}

//6.18
#include "stdio.h"

int main()
{
    int Rabnud = 5,Dunbar = 150,i=0;
    while (Rabnud<=Dunbar)
    {
        Rabnud -= 1;
        Rabnud *= 2;
        i++;
        printf("Rabnud has %d friends in the %dth week.\n",Rabnud,i);
    }
    
    return 0;
}

//unit 7
//2019/7/16
//7.1

#include "stdio.h"
#include "ctype.h"
#define STOP '#'

int main()
{
    char ch;
    int enter_num = 0,space_num = 0,other_num = 0;
    printf("Please enter:");
    while ((ch=getchar())!=STOP)
    {
        switch (ch)
        {
            case '\n':
                enter_num++;
                break;
            case ' ':
                space_num++;
                break;
                
            default:
                other_num++;
                break;
        }
    }
    printf("ENTER = %d\nSPACE = %d\nOTHER = %d\n",enter_num,space_num,other_num);
    
    return 0;
}

//7.2
#include "stdio.h"
#include "ctype.h"
#define STOP '#'

int main()
{
    char ch;
    int i=0;
    printf("Enter:");
    while ((ch=getchar())!=STOP)
    {
        i++;
        if (i%8!=0)
            printf("%-2c%-4d",ch,ch);
        else
            printf("\n");
    }
    printf("\n");
    
    return 0;
}

//7.3
#include "stdio.h"

int main()
{
    int num,even_num = 0,odd_num = 0,even_sum = 0,odd_sum = 0;
    float even_average,odd_average;
    printf("Enter:");
    while (scanf("%d",&num) == 1)
    {
        if (num == 0)
            break;
        else if (num%2 == 0)
        {
            even_num++;
            even_sum += num;
        }
        else
        {
            odd_num++;
            odd_sum += num;
        }
    }
    even_average = even_sum/even_num;
    odd_average = odd_sum/odd_num;
    printf("Even:%d %.2f\nOdd:%d %.2f",even_num,even_average,odd_num,odd_average);
    
    return 0;
}

//7.4
#include "stdio.h"
#include "ctype.h"
#define STOP '#'

int main()
{
    char ch;
    int num = 0;
    printf("Enter:");
    while ((ch = getchar()) != STOP)
    {
        if (ch == '.')
        {
            printf("!");
            num++;
        }
        else if (ch == '!')
        {
            printf("!!");
            num++;
        }
        else
            printf("%c",num);
    }
    printf("Num:%d\n",num);
    
    return 0;
}

//7.4
#include "stdio.h"
#include "ctype.h"
#define STOP '#'

int main()
{
    char ch;
    int num = 0;
    printf("Enter:");
    while ((ch = getchar()) != STOP)
    {
        switch (ch)
        {
            case '.':
                putchar('!');
                num++;
                break;
            case '!':
                putchar('!');
                putchar('!');
                num++;
                break;
            default:
                putchar(ch);
                break;
        }
    }
    printf("Num:%d\n",num);
    
    return 0;
}

//2019/7/17
//7.5
#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"
#define STOP '#'

int main()
{
    char ch;
    int num=0;
    bool ei = false;
    printf("Enter:");
    while ((ch = getchar()) != STOP)
    {
        if ((ch == 'e')&&!ei)
            ei = true;
        else if ((ch == 'i')&&ei)
        {
            num++;
            ei = false;
        }
        else
            ei = false;
    }
    printf("%d\n",num);
    
    return 0;
}

//7.6
#include "stdio.h"
#include "ctype.h"
#define STOP '#'

int main()
{
    char ch;
    char prev = '\n';
    int num = 0;
    printf("Enter:");
    while ((ch = getchar()) != STOP)
    {
        if ((ch == 'i')&&(prev == 'e'))
            num++;
        prev = ch;
    }
    printf("%d\n",num);
    
    return 0;
}

//7.7
#include "stdio.h"
#define wage 10
#define overtime_break 40
#define overtime_rate 1.5
#define BREAK1 300
#define RATE1 0.15
#define BREAK2 450
#define RATE2 0.20
#define RATE3 0.25
#define BASE1 BREAK1*RATE1
#define BASE2 (BREAK2-BREAK1)*RATE2+BASE1

int main()
{
    float hour,sum,tax,income;
    printf("How many hours?\n");
    scanf("%f",&hour);
    if (hour>40)
        hour = (hour-overtime_break)*overtime_rate+overtime_break;
    sum = hour*wage;
    if (sum<=300)
        tax = sum*RATE1;
    else if ((sum>300)&&(sum<=450))
        tax = BASE1+(sum-BREAK1)*RATE2;
    else
        tax = BASE2+(sum-BREAK2)*RATE3;
    income = sum-tax;
    printf("SUM:%.2f\nTAX:%.2f\nINCOME:%.2f\n",sum,tax,income);
    
    return 0;
}

//7.8
#include "stdio.h"
#include "ctype.h"
#define overtime_break 40
#define overtime_rate 1.5
#define BREAK1 300
#define RATE1 0.15
#define BREAK2 450
#define RATE2 0.20
#define RATE3 0.25
#define BASE1 BREAK1*RATE1
#define BASE2 (BREAK2-BREAK1)*RATE2+BASE1

void money(float (wage))
{
    printf("How many hours?\n");
    float hour,sum,tax,income;
    scanf("%f",&hour);
    if (hour>40)
        hour = (hour-overtime_break)*overtime_rate+overtime_break;
    sum = hour*wage;
    if (sum<=300)
        tax = sum*RATE1;
    else if ((sum>300)&&(sum<=450))
        tax = BASE1+(sum-BREAK1)*RATE2;
    else
        tax = BASE2+(sum-BREAK2)*RATE3;
    income = sum-tax;
    printf("SUM:%.2f\nTAX:%.2f\nINCOME:%.2f\n\n",sum,tax,income);
}

void print()
{
    printf("Enter the number corresponding to the desire pay rate or action:\n");
    printf("1) $8.75/hr       2) $9.33/hr\n");
    printf("3) $10.00/hr      4) $11.20/hr\n");
    printf("5) quit\n");
}

int main()
{
    char choice;
    float wage;
    print();
    while ((choice = getchar()) != '5')
    {
        switch (choice)
        {
            case '1':
                wage = 8.75;
                money(wage);
                break;
            case '2':
                wage = 9.33;
                money(wage);
                break;
            case '3':
                wage = 10.00;
                money(wage);
                break;
            case '4':
                wage = 11.20;
                money(wage);
                break;
            default:
                printf("Wrong!\n\n");
                break;
        }
        while (getchar() != '\n')
            continue;
        print();
    }
    
    return 0;
}

//7.9
#include "stdio.h"
#include "stdbool.h"

void prime(int i);

int main()
{
    int num;
    printf("Enter:");
    if ((scanf("%d",&num) == 1)&&(num > 0))
    {
        for (int i = 1;i <=num;i++)
            prime(i);
    }
    else
        printf("Wrong!\n");
    printf("\n");
    
    return 0;
}

void prime(int i)
{
    int k =0;
    for (int j = 1;j*j <= i;j++)
    {
        if (i%j ==0)
            k++;
    }
    if ((k == 1)&&(i !=1))
        printf("%d ",i);
}

//7.10
#include "stdio.h"
#define RATE1 0.15
#define RATE2 0.28
#define BREAK1 17850
#define BREAK2 23900
#define BREAK3 29750
#define BREAK4 14875

float TAX(int BREAK)
{
    float salary;
    printf("How much salary do you take?\n");
    scanf("%f",&salary);
    if (salary > BREAK)
        return (salary-BREAK)*RATE2+BREAK*RATE1;
    else
        return salary*RATE1;
}

int main()
{
    char kind;
    float tax;
    printf("Which kind?\n");
    while ((kind = getchar()) != '#')
    {
        switch (kind)
        {
            case '1':
                tax = TAX(BREAK1);
                printf("TAX = %f\n",tax);
                break;
            case '2':
                tax = TAX(BREAK2);
                printf("TAX = %f\n",tax);
                break;
            case '3':
                tax = TAX(BREAK3);
                printf("TAX = %f\n",tax);
                break;
            case '4':
                tax = TAX(BREAK4);
                printf("TAX = %f\n",tax);
                break;
            default:
                printf("Wrong!\n");
        }
        while (getchar() != '\n')
            continue;
        printf("\nWhich kind?\n");
    }
    
    return 0;
}

//7.11
#include "stdio.h"
#define price_artichoke 2.05
#define price_beet 1.15
#define price_carrot 1.09
#define discount_value 0.05
#define discount_break 100
#define trans_break1 5
#define trans_break2 20
#define trans_fee1 6.5
#define trans_fee2 14
#define trans_rate 0.5

int main()
{
    char kind;
    float pound_artichoke = 0,pound_beet = 0,pound_carrot = 0,pound;
    printf("Which kind of vegetable would you like?\n");
    while ((kind = getchar()) != 'q')
    {
        switch (kind)
        {
            case 'a':
                printf("How many pounds of artichoke do you want?\n");
                pound_artichoke += scanf("%f",&pound);
                break;
            case 'b':
                printf("How many pounds of beet do you want?\n");
                pound_beet += scanf("%f",&pound);
                break;
            case 'c':
                printf("How many pounds of carrot do you want?\n");
                pound_carrot += scanf("%f",&pound);
                break;
            default:
                printf("Wrong!\n");
                break;
        }
        while (getchar() != '\n')
            continue;
        printf("Which kind of vegetable would you like?\n");
    }
    
    float cost_artichoke = pound_artichoke*price_artichoke;
    float cost_beet = pound_beet*price_beet;
    float cost_carrot = pound_carrot*price_carrot;
    float total_cost = cost_artichoke+cost_beet+cost_carrot;
    
    float discount,trans;
    if (total_cost >= discount_break)
    {
        discount = discount_value*total_cost;
    }
    else
        discount = 0;
    
    float total_pound = pound_artichoke+pound_beet+pound_carrot;
    if (total_pound <= trans_break1)
        trans = trans_fee1;
    else if (total_pound <= trans_break2)
        trans = trans_fee2;
    else
        trans = trans_break2+(total_pound-trans_break2)*trans_rate;
    
    float fee = total_cost - discount +trans;
    printf("Artichoke price:%3.2f pound:%3.1f cost:%5.2f\n",price_artichoke,pound_artichoke,cost_artichoke);
    printf("Beet      price:%3.2f pound:%3.1f cost:%5.2f\n",price_beet,pound_beet,cost_beet);
    printf("Carrot    price:%3.2f pound:%3.1f cost:%5.2f\n",price_carrot,pound_carrot,cost_carrot);
    printf("Total cost:%6.2f Discount:%6.2f Trans:%6.2f\n",total_cost,discount,trans);
    printf("Final cost:%6.2f\n",fee);
    
    return 0;
}

//unit 8
//2019/7/21
//8.1
#include "stdio.h"

int main()
{
    char ch;
    int i = 0;
    printf("Enter:");
    while ((ch = getchar()) != EOF)
    {
        i++;
    }
    printf("%d\n",i);
    
    return 0;
}

//8.3
#include "stdio.h"
#include "ctype.h"

int main()
{
    char ch;
    int I = 0,i= 0;
    printf("Enter:");
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            i++;
        else if (isupper(ch))
            I++;
        else
            continue;
    }
    printf("Supper:%d\nLower:%d\n",I,i);
    
    return 0;
}

//8.2
#include "stdio.h"

int main()
{
    char ch;
    int i = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch >= ' ')
        {
            printf("%c %d ",ch,ch);
            i++;
            
        }
        else if (ch == '\n')
        {
            printf("\\n %d ",ch);
            i++;
            
        }
        else if (ch == '\t')
        {
            printf("\\t %d ",ch);
            i++;
        }
        else
        {
            printf("^%c %d ",ch+64,ch);
            i++;
        }
        if (i%10 ==0)
            printf("\n");
    }
    printf("\n");
    
    return 0;
}

//8.4
#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"

int main()
{
    char ch;
    float num_word = 0,num_alpha = 0;
    bool word = false;
    printf("Enter:");
    while ((ch = getchar()) != EOF)
    {
        if (isalpha(ch)&&!word)
        {
            word = true;
            num_word++;
            num_alpha++;
        }
        else if (isalpha(ch)&&word)
            num_alpha++;
        else if (!isalpha(ch)&&word)
            word = false;
        else
            continue;
    }
    float k = num_alpha/num_word;
    printf("Average:%f\n",k);
    
    return 0;
}

//检测字符
int Detecting_characters(char ch)
{
    if (ch >= ' ')
    {
        printf("%c %d ",ch,ch);
        
    }
    else if (ch == '\n')
    {
        printf("\\n %d ",ch);
    }
    else if (ch == '\t')
    {
        printf("\\t %d ",ch);
    }
    else
    {
        printf("^%c %d ",ch+64,ch);
    }
    printf("\n");
    return 0;
}

//8.5
#include "stdio.h"
#include "ctype.h"

char ask(int num);
char get_first(void);
int Detecting_characters(char ch);

int main()
{
    int num = 50;
    int min = 0,max = 100;
    char ch = ask(num);
    while (ch != 'c')
    {
        if (ch == 'a')
        {
            max = num;
            num = (min+max)/2;
        }
        else
        {
            min = num;
            num = (min+max)/2;
        }
        ch = ask(num);
    }
    printf("The number is %d, I know I can do it!\n",num);
    
    return 0;
}

char ask(int num)
{
    char ch;
    printf("Is the number %d?\n",num);
    printf("If it is bigger than the number, enter 'a'.\n"
           "If it is smaller than the number, enter 'b'.\n"
           "IF it is the right number, enter 'c'.\n");
    ch = get_first();
    switch (ch)
    {
        case 'a':
            return 'a';
            break;
        case 'b':
            return 'b';
            break;
        case 'c':
            return 'c';
            break;
        default:
            printf("Wrong!Try again:\n");
            return(ask(num));
            break;
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
*/
//2019/7/22
//8.8
#include "stdio.h"
#include "ctype.h"

void menu(void);
char get_first(void);
float get_first_num(void);
float get_second_num(void);
float get_second_num_divide(void);

int main()
{
    menu();
    char ch = get_first();
    float first_num,second_num;
    while (ch != 'q')
    {
        switch (ch)
        {
            case 'a':
                first_num = get_first_num();
                second_num = get_second_num();
                printf("%.2f + %.2f = %.2f\n",first_num,second_num,first_num+second_num);
                break;
            case 's':
                first_num = get_first_num();
                second_num = get_second_num();
                printf("%.2f - %.2f = %.2f\n",first_num,second_num,first_num-second_num);
                break;
            case 'm':
                first_num = get_first_num();
                second_num = get_second_num();
                printf("%.2f * %.2f = %.2f\n",first_num,second_num,first_num*second_num);
                break;
            case 'd':
                first_num = get_first_num();
                second_num = get_second_num_divide();
                printf("%.2f / %.2f = %.2f\n",first_num,second_num,first_num/second_num);
                break;
            default:
                printf("Wrong!Try again:\n");
                break;
        }
        menu();
        ch = get_first();
    }
    printf("Bye.\n");
    
    return 0;
}

void menu(void)
{
    printf("Enter the operation of your choice:\n"
           "a. add            s. subtract\n"
           "m. multiply       d. divide\n"
           "q. quit\n");
}

char get_first(void)
{
    char ch;
    ch = getchar();
    while (isblank(ch))
        ch = getchar();
    while (getchar() != '\n')
        continue;
    
    return ch;
}

float get_first_num(void)
{
    float num;
    printf("Enter first number:");
    if (scanf("%f",&num) == 1)
    {
        while (getchar() != '\n');
        return num;
    }
    else
    {
        printf("It is not a number!Try again.\n");
        while (getchar() != '\n');
        return get_first_num();
    }
}

float get_second_num(void)
{
    float num;
    printf("Enter second number:");
    if (scanf("%f",&num) == 1)
    {
        while (getchar() != '\n');
        return num;
    }
    else
    {
        printf("It is not a number!Try again.\n");
        while (getchar() != '\n');
        return get_second_num();
    }
}

float get_second_num_divide(void)
{
    float num;
    printf("Enter second number:");
    if (scanf("%f",&num) == 1)
    {
        if (num == 0)
        {
            printf("Enter a number other than 0.");
            return get_second_num_divide();
        }
        else
        {
            while (getchar() != '\n');
            return num;
        }
    }
    else
    {
        printf("It is not a number!Try again.\n");
        while (getchar() != '\n');
        return get_second_num_divide();
    }
}
