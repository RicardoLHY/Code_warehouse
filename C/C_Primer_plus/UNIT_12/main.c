//
//  main.c
//  UNIT_12
//
//  Created by 李环宇 on 2019/9/17.
//  Copyright © 2019 Li Huanyu. All rights reserved.
//


//2019/9/17
//12.1
// global.c  -- uses an external variable
#include <stdio.h>
void critic(int *);
int main(void)
{
    static int units;  // an optional redeclaration
    int* pt = &units;
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while ( units != 56)
        critic(pt);
    printf("You must have looked it up!\n");
    
    return 0;
}

void critic(int* pt)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d", pt);
}


//2019/9/18
//12.2
//12.3

//12.4
#include <stdio.h>

int returnCalls(void)
{
    static int n = 0;
    n++;
    
    return n;
}

int main()
{
    int n = 0;
    for (int i = 0;i < 100;i++)
        n = returnCalls();
    printf("Return %d calls.\n",n);
    
    return 0;
}



//2019/9/19
//12.5
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,temp,max;
    int array[100];
    for (int i = 0;i < 100;i++)
    {
        num = rand()%10 + 1;
        array[i] = num;
    }
    for (int i = 0;i < 99;i++)
    {
        max = array[i];
        int z = i;
        for (int j = i;j < 100;j++)
        {
            if (array[j] > max)
            {
                max = array[j];
                z = j;
            }
        }
        temp = array[i];
        array[i] = array[z];
        array[z] = temp;
    }
    for (int i = 0;i < 100; i++)
        printf("%d\n",array[i]);
 
 return 0;
}


//12.6
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int seed,num;
    int array[10] = {0,0,0,0,0,0,0,0,0,0};
    printf("Enter seed:");
    scanf("%d",&seed);
    srand(seed);
    for (int i = 0;i < 1000;i++)
    {
        num = rand()%10;
        array[num] += 1;
    }
    for (int i = 0; i < 10; i++)
        printf("%d\n",array[i]);
    
    return 0;
}


//12.7
#include <stdio.h>
#include <stdlib.h>

int getRandom(int sides,int dice,int i);
int getSets(void);

int main()
{
    int sets,sides,dice;
    printf("Enter the number of sets; enter q to stop:");
    while ((sets = getSets()) != -1)
    {
        printf("How many sides and how many dice? ");
        while (scanf("%d %d",&sides,&dice) != 2)
        {
            printf("Wrong!Try again.\n");
            scanf("%*s");
            printf("How many sides and how many dice? ");
        }
        printf("Here are %d sets of %d %d-sided throws.\n",sets,dice,sides);
        for (int i = 0;i < sets;i++)
        {
            printf("%4d",getRandom(sides, dice,i));
            if (i % 5 == 4)
                putchar('\n');
        }
        putchar('\n');
        printf("How many sets? Enter q to stop: ");
    }
    printf("Done.\n");
    
    return 0;
}

int getRandom(int sides,int dice,int i)
{
    srand(i);
    int a,s = 0;
    for (int i = 0;i < dice;i++)
    {
        a = rand() % sides + 1;
        s += a;
    }
    
    return s;
}

int getSets(void)
{
    int sets;
    if ((scanf("%d",&sets)) == 1)
        return sets;
    else if (getchar() == 'q')
        return -1;
    else
    {
        while (getchar() != '\n')
            continue;
        printf("Wrong!Try again.\n"
               "How many sets? Enter q to stop: ");
        return getSets();
    }
}


//12.8
#include <stdio.h>
#include <stdlib.h>

int* make_array(int elem,int val);
void show_array(const int ar[],int n);

int main(void)
{
    int* pa;
    int size;
    int value;
    printf("Enter the number of elements:");
    while (scanf("%d",&size) == 1 && size > 0)
    {
        printf("Enter the initialization value:");
        scanf("%d",&value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit):");
    }
    printf("Done.\n");
    
    return 0;
}

int* make_array(int elem,int val)
{
    int *pa = (int*)malloc(elem * sizeof(int));
    for (int i = 0;i < elem;i++)
        *pa++ = val;
    pa -= elem;
    
    return pa;
}

void show_array(const int ar[],int n)
{
    for (int i = 0;i < n;i++)
    {
        printf("%3d",ar[i]);
        if (i % 8 == 7)
            putchar('\n');
    }
    putchar('\n');
}


//12.9
//Error 1
#include <stdio.h>

