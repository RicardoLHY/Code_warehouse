/*
//Lesson 1
//2020/2/22
 01-复杂度1 最大子列和问题 (20分)
 给定K个整数组成的序列{ N1, N​2, ..., NK}，“连续子列”被定义为{ Ni, Ni+1, ..., Nj}，其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2}，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。

 本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

 数据1：与样例等价，测试基本正确性；
 数据2：102个随机整数；
 数据3：103个随机整数；
 数据4：104个随机整数；
 数据5：105个随机整数；
 输入格式:
 输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。

 输出格式:
 在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

 输入样例:
 6
 -2 11 -4 13 -5 -2

       
     
 输出样例:
 20
 Mycode:
#include <stdio.h>

int Sum(int[],int);

int main()
{
    int n,max;
    scanf("%d\n",&n);
    int *Array;
    Array = (int*)calloc(n,sizeof(int));
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&Array[i]);
    }
    max = Sum(Array,n);
    printf("%d",max);
}

int Sum(int Array[],int n)
{
    int ThisSum,MaxSum;
    ThisSum = MaxSum = 0;
    for (int i = 0;i < n;i++)
    {
        ThisSum += Array[i];
        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
        }
    }
    return MaxSum;
}

 01-复杂度2 Maximum Subsequence Sum (25分)
 Given a sequence of K integers { N​1, N2, ..., NK}. A continuous subsequence is defined to be
 { Ni, Ni+1, ..., Nj} where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

 Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

 Input Specification:
 Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

 Output Specification:
 For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

 Sample Input:
 10
 -10 1 2 3 4 -5 -23 3 7 -21

       
     
 Sample Output:
 10 1 4
 
 Mycode:
#include <stdio.h>
#include "stdbool.h"

void Sum(int[],int);

int main()
{
    int n;
    scanf("%d\n",&n);
    int *Array;
    Array = (int*)calloc(n,sizeof(int));
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&Array[i]);
    }
    Sum(Array,n);
}

void Sum(int Array[],int n)
{
    int ThisSum,MaxSum,First,Last,temp,numberOfZero,mark;
    bool No_negative = true;
    ThisSum = MaxSum = temp = 0;
    First = Array[0];
    Last = Array[n-1];
    numberOfZero = 0;
    mark = -1;
    for (int i = 0;i < n;i++)
    {
        ThisSum += Array[i];
        if (Array[i] > 0)
        {
            No_negative = false;
        }
        else if ((Array[i] == 0) && (numberOfZero == 0))
        {
            mark = i;
            numberOfZero++;
        }
        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            Last = Array[i];
            First = Array[temp];
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
            temp = i+1;
        }
    }
    if (No_negative && mark>=0)
    {
        First = Last = Array[mark];
    }
    printf("%d %d %d",MaxSum,First,Last);
}


//2020/2/23
 01-复杂度3 二分查找 (20分)
 本题要求实现二分查找算法。

 函数接口定义：
 Position BinarySearch( List L, ElementType X );

       
     
 其中List结构定义如下：

 typedef int Position;
 typedef struct LNode *List;
 struct LNode {
     ElementType Data[MAXSIZE];
     Position Last;  保存线性表中最后一个元素的位置
 };

       
     
 L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，并且题目保证传入的数据是递增有序的。
 函数BinarySearch要查找X在Data中的位置，即数组下标（注意：元素从下标1开始存储）。找到则返回下标，
 否则返回一个特殊的失败标记NotFound。

 裁判测试程序样例：
 #include <stdio.h>
 #include <stdlib.h>

 #define MAXSIZE 10
 #define NotFound 0
 typedef int ElementType;

 typedef int Position;
 typedef struct LNode *List;
 struct LNode {
     ElementType Data[MAXSIZE];
     Position Last;  保存线性表中最后一个元素的位置
 };

 List ReadInput();  裁判实现，细节不表。元素从下标1开始存储
 Position BinarySearch( List L, ElementType X );

 int main()
 {
     List L;
     ElementType X;
     Position P;

     L = ReadInput();
     scanf("%d", &X);
     P = BinarySearch( L, X );
     printf("%d\n", P);

     return 0;
 }

  你的代码将被嵌在这里

       
     
 输入样例1：
 5
 12 31 55 89 101
 31

       
     
 输出样例1：
 2

       
     
 输入样例2：
 3
 26 78 233
 31

       
     
 输出样例2：
 0
 //My code:
Position BinarySearch(List L,ElementType X)
{
    int first,middle,last;
    first = 1;
    last = L -> Last;
    if (first > last || last > MAXSIZE || X < L -> Data[first] || X > L -> Data[last])
    {
        return 0;
    }
    while (first <= last)
    {
        middle = (first + last) / 2;
        if (X == L ->Data[middle])
        {
            return middle;
        }
        else if (X > L ->Data[middle])
        {
            first = middle +1;
        }
        else
        {
            last = middle - 1;
        }
    }
    return NotFound;
}


//2020/3/23
//联合的用法
#include <stdio.h>

int main()
{
    union key
    {
        int k;
        char ch[2];
    }u;
    
    u.k = 258;
    printf("%d %d\n",u.ch[0],u.ch[1]);
}
