//
//  main.c
//  UNIT_11
//
//  Created by 李环宇 on 2019/9/2.
//  Copyright © 2019 Li Huanyu. All rights reserved.
//


//2019/9/2
//11.1
#include <stdio.h>
#define LIMIT 10

char* getInput(char* array,int n)
{
    int i;
    int ch;
    for(i = 0;i < n;i++)
    {
        ch = getchar();
        if (ch != EOF)
            array[i] = ch;
        else
            break;
    }
    if (ch == EOF)
        return NULL;
    else
    {
        array[i] = '\0';
 
    return array;
    }
}

int main()
{
    char Input[LIMIT];
    char* ct = getInput(Input,LIMIT-1);
    puts(ct);
 
    return 0;
}


//11.2
#include <stdio.h>
#define LIMIT 81

char* getInput(char* array,int n)
{
    int i;
    int ch;
    for(i = 0;i < n;i++)
    {
        ch = getchar();
        if ((ch != ' ')&&(ch != '\n')&&(ch != '\t'))
            array[i] = ch;
        else
            break;
    }
    array[i+1] = '\0';
 
    return array;
}

int main()
{
    int n;
    char Input[LIMIT];
    printf("Please enter n:");
    n = getchar();
    while (getchar() != '\n')
        continue;
    char* ct = getInput(Input,n);
    fputs(ct,stdout);
 
    return 0;
}


//11.3
#include <stdio.h>
#include <ctype.h>
#define LIMIT 10

char* word(char array[])
{
    char ch;
    int i;
    while (isspace(ch = getchar()))
        continue;
    for (i = 0;i < LIMIT;i++)
    {
        array[i] = ch;
        if (isspace(ch = getchar()))
            break;
    }
    array[i+1] = '\0';
 
    return array;
}

int main()
{
    char array[LIMIT];
    char* ct = word(array);
    fputs(ct,stdout);
    putchar('\n');
 
    return 0;
}

//11.4
#include <stdio.h>
#include <ctype.h>
#define LIMIT 81

char* word(char array[],int n)
{
    char ch;
    int i;
    while (isspace(ch = getchar()))
        continue;
    for (i = 0;i < n-1;i++)
    {
        array[i] = ch;
        if (isspace(ch = getchar()))
            break;
    }
    array[i] = '\0';
 
    return array;
}

int main()
{
    char array[LIMIT];
    int n = 10;
    char* ct = word(array,n+1);
    fputs(ct,stdout);
    putchar('\n');
 
    return 0;
}
 

//11.5
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LIMIT 81

char* searchCharacter(char* str,char ch)
{
    unsigned long n = strlen(str);
    char* pt = &str[0];
    bool BOOL = false;
    for (int i = 0;i < n;i++)
    {
        if (*pt == ch)
        {
            BOOL = true;
            break;
        }
        pt++;
    }
    if (BOOL)
        return pt;
    else
        return NULL;
}

