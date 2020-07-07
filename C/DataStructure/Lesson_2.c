/*
//Lesson 2
 
 02-线性结构1 两个有序链表序列的合并 (15分)
 本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

 函数接口定义：
 List Merge( List L1, List L2 );

       
     
 其中List结构定义如下：

 typedef struct Node *PtrToNode;
 struct Node {
     ElementType Data; 存储结点数据
     PtrToNode   Next;  指向下一个结点的指针
 };
 typedef PtrToNode List;  定义单链表类型

       
     
 L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
 函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

 裁判测试程序样例：
 #include <stdio.h>
 #include <stdlib.h>

 typedef int ElementType;
 typedef struct Node *PtrToNode;
 struct Node {
     ElementType Data;
     PtrToNode   Next;
 };
 typedef PtrToNode List;

 List Read()  细节在此不表
 {
     int n;
     scanf("%d",&n);
     List L=(List)malloc(sizeof(PtrToNode));   ///申请一个头结点
     L->Next = NULL;        ///头指针为空
     if(n)    ///当n不是0时
     {
         List r=L;     ///r是一个中间变量的节点
         for(int i=0;i<n;i++)
         {
             List p=(List)malloc(sizeof(struct Node));
             scanf("%d",&(p->Data));    ///尾插法
             r->Next = p;
             r = p;
         }
         r->Next = NULL;
     }
     return L;
 }
 

 void Print( List L )  细节在此不表；空链表将输出NULL
 {
    List p=L->Next;
    if(p)
    {
        List r;
        r = L;
        while(r->Next)
        {
            r = r->Next;
            printf("%d ",r->Data);
        }
    }
    else
    {
        printf("NULL");
    }
    printf("\n");
 }
 

 List Merge( List L1, List L2 );

 int main()
 {
     List L1, L2, L;
     L1 = Read();
     L2 = Read();
     L = Merge(L1, L2);
     Print(L);
     Print(L1);
     Print(L2);
     return 0;
 }

  你的代码将被嵌在这里

       
     
 输入样例：
 3
 1 3 5
 5
 2 4 6 8 10

       
     
 输出样例：
 1 2 3 4 5 6 8 10
 NULL
 NULL

//2020/3/27
List Merge(List L1, List L2)
{
    List front,rear,pa,pb;
    front = (List)malloc(sizeof(struct Node));
    rear = front;
    pa = L1->Next;
    pb = L2->Next;
    while (pa && pb)
    {
        if (pa->Data <= pb->Data)
        {
            rear->Next = pa;
            rear = rear->Next;
            pa = pa->Next;
        }
        else
        {
            rear->Next = pb;
            rear = rear->Next;
            pb = pb->Next;
        }
    }
    if (pa)
    {
        rear->Next = pa;
    }
    else
    {
        rear->Next = pb;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return front;
}
 
 02-线性结构2 一元多项式的乘法与加法运算 (20分)
 设计函数分别求两个一元多项式的乘积与和。

 输入格式:
 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

 输出格式:
 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

 输入样例:
 4 3 4 -5 2  6 1  -2 0
 3 5 20  -7 4  3 1

       
     
 输出样例:
 15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
 5 20 -4 4 -5 2 9 1 -2 0

//2020/3/28
#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"

typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode
{
    ElementType coef;
    ElementType expon;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List getList(void);//获取链表
List polyAdd(List, List);//两个多项式相加，生成新的链表
List polyMultiply(List, List);//两个多项式相乘，生成新的链表
void printList(List);//输出多项式
void attach(int coef, int expon, Position* ptrRear);//往指定链表中添加新的元素
Position removeEmptyNode(Position);//移除空表头

int main()
{
    List listFirst, listSecond, listAdd, listMultiply;
    listFirst = getList();
    listSecond = getList();
    listAdd = polyAdd(listFirst, listSecond);
    listMultiply = polyMultiply(listFirst, listSecond);
    printList(listMultiply);
    putchar('\n');
    printList(listAdd);

    return 0;
}

void attach(int coef, int expon, Position * ptrRear)
{
    Position P;

    P = (Position)malloc(sizeof(struct LNode));
    P->coef = coef;
    P->expon = expon;
    P->Next = NULL;

    (*ptrRear)->Next = P;
    *ptrRear = P;
}

Position removeEmptyNode(Position front)
{
    Position temp;
    
    temp = front;
    front = front->Next;
    free(temp);
    
    return front;
}

List getList(void)
{
    List front, rear;
    int numOfPoly, coef, expon, i, a;

    front = (List)malloc(sizeof(struct LNode));
    rear = front;
    a = scanf("%d", &numOfPoly);//不用上scanf的返回值不让编译通过
        for (i = a - 1; i < numOfPoly; i++)
        {
            a = scanf("%d %d", &coef, &expon);
            attach(coef, expon, &rear);
            
        }
    
    rear->Next = NULL;
    front = removeEmptyNode(front);

    return front;
}

void printList(List L)
{
    bool zero = true;//要求零多项式特殊输出，用来判断
    while (L)
    {
        if (L->coef != 0)//要求输出非零值
        {
            printf("%d", L->coef);
            putchar(' ');
            printf("%d", L->expon);
            zero = false;
        }
        L = L->Next;
        if (L && L->coef != 0)
        {
            putchar(' ');
        }
    }
    if (zero)
    {
        printf("0 0");
    }
}

List polyAdd(List listFirst, List listSecond)//这个函数不用注释你也应该能看懂
{
    Position front, rear;
    int sum;
    
    front = (Position)malloc(sizeof(struct LNode));
    rear = front;
    while (listFirst && listSecond)
    {
        if (listFirst->expon > listSecond->expon)
        {
            attach(listFirst->coef, listFirst->expon, &rear);
            listFirst = listFirst->Next;
        }
        else if (listFirst->expon < listSecond->expon)
        {
            attach(listSecond->coef, listSecond->expon, &rear);
            listSecond = listSecond->Next;
        }
        else
        {
            sum = listFirst->coef + listSecond->coef;
            attach(sum, listFirst->expon, &rear);
            listFirst = listFirst->Next;
            listSecond = listSecond->Next;
        }
    }
    for (; listFirst; listFirst = listFirst->Next)
    {
        attach(listFirst->coef, listFirst->expon, &rear);
    }
    for (; listSecond; listSecond = listSecond->Next)
    {
        attach(listSecond->coef, listSecond->expon, &rear);
    }
    rear->Next = NULL;
    front = removeEmptyNode(front);

    return front;
}

List polyMultiply(List L1, List L2)
{
    List firstList, secondList;//我感觉这里指针用多了，两个参数链表
    Position tempFront1,tempFront2, tempRear1, tempRear2;//和两条用于合成的链的表头和表尾
    int coef, expon;//P.S.是不是一条就够了？
    
    if (!L1 || !L2)
    {
        return NULL;
    }
    
    tempFront1 = (Position)malloc(sizeof(struct LNode));
    tempFront2 = (Position)malloc(sizeof(struct LNode));
    firstList = L1;
    secondList = L2;
    tempRear1 = tempFront1;
    tempRear2 = tempFront2;
    while (firstList)//第二条链的第一项和第一条链所有项相乘，生成temp1链
    {
        coef = firstList->coef * secondList->coef;
        expon = firstList->expon + secondList->expon;//我把secondList写成了firstList，花了半小时才发现
        attach(coef, expon, &tempRear1);
        firstList = firstList->Next;
    }
    tempRear1->Next = NULL;
    tempFront1 = removeEmptyNode(tempFront1);
    secondList = secondList->Next;
    while (secondList)//从第二条链的第二项开始循环
    {
        firstList = L1;
        tempRear2 = tempFront2;
        while (firstList)//第二条链的某一项和第一条链所有项相乘，生成temp2链
        {
            coef = firstList->coef * secondList->coef;
            expon = firstList->expon + secondList->expon;
            attach(coef, expon, &tempRear2);
            firstList = firstList->Next;
        }
        tempRear2->Next = NULL;
        tempFront2 = removeEmptyNode(tempFront2);//去除每次循环都需要去掉的表头，这句也用了半小时改
        tempFront1 = polyAdd(tempFront1, tempFront2);//temp1和temp2相加，生成新的temp1
        secondList = secondList->Next;//因为忘记这句话，我找了半小时bug
    }
    
    return tempFront1;
}

 
02-线性结构3 Reversing Linked List (25分)
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10
​5
​​ ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

      
    
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

      
    
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

//2020/3/29
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100001

typedef int Element;
typedef struct LNode *PtrToLNode;
struct LNode
{
    Element address;
    Element data;
    Element nextAddress;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position reverseList(Position L, int K);
void printList(List L);

int main()
{
    int firstAddress, n, k, i, j, temp, num;
    int data[MAX_SIZE];
    int next[MAX_SIZE];
    
    scanf("%d %d %d",&firstAddress, &n, &k);
    struct LNode array[n+1];
    array[0].nextAddress = firstAddress;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        scanf("%d %d", &data[temp], &next[temp]);
    }
    
    for (i = 1; ; i++)
    {
        if (array[i - 1].nextAddress == -1)
        {
            num = i - 1;
            array[i - 1].Next = NULL;
            break;
        }
        array[i].address = array[i - 1].nextAddress;
        array[i].data = data[array[i].address];
        array[i].nextAddress = next[array[i].address];
        array[i - 1].Next = array + i;//这代码真的牛逼
    }
    
    Position p = array;//p指向链表头结点
    Position rp = NULL;//反转链表函数的返回值
    if (k <= num)
    {
        for (i = 0; i < num / k; i++)
        {
            rp = reverseList(p, k);
            p->Next = rp;// 第一次执行，a[0]->next 指向第一段子链表反转的第一个节点
            p->nextAddress = rp->address;// 更改Next值，指向逆转后它的下一个节点的位置
            for (j = 0; j < k; j++)//使p指向下一段需要反转的子链表的头结点（第一个节点的前一个节点）
            {
                p = p->Next;
            }
        }
    }
    
    printList(array->Next);
}

Position reverseList(Position head, int K)
{
    Position new, old, temp;
    int i;
    
    new = head->Next;
    old = new->Next;
    temp = NULL;
    for (i = 1; i < K; i++)
    {
        temp = old->Next;
        old->Next = new;
        old->nextAddress = new->address;
        new = old;
        old = temp;
    }
    head->Next->Next = old;//使反转后的最后一个节点指向下一段子链表的第一个节点
    if (old)//修改Next值，使它指向下一个节点的位置
    {
        head->Next->nextAddress = old->address;
    }
    else//如果old为NULL,即没有下一个子链表，那么反转后的最后一个节点即是真个链表的最后一个节点
    {
        head->Next->nextAddress = -1;
    }
    
    return new;
}

void printList(List L)
{
    while (L->nextAddress != -1)
    {
        printf("%05d %d %05d\n", L->address, L->data, L->nextAddress);
        L = L->Next;
    }
    printf("%05d %d %d", L->address, L->data, -1);
}
 
 
 02-线性结构4 Pop Sequence (25分)
 Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

 Input Specification:
 Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

 Output Specification:
 For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

 Sample Input:
 5 7 5
 1 2 3 4 5 6 7
 3 2 1 7 5 6 4
 7 6 5 4 3 2 1
 5 6 4 3 7 2 1
 1 7 6 5 4 3 2

       
     
 Sample Output:
 YES
 NO
 NO
 YES
 NO

//2020/3/29
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack createStack(void);
bool push(Stack, ElementType);
ElementType pop(Stack);
bool inStack(Stack, ElementType);
void sequence(int, int, int, int[*][*]);

int main()
{
    int m, n, k, i, j;
    scanf("%d %d %d", &m, &n, &k);
    int array[k][n+1];
    
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
        array[i][n] = 0;
    }

    sequence(m, k, n, array);
    
    for (i = 0; i < k; i++)
    {
        if (i)
        {
            putchar('\n');
        }
        if (array[i][n])
        {
            printf("YES");
        }
        else
        {
            printf("NO");
        }
    }
    
}

Stack createStack(void)
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Data = 0;
    S->Next = NULL;
    
    return S;
}

bool push(Stack S, ElementType X)
{
    Stack temp;
    
    temp = (Stack)malloc(sizeof(struct SNode));
    temp->Data = X;
    temp->Next = S->Next;
    S->Next = temp;
    S->Data += 1;
    
    return true;
}

ElementType pop(Stack S)
{
    ElementType X;
    Stack temp;
    
    temp = S->Next;
    X = temp->Data;
    S->Next = temp->Next;
    free(temp);
    S->Data -= 1;
    
    return X;
}

bool inStack(Stack S, ElementType X)
{
    while (S)
    {
        if (S->Data == X)
        {
            return true;
        }
        else
        {
            S = S->Next;
        }
    }
    
    return false;
}

void sequence(int m, int k, int n, int array[k][n + 1])
{
    Stack S;
    int i, j, l, *p;
    int num[n];
    
    for (i = 0; i < n; i++)
    {
        num[i] = i + 1;
    }
    for (i = 0; i < k; i++)
    {
        p = num;
        S = createStack();
        for (j = 0; j < n; j++)
        {
            if (inStack(S, array[i][j]))
            {
                if (S->Next->Data == array[i][j])
                {
                    if (pop(S) == array[i][n - 1])
                    {
                        array[i][n] = 1;
                    }
                    continue;;
                }
                else
                {
                    break;
                }
            }
            else
            {
                for (l = *p;l < array[i][j] + 1; l++)
                {
                    push(S, l);
                    p++;
                }
                if (S->Data > m)
                {
                    break;
                }
                j--;
            }
        }
    }
}


//验证(log n)^2的复杂度
#include <stdio.h>
#include "math.h"

int main()
{
    double N;
    
    printf("Please enter:");
    scanf("%lf", &N);
    printf("Ratio: %f", log(N) * log(N) / N);
    
    return 0;
}
*/
