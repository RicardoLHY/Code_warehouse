/*
 //Lesson4
 04-树4 是否同一棵二叉搜索树 (25分)
 给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

 输入格式:
 输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

 简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

 输出格式:
 对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

 输入样例:
 4 2
 3 1 4 2
 3 4 1 2
 3 2 4 1
 2 1
 2 1
 1 2
 0

       
     
 输出样例:
 Yes
 No
 No

//2020/4/24
#include <stdio.h>
#include "stdlib.h"
#include "stdbool.h"
#include "math.h"

typedef int ElementType;
typedef struct TNode *PtrToTNode;
struct TNode
{
    ElementType data;
    PtrToTNode left;
    PtrToTNode right;
};
typedef PtrToTNode Tree;

Tree getTree(int);
void judgeTree(Tree, Tree, int);
Tree getTNode(int);
Tree insertTNode(Tree, int);
void inOrderTraverse(Tree, int*, int);
void preOrderTraverse(Tree, int*, int);

int main()
{
    int N, L, i;
    Tree tree1, tree2;
    
    scanf("%d", &N);
    while (N)
    {
        scanf(" %d\n", &L);
        tree1 = getTree(N);
        for (i = 0; i < L; i++)
        {
            tree2 = getTree(N);
            judgeTree(tree1, tree2, N);
            free(tree2);
        }
        free(tree1);
        scanf("%d", &N);
    }
}

Tree getTree(int N)
{
    int num, i;
    Tree tree;
    
    scanf("%d", &num);
    tree = getTNode(num);
    for (i = 1; i < N; i++)
    {
        scanf("%d", &num);
        tree = insertTNode(tree, num);
    }
    while (getchar() != '\n')
    {
        continue;
    }
    
    return tree;
}

Tree getTNode(int N)
{
    Tree tree;
    
    tree = (Tree)malloc(sizeof(struct TNode));
    tree->data = N;
    tree->left = NULL;
    tree->right = NULL;
    
    return tree;
}

Tree insertTNode(Tree tree, int N)
{
    if (!tree)
    {
        tree = getTNode(N);
    }
    else if (tree->data < N)
    {
        tree->right = insertTNode(tree->right, N);
    }
    else
    {
        tree->left = insertTNode(tree->left, N);
    }
    
    return tree;
}

void judgeTree(Tree tree1, Tree tree2, int N)
{
    int i, *array1, *array2, *array3, *array4, index;
    bool sameTree;
    
    index = 1;
    sameTree = true;
    for (i = 0; i < N; i++)
    {
        index *= 2;
    }
    array1 = (int*)malloc(index * sizeof(int));
    array2 = (int*)malloc(index * sizeof(int));
    array3 = (int*)malloc(index * sizeof(int));
    array4 = (int*)malloc(index * sizeof(int));
    for (i = 0; i < index; i++)
    {
        array1[i] = 0;
        array2[i] = 0;
        array3[i] = 0;
        array4[i] = 0;
    }
    inOrderTraverse(tree1, array1, 1);
    inOrderTraverse(tree2, array2, 1);
    preOrderTraverse(tree1, array3, 1);
    preOrderTraverse(tree2, array4, 1);
    for (i = 0;i < index; i++)
    {
        if (array1[i] != array2[i])
        {
            sameTree = false;
            break;
        }
        if (array3[i] != array4[i])
        {
            sameTree = false;
            break;
        }
    }
    if (sameTree)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

void inOrderTraverse(Tree tree, int *array, int i)
{
    if (tree != NULL)
    {
        inOrderTraverse(tree->left, array, 2 * i);
        array[i] = tree->data;
        inOrderTraverse(tree->right, array, 2 * i + 1);
    }
}

void preOrderTraverse(Tree tree, int *array, int i)
{
    if (tree != NULL)
    {
        array[i] = tree->data;
        preOrderTraverse(tree->left, array, 2 * i);
        preOrderTraverse(tree->right, array, 2 * i + 1);
    }
}


04-树5 Root of AVL Tree (25分)
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120

      
    
Sample Output 1:
70

      
    
Sample Input 2:
7
88 70 61 96 120 90 65

      
    
Sample Output 2:
88

//2020/4/24
#include <stdio.h>
#include "stdlib.h"

typedef int ElementType;
typedef struct AVLNode *AVLTree;
struct AVLNode
{
    ElementType data;
    AVLTree left;
    AVLTree right;
    int height;
};

AVLTree insertNode(AVLTree, ElementType);
AVLTree singleLeftRotation(AVLTree);
AVLTree singleRightRotation(AVLTree);
AVLTree doubleLeftRightRotation(AVLTree);
AVLTree doubleRightLeftRotation(AVLTree);
int getHeight(AVLTree);
int max(int, int);

int main()
{
    int N, data, i;
    AVLTree tree;
    
    tree = NULL;
    scanf("%d", &N);
    while (getchar() != '\n')
    {
        continue;
    }
    for (i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            scanf("%d ", &data);
        }
        else
        {
            scanf("%d", &data);
        }
        tree = insertNode(tree, data);
    }
    printf("%d", tree->data);
}

AVLTree insertNode(AVLTree tree, ElementType X)
{
    if (tree == NULL)
    {
        tree = (AVLTree)malloc(sizeof(struct AVLNode));
        tree->data = X;
        tree->left = NULL;
        tree->right = NULL;
        tree->height = 1;
    }
    else if (X < tree->data)
    {
        tree->left = insertNode(tree->left, X);
        if (getHeight(tree->left) - getHeight(tree->right) == 2)
        {
            if (X < tree->left->data)
            {
                tree = singleLeftRotation(tree);
            }
            else
            {
                tree = doubleLeftRightRotation(tree);
            }
        }
    }
    else if (X > tree->data)
    {
        tree->right = insertNode(tree->right, X);
        if (getHeight(tree->right) - getHeight(tree->left) == 2)
        {
            if (X > tree->right->data)
            {
                tree = singleRightRotation(tree);
            }
            else
            {
                tree = doubleRightLeftRotation(tree);
            }
        }
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    
    return tree;
}

AVLTree singleLeftRotation(AVLTree A)
{
    AVLTree B;
    
    B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left), A->height) + 1;
    
    return B;
}

AVLTree singleRightRotation(AVLTree A)
{
    AVLTree B;
    
    B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left), A->height) + 1;
    
    return B;
}

AVLTree doubleLeftRightRotation(AVLTree A)
{
    A->left = singleRightRotation(A->left);
    
    return singleLeftRotation(A);
}

AVLTree doubleRightLeftRotation(AVLTree A)
{
    A->right = singleLeftRotation(A->right);
    
    return singleRightRotation(A);
}

int getHeight(AVLTree tree)
{
    int a, b;
    
    if (tree != NULL)
    {
        a = getHeight(tree->left);
        b = getHeight(tree->right);
        return max(a, b) + 1;
    }
    else
    {
        return 0;
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

04-树6 Complete Binary Search Tree (30分)
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0

      
    
Sample Output:
6 3 8 1 5 7 9 0 2 4

//2020/4/25
#include <stdio.h>
#include "stdlib.h"

void sortArray(int*, int);
void getCBT(int*, int*, int, int);
static int k = 0;

int main()
{
    int N, *array, *CBT, i;
    static int *p;
    
    scanf("%d", &N);
    array = (int*)malloc(N * sizeof(int));
    CBT = (int*)malloc((N + 1) * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
    p = &array[0];
    sortArray(array, N);
    getCBT(p, CBT, N, 1);
    for (i = 0; i < N; i++)
    {
        printf("%d", CBT[i+1]);
        if (i != N-1)
        {
            putchar(' ');
        }
    }
}

void sortArray(int *array, int N)
{
    int i, j, temp;
    
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void getCBT(int *array, int*CBT, int N, int i)
{
    if (i <= N)
    {
        getCBT(array, CBT, N, 2 * i);
        CBT[i] = array[k++];
        getCBT(array, CBT, N, 2 * i + 1);
    }
}

04-树7 二叉搜索树的操作集 (30分)
本题要求实现给定二叉搜索树的5种常用操作。

函数接口定义：
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

      
    
其中BinTree结构定义如下：

typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

      
    
函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
函数FindMin返回二叉搜索树BST中最小元结点的指针；
函数FindMax返回二叉搜索树BST中最大元结点的指针。
裁判测试程序样例：见后

    
输入样例：
10
5 8 6 2 4 1 0 10 9 7
5
6 3 10 0 5
5
5 7 0 10 3

      
    
输出样例：
Preorder: 5 2 1 0 4 8 6 7 10 9
6 is found
3 is not found
10 is found
10 is the largest key
0 is found
0 is the smallest key
5 is found
Not Found
Inorder: 1 2 4 6 8 9
*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); // 先序遍历，由裁判实现，细节不表
void InorderTraversal( BinTree BT );  // 中序遍历，由裁判实现，细节不表

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

void PreorderTraversal(BinTree BT)
{
    if (BT != NULL)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void InorderTraversal( BinTree BT )
{
    if (BT != NULL)
    {
        InorderTraversal(BT->Left);
        printf("%d ", BT->Data);
        InorderTraversal(BT->Right);
    }
}

// 你的代码将被嵌在这里
//2020/4/25
BinTree Insert( BinTree BST, ElementType X )
{
    if (BST == NULL)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else if (X < BST->Data)
    {
        BST->Left = Insert(BST->Left, X);
    }
    else if (X > BST->Data)
    {
        BST->Right = Insert(BST->Right, X);
    }
    
    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    Position Temp;
    
    if (BST == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        if (X < BST->Data)
        {
            BST->Left = Delete(BST->Left, X);
        }
        else if (X > BST->Data)
        {
            BST->Right = Delete(BST->Right, X);
        }
        else
        {
            if (BST->Left != NULL && BST->Right != NULL)
            {
                Temp = FindMax(BST->Left);
                BST->Data = Temp->Data;
                BST->Left = Delete(BST->Left, BST->Data);
            }
            else
            {
                Temp = BST;
                if (BST->Left == NULL)
                {
                    BST = BST->Right;
                }
                else
                {
                    BST = BST->Left;
                }
                free(Temp);
            }
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    if (BST == NULL)
    {
        return NULL;
    }
    else if (X < BST->Data)
    {
        return Find(BST->Left, X);
    }
    else if (X > BST->Data)
    {
        return Find(BST->Right, X);
    }
    else
    {
        return BST;
    }
}

Position FindMin( BinTree BST )
{
    if (BST != NULL && BST->Left != NULL)
    {
        BST = FindMin(BST->Left);
    }
    
    return BST;
}

Position FindMax( BinTree BST )
{
    if (BST != NULL && BST->Right != NULL)
    {
        BST = FindMax(BST->Right);
    }
    return BST;
}