char* getStr(char* str)
{
    int i = 0;
    char ch;
    printf("Please enter a string:");
    while ((ch = getchar()) != '\n')
    {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    
    return str;
}

char getChar(void)
{
    char ch;
    printf("Please enter a char:");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    
    return ch;
}

bool whetherToContinue(void)
{
    char ch;
    printf("Enter Y to continue, or N to stop.\n");
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    if (ch == 'Y')
        return true;
    else if (ch == 'N')
    {
        printf("Done.\n");
        return false;
    }
    else
    {
        printf("Wrong!Try again.\n");
        return whetherToContinue();
    }
}

int main()
{
    char str[LIMIT];
    char ch;
    bool ToContinue = true;
    while (ToContinue)
    {
        getStr(str);
        ch = getChar();
        char* pt = searchCharacter(str, ch);
        if (pt == NULL)
            printf("The specified character was not found!\n");
        else
            printf("Found!No.%ld\n",(pt-str)+1);
        ToContinue = whetherToContinue();
    }
    
    return 0;
}


//
// 11.6
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LIMIT 81

bool searchCharacter(char* str,char ch)
{
    unsigned long n = strlen(str);
    char* pt = &str[0];
    bool BOOL = false;
    for (int i = 0;i < n;i++)
    {
        if (*pt == ch)
        {
            BOOL = true;
            break;
        }
        pt++;
    }
    return BOOL;
}

char* getStr(char* str)
{
    int i = 0;
    char ch;
    printf("Please enter a string:");
    while ((ch = getchar()) != '\n')
    {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';
    
    return str;
}

char getChar(void)
{
    char ch;
    printf("Please enter a char:");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    
    return ch;
}

bool whetherToContinue(void)
{
    char ch;
    printf("Enter Y to continue, or N to stop.\n");
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    if (ch == 'Y')
        return true;
    else if (ch == 'N')
    {
        printf("Done.\n");
        return false;
    }
    else
    {
        printf("Wrong!Try again.\n");
        return whetherToContinue();
    }
}

int main()
{
    char str[LIMIT];
    char ch;
    bool ToContinue = true;
    while (ToContinue)
    {
        getStr(str);
        ch = getChar();
        bool pt = searchCharacter(str, ch);
        if (!pt)
            printf("The specified character was not found!\n");
        else
            printf("Found!\n");
        ToContinue = whetherToContinue();
    }
    
    return 0;
}


//2019/9/4
//11.7
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define LIMIT 81

int firsr_second = 0;

char* mystrncpy(char* s1,char* s2,int n)
{
    char* pt = &s1[0];
    while (*pt != '\0')
        pt++;
    for (int i = 0;i < n;i++)
    {
        *pt = s2[i];
        pt++;
        if (s2[i] == '\0')
            break;
        if ((i == n-1) && (s2[i] != '\0'))
            *pt = '\0';
    }
    
    return s1;
}

char* getStr(char* str)
{
    char ch;
    char* pt = &str[0];
    if (firsr_second == 0)
        printf("Enter the first string:");
    else
        printf("Enter the second string:");
    firsr_second++;
    while ((ch = getchar()) != '\n')
    {
        *pt = ch;
        pt++;
    }
    *pt = '\0';
    
    return str;
}

int get_n(void)
{
    int n;
    printf("n:");
    if (scanf("%d",&n) != 1)
    {
        printf("Wrong!Try again.\n");
        scanf("%*s");
        return get_n();
    }
    else
        return n;
}

bool trueOrFalse(void)
{
    printf("Go on?(Enter Y or N):");
    char ch;
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    if (ch == 'Y')
        return true;
    else if (ch == 'N')
    {
        printf("Done.\n");
        return false;
    }
    else
    {
        printf("Wrong!Try again.\n");
        return trueOrFalse();
    }
}

int main()
{
    char str1[LIMIT];
    char str2[LIMIT];
    bool tof;
    int n;
    do
    {
        getStr(str1);
        getStr(str2);
        n = get_n();
        mystrncpy(str1, str2, n);
        fputs(str1, stdout);
        putchar('\n');
        tof = trueOrFalse();
    }while (tof);
    return 0;
}


 //11.8
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define LIMIT 81

int firsr_second = 0;

char* string_in(char* str1,char* str2)
{
    char* pt;
    int i;
    A:i = 0;
    while (*str1 != *str2)
    {
        str1++;
        if (*str1 == '\0')
            return NULL;
    }
    pt =  str1;
    while(*str1 == *str2)
    {
        str1++;
        str2++;
        i++;
        if (*str2 == '\0')
        {
            printf("%c",*pt);
            return pt;
        }
    }
    str2 = str2 - i;
    goto A;
}

char* getStr(char* str)
{
    char ch;
    char* pt = &str[0];
    if (firsr_second == 0)
        printf("Enter the first string:");
    else
        printf("Enter the second string:");
    firsr_second++;
    while ((ch = getchar()) != '\n')
    {
        *pt = ch;
        pt++;
    }
    *pt = '\0';
    
    return str;
}

bool trueOrFalse(void)
{
    printf("Go on?(Enter Y or N):");
    char ch;
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    if (ch == 'Y')
        return true;
    else if (ch == 'N')
    {
        printf("Done.\n");
        return false;
    }
    else
    {
        printf("Wrong!Try again.\n");
        return trueOrFalse();
    }
}

int main()
{
    char str1[LIMIT];
    char str2[LIMIT];
    char* pt = NULL;
    bool tof;
    do
    {
        getStr(str1);
        getStr(str2);
        pt = string_in(str1,str2);
        if (pt != NULL)
            printf("%p\n%c\n",pt,*pt);
        else
            printf("NULL\n");
        tof = trueOrFalse();
    }while (tof);
    
    return 0;
}


//11.9
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define LIMIT 81

void reverseOrder(char* str)
{
    int i = 0;
    while (*str != '\0')
    {
        str++;
        i++;
    }
    while (i != 0)
    {
        str--;
        putchar(*str);
        i--;
    }
    putchar('\n');
}

char* getStr(char* str)
{
    char ch;
    char* pt = &str[0];
    printf("Enter the string:");
    while ((ch = getchar()) != '\n')
    {
        *pt = ch;
        pt++;
    }
    *pt = '\0';
    
    return str;
}

bool trueOrFalse(void)
{
    printf("Go on?(Enter Y or N):");
    char ch;
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    if (ch == 'Y')
        return true;
    else if (ch == 'N')
    {
        printf("Done.\n");
        return false;
    }
    else
    {
        printf("Wrong!Try again.\n");
        return trueOrFalse();
    }
}

int main()
{
    char str[LIMIT];
    getStr(str);
    reverseOrder(str);
    
    return 0;
}


//11.10
#include <stdio.h>
#include <stdbool.h>
#define LIMIT 81

char* deleteSpace(char* str)
{
    char* head = NULL;
    char* pt = NULL;
    head = pt = str;
    while (*pt++)
    //优先级:先解引用，判断条件，然后移动指针
    {
        if (*pt != ' ')
        {
            *str++ = *pt;
            //优先级：先赋值，再移动指针
        }
    }
    *str = '\0';
    
    return head;
}

char* getStr(char* str)
{
    while ((*str = getchar()) != '\n')
        str++;
    *str = '\0';
    
    return str;
}

int main()
{
    char str[LIMIT];
    while (true)
    {
        printf("Enter:");
        getStr(str);
        if (*str == '\0')
            break;
        deleteSpace(str);
        printf("%s\n",str);
    }
    
    return 0;
}


//2019/9/6
//11.11
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define ROW 10
#define COL 81

char** getStr(char str[ROW][COL]);
void printStr(char str[ROW][COL]);
void printBy(char str[ROW][COL],int n);
int firstWord(char* pt);
char menu(void);
char str[ROW][COL];

int main()
{
    bool trueOrFalse = true;
    char ch;
    do
    {
        getStr(str);
        ch = menu();
        switch (ch)
        {
            case 'a':
                printStr(str);
                break;
            case 'b':
                printBy(str,1);
                break;
            case 'c':
                printBy(str,2);
                break;
            case 'd':
                printBy(str,3);
                break;
            default:
                printf("Done.\n");
                trueOrFalse = false;
                break;
        }
    }while (trueOrFalse);
    
    return 0;
}

char** getStr(char str[ROW][COL])
{
    for (int i = 0;i < ROW;i++)
    {
        char* pt = *(str + i);
        printf("Enter ROW %d:",i);
        while (((*pt = getchar()) != '\n') && (*pt != EOF))
            pt++;
        if (*pt == EOF)
            break;
        *pt = '\0';
    }
    
    return str;
    //Incompatible pointer types returning 'char (*)[81]' from a function with result type 'char **'
    //改成return 0；就不标黄
    //最简单的方法：把所有返回数组的函数声明成void；
}

void printStr(char str[ROW][COL])
{
    putchar('\n');
    printf("Source string list:\n");
    for (int i = 0;i < ROW;i++)
    {
        for (int j = 0;j < COL;j++)
            putchar(str[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void printBy(char str[ROW][COL],int n)
{
    char *pt[ROW];
    for (int i = 0;i < ROW;i++)
        pt[i] = str[i];
    for (int i = 0;i < ROW - 1;i++)
    {
        for(int j = i + 1;j < ROW;j++)
        {
            char* temp;
            if (n == 0)
            {
                char a = *pt[i];
                char b = *pt[j];
                if (a > b)
                {
                    temp = pt[i];
                    pt[i] = pt[j];
                    pt[j] = temp;
                }
            }
            else if (n == 1)
            {
                unsigned long a = strlen(pt[i]);
                unsigned long b = strlen(pt[j]);
                if (a > b)
                {
                    temp = pt[i];
                    pt[i] = pt[j];
                    pt[j] = temp;
                }
            }
            else
            {
                int a = firstWord(pt[i]);
                int b = firstWord(pt[j]);
                if (a > b)
                {
                    temp = pt[i];
                    pt[i] = pt[j];
                    pt[j] = temp;
                }
            }
        }
    }
    putchar('\n');
    if (n == 0)
        printf("String list printed by initials:\n");
    else if (n == 1)
        printf("Strings printed in increasing order of length:\n");
    else
        printf("String printed by the length of the first word:\n");
    for (int i = 0;i < ROW;i++)
    {
        while (*pt[i] != '\0')
        //不能写成while (*pt[i]++ != '\0')，这样指针就移动了
        {
            putchar(*pt[i]);
            pt[i]++;
        }
        putchar('\n');
    }
    putchar('\n');
}

int firstWord(char* pt)
{
    int n = 0;
    while (isspace(*pt))
        pt++;
    while (!isspace(*pt))
    {
        n++;
        pt++;
    }
    
    return n;
}

char menu(void)
{
    printf("Please enter a letter to choose:\n"
           "a: Print source string list.\n"
           "b: Print String list by initials.\n"
           "c: Print strings in increasing order of length.\n"
           "d: Print string by the length of the first word.\n"
           "q:Quiz.\n");
    char ch;
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    if ((ch != 'a')&&(ch != 'b')&&(ch != 'c')&&(ch != 'd')&&(ch != 'q'))
    {
        printf("Wrong!Try again.\n");
        return menu();
    }
    else
        return ch;
}


//11.12
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    int num_word = 0;
    int upper = 0,lower = 0,punct = 0,digit = 0;
    char ch,last_ch = ' ';
    while ((ch = getchar()) != EOF)
    {
        if ((!isalpha(last_ch)) && isalpha(ch))
            num_word++;
        if (isupper(ch))
            upper++;
        if (islower(ch))
            lower++;
        if (ispunct(ch))
            punct++;
        if (isdigit(ch))
            digit++;
        last_ch = ch;
    }
    printf("word = %d\nupper = %d\nlower = %d\npunct = %d\ndigit = %d\n",num_word,upper,lower,punct,digit);

    return 0;
}


//2019.9.9
//11.13
#include <stdio.h>

int main(int argc,char* argv[])
{
    for (int count = argc - 1;count > 0;count--)
        printf("%s ",argv[count]);
    putchar('\n');
    
    return 0;
}


//11.14
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
    double a = atof(argv[1]);
    double s = 1;
    int b = atoi(argv[2]);
    for (int i = 0;i < b;i++)
        s *= a;
    printf("%lf",s);
    putchar('\n');
    
    return 0;
}


//11.15
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int reAtoi(char *argv)
{
    int a,s = 0;
    while (*argv != '\0')
    {
        if (!isdigit(*argv))
            return 0;
        a = *argv - 48;
        s = s * 10 + a;
        argv++;
    }
    
    return s;
}

int main(int argc,char* argv[])
{
    double a = atof(argv[1]);
    double s = 1;
    int b = reAtoi(argv[2]);
    for (int i = 0;i < b;i++)
        s *= a;
    printf("%lf",s);
    putchar('\n');
    
    return 0;
}


//11.16
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(int argc,char* argv[])
{
    char ch;
    bool UPPER = false,LOWER = false;
    for (int i = argc - 1;i >= 0;i--)
    {
        if (!strcmp(argv[i], "-u"))//相同返回0
            UPPER = true;
        if (!strcmp(argv[i], "-l"))
            LOWER = true;
    }
    printf("Please enter:");
    while ((ch = getchar()) != EOF)
    {
        if ((UPPER) && (islower(ch)))
                ch = ch - 32;
        else if ((LOWER) && (isupper(ch)))
                ch = ch + 32;
        putchar(ch);
    }
    
    return 0;
}