int main()
{
    int word;
    printf("How many words do you wish to enter:");
    scanf("%d",&word);
    char** pt = (char**)malloc(word * sizeof(char*));
    printf("Enter %d words now:\n",word);
    for (int i = 0;i < word;i++)
    {
        int j = 0;
        char ch;
        char array[20];
        getchar();
        while (((ch = getchar()) != ' ') && ch != '\n')
            array[j++] = ch;
        char* ptr = (char*)malloc(j * sizeof(char));
        for (int k = 1;k < j;k++)
            *ptr++ = array[k-1];
        ptr -= j;
        pt[i] = ptr;
    }
    printf("Here are your words:\n");
    for (int i = 0;i < word;i++)
    {
        printf("%s",pt[i]);
        putchar('\n');
    }
    
    return 0;
}

//Error 2
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define LIMIT 81

void getWord(char** pt,int word);
void putWord(char** pt,int word);

int main()
{
    int word;
    printf("How many words do you wish to enter:");
    scanf("%d",&word);
    char** pt = (char**)malloc(word * sizeof(char*));
    getWord(pt,word);
    putWord(pt,word);
    free(pt);
    
    return 0;
}

void getWord(char** pt,int word)
{
    printf("Enter %d words now:\n",word);
    getchar();
    char array[LIMIT],ch;
    int num_letter[word];
    for (int i = 0;i < word;i++)
        num_letter[i] = 0;
    char* ptr = &array[0];
    int letter = 0,num_word = 0,num_alpha = 0;
    bool isword = false;
    while ((ch = getchar()) != '\n')
    {
        *ptr++ = ch;
        letter++;
        if (isalpha(ch) && !isword)
        {
            isword = true;
            num_word++;
            num_alpha++;
        }
        else if (isalpha(ch) && isword)
            num_alpha++;
        else if (!isalpha(ch) && isword)
        {
            isword = false;
            num_letter[num_word-1] = num_alpha;
            num_alpha = 0;
        }
        else
            continue;
    }
    ptr -= letter;
    for (int i = 0;i < word;i++)
    {
        char* array = (char*)malloc(num_letter[i]*sizeof(char));
        *array = *ptr;
        array++;
        ptr++;
        array -= num_letter[i];
        *pt++ = array;
        while (!isalpha(*ptr) && *ptr != '\n')
            ptr++;
    }
    pt -= word;
}

void putWord(char** pt,int word)
{
    printf("Here are your words:\n");
    for (int i = 0;i < word;i++)
    {
        char* ptr = *pt++;
        while (isalpha(*ptr))
        {
            putchar((int)*ptr);
            ptr++;
        }
        putchar('\n');
    }
}


//Right
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <stdbool.h>
 #define LIMIT 15
 
 void getWord(char** pt,int word);
 void putWord(char** pt,int word);
char* getArray(char* array,int num_alpha);
 
 int main()
 {
     int word;
     printf("How many words do you wish to enter:");
     scanf("%d",&word);
     char** pt = (char**)malloc(word * sizeof(char*));
     getWord(pt,word);
     putWord(pt,word);
     free(pt);
 
     return 0;
 }

void getWord(char** pt,int word)
{
    printf("Enter %d words now:\n",word);
    char array[LIMIT],ch;
    for (int i = 0;i < LIMIT;i++)
        array[i] = 0;
    int num_alpha = '\0';
    bool isword = false;
    while (getchar() != '\n')
        continue;
    while (true)
    {
        ch = getchar();
        if (isalpha(ch) && !isword)
        {
            isword = true;
            array[num_alpha] = ch;
            num_alpha++;
        }
        else if (isalpha(ch) && isword)
        {
            array[num_alpha] = ch;
            num_alpha++;
        }
        else if (!isalpha(ch) && isword)
        {
            isword = false;
            *pt++ = getArray(array,num_alpha);
            num_alpha = 0;
            for (int i = 0;i < LIMIT;i++)
                array[i] = 0;
        }
        else
            continue;
        if (ch == '\n')
            break;
    }
    pt -= word;
}

void putWord(char** pt,int word)
{
    printf("Here are your words:\n");
    for (int i = 0;i < word;i++)
    {
        char* str = *pt;
        while (isalpha(*str))
        {
            putchar(*str);
            str++;
        }
        putchar('\n');
        free(*pt);
        pt++;
    }
}

char* getArray(char* array,int num_alpha)
{
    char* str = (char*)malloc(num_alpha * sizeof(char));
    for (int i = 0;i < num_alpha;i++)
        str[i] = array[i];
    
    return str;
}
