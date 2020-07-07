/*
 //Lesson9
 09-排序1 排序 (25分)
 给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。

 本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：

 数据1：只有1个元素；
 数据2：11个不相同的整数，测试基本正确性；
 数据3：10^3个随机整数；
 数据4：10^4个随机整数；
 数据5：10^5个随机整数；
 数据6：10^5个顺序整数；
 数据7：10^5个逆序整数；
 数据8：10^5个基本有序的整数；
 数据9：10^5个随机正整数，每个数字不超过1000。
 输入格式:
 输入第一行给出正整数N（≤10^5），随后一行给出N个（长整型范围内的）整数，其间以空格分隔。

 输出格式:
 在一行中输出从小到大排序后的结果，数字间以1个空格分隔，行末不得有多余空格。

 输入样例:
 11
 4 981 10 -17 0 -20 29 50 8 43 -5

       
     
 输出样例:
 -20 -17 -5 0 4 8 10 29 43 50 981


//2020/05/04
#include <stdio.h>
#include <stdbool.h>
#define MAX 100000

typedef int ElementType;
void bubbleSort(int*, int);//5,7,9超时(>10s)
void simpleSelectionSort(int*, int);//均不超时，56789为各5秒
void insertSort(int*, int);//均不超时,59为2.5秒，7为5秒

int main()
{
    ElementType *array;
    int N, i;
    
    scanf("%d\n", &N);
    array = (int*)malloc(N * sizeof(ElementType));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    insertSort(array, N);
    
    for (i = 0; i < N; i++)
    {
        printf("%d", array[i]);
        if (i != N-1)
        {
            putchar(' ');
        }
    }
}

void bubbleSort(int* array, int N)
{
    ElementType temp;
    int i, j;
    bool flag;
    
    for (i = N-1; i >= 0; i--)
    {
        flag = false;
        for (j = 0; j < i; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

void simpleSelectionSort(int* array, int N)
{
    ElementType temp;
    int i, j, min;
    
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void insertSort(int* array, int N)
{
    int i, j;
    ElementType temp;
    
    for (i = 1; i < N; i++)
    {
        temp = array[i];
        for (j = i; array[j-1] > temp && j > 0; j--)
        {
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 
struct TNode
{
    int Data;
    struct TNode* Left;
    struct TNode* Right;
};
 
typedef struct TNode* Tree;
 
//还原二叉树的函数
 ≤≥
    Tree T = (Tree)malloc(sizeof(struct TNode));
    //if (T == NULL) {return NULL;//若内存满了，返回NULL；}
    T->Data = pre[0];                    // 当前根节点
    for (i = 0; i < n; i++)
    {
        if (i <= n1 && in[i] != pre[0])
        {                                 //中序遍历被根节点分开的左子树的点
            lin[n1++] = in[i];
        }
        else if (in[i] != pre[0])
        {                                 //右子树的点,注意是else if，因为这个时候i是大于n1的
            rin[n2++] = in[i];
        }
    }
    //分前序遍历序列,注意！这里从1开始循环，因为0号元素作为根
    for (i = 1; i < n; i++)
    {
        if (i<(n1 + 1))               // 这里n1+1是因为编号是从1开始的，共有n1个左子数
        {
            lpre[m1++] = pre[i];
            //m1++;
        }
        else
        {
            rpre[m2++] = pre[i];     //  其余为右子数
            //m2++;
        }
    }
    T->Left = restoreTree(lpre, lin, n1);
    T->Right = restoreTree(rpre, rin, n2);
    return T;
}
int getHight(Tree BST) {//得到树的高度，已知左右树高，树高为max（左树高，右树高）+1；
    int lh, rh;
    if (BST == NULL)
    {
        return 0;
    }
    else {
        lh = getHight(BST->Left);
        rh = getHight(BST->Right);
        return (lh>rh ? lh : rh) + 1;
    }
 
}
int main()
{
    int n;
    char pre[60], in[60];
    scanf("%d", &n);
    scanf("%s", pre);
    scanf("%s", in);
    Tree BST = NULL;
    BST = restoreTree(pre, in, n);//建树
    int hight;
    hight = getHight(BST);//求高
    printf("%d\n", hight);//输出
    return 0;
}
*/
