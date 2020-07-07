/*
//Lesson 3
 
03-树1 树的同构 (25分)
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。

现给定两棵树，请你判断它们是否是同构的。
输入格式:
输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:
如果两棵树是同构的，输出“Yes”，否则输出“No”。

输入样例1（对应图1）：
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -

      
    
输出样例1:
Yes

      
    
输入样例2（对应图2）：
8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4

      
    
输出样例2:
No


//2020/4/13
#include <stdio.h>
#include "stdbool.h"

struct TNode
{
    char ch;
    int left;
    int right;
};
typedef struct TNode Tree;

void getTree(Tree*, int);
bool judgeTree(Tree*, Tree*, int);


int main()
{
    int num1, num2;
    bool Isomorphism;
    Tree* tree1,*tree2;
    
    scanf("%d", &num1);
    tree1 = (Tree*)calloc(num1, sizeof(Tree));
    getTree(tree1, num1);
    getchar();
    scanf("%d", &num2);
    tree2 = (Tree*)calloc(num2, sizeof(Tree));
    getTree(tree2, num2);
    
    if (num1 == num2)
    {
        Isomorphism = judgeTree(tree1, tree2, num1);
    }
    else
    {
        Isomorphism = false;
    }
    
    if (Isomorphism)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}

void getTree(Tree* tree, int num)
{
    char ch, left, right;
    
    for (int i = 0; i < num; i++)
    {
        getchar();
        scanf("%c %c %c", &ch, &left, &right);
        tree->ch = ch;
        if (left - 45)
        {
            tree->left = left - 48;
        }
        else
        {
            tree->left = -1;
        }
        if (right - 45)
        {
            tree->right = right - 48;
        }
        else
        {
            tree->right = -1;
        }
        tree++;
    }
}

bool judgeTree(Tree* tree1, Tree* tree2, int num)
{
    int i, j;
    char leftOfTree1, rightOfTree1, leftOfTree2, rightOfTree2;
    
    for (i = 0; i < num; i++)
    {
        leftOfTree1 = 'a';
        rightOfTree1 = 'a';
        if (tree2[i].left >= 0)
        {
            leftOfTree2 = tree2[tree2[i].left].ch;
        }
        else
        {
            leftOfTree2 = '\0';
        }
        if (tree2[i].right >= 0)
        {
            rightOfTree2 = tree2[tree2[i].right].ch;
        }
        else
        {
            rightOfTree2 = '\0';
        }
        for (j = 0; j < num; j++)
        {
            if (tree1[j].ch != tree2[i].ch)
            {
                continue;
            }
            else
            {
                if (tree1[j].left >= 0)
                {
                    leftOfTree1 = tree1[tree1[j].left].ch;
                }
                else
                {
                    leftOfTree1 = '\0';
                }
                if (tree1[j].right >=0)
                {
                    rightOfTree1 = tree1[tree1[j].right].ch;
                }
                else
                {
                    rightOfTree1 = '\0';
                }
                break;
            }
        }
        if (leftOfTree1 == leftOfTree2 && rightOfTree1 == rightOfTree2)
        {
            continue;
        }
        else if (leftOfTree1 == rightOfTree2 && leftOfTree2 == rightOfTree1)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
 
 03-树2 List Leaves (25分)
 Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

 Input Specification:
 Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

 Output Specification:
 For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

 Sample Input:
 8
 1 -
 - -
 0 -
 2 7
 - -
 - -
 5 -
 4 6

       
     
 Sample Output:
 4 1 5


//2020/4/14
#include <stdio.h>
#include "stdbool.h"
#define MAXSIZE 11

struct TNode
{
    int self;
    int left;
    int right;
};
typedef struct TNode Tree;

struct QNode
{
    Tree tree[MAXSIZE];
    int rear;
    int front;
};
typedef struct QNode Queue;

void getTree(Tree*, int);
void findLeaves(Tree*, int);
int findRoot(Tree*, int);
void addQueue(Queue*, Tree);
int deleteQueue(Queue*);

int main()
{
    int num;
    Tree *tree;
    
    scanf("%d", &num);
    tree = (Tree*)calloc(num, sizeof(struct TNode));
    getTree(tree, num);
    findLeaves(tree, num);
}

void getTree(Tree* tree, int num)
{
    char left, right;
    
    for (int i = 0; i < num; i++)
    {
        getchar();
        tree->self = i;
        scanf("%c %c", &left, &right);
        if (left - 45)
        {
            tree->left = left - 48;
        }
        else
        {
            tree->left = -1;
        }
        if (right - 45)
        {
            tree->right = right - 48;
        }
        else
        {
            tree->right = -1;
        }
        tree++;
    }
}

void findLeaves(Tree* tree, int num)
{
    int root, node, leave[num], i, j;
    Queue *queue;
    
    i = 0;
    queue = (Queue*)calloc(1, sizeof(Queue));
    root = findRoot(tree, num);
    addQueue(queue, tree[root]);
    while (queue->front != queue->rear)
    {
        node = deleteQueue(queue);
        if (tree[node].left == -1 && tree[node].right == -1)
        {
            leave[i++] = node;
        }
        if (tree[node].left != -1)
        {
            addQueue(queue, tree[tree[node].left]);
        }
        if (tree[node].right != -1)
        {
            addQueue(queue, tree[tree[node].right]);
        }
    }
    
    for(j = 0; j < i; j++)
    {
        printf("%d", leave[j]);
        if (j != i - 1)
        {
            putchar(' ');
        }
    }
}

int findRoot(Tree* tree, int num)
{
    int i;
    bool findRoot[num];
    
    for (i = 0; i < num; i++)
    {
        findRoot[i] = true;
    }
    for (i = 0; i < num; i++)
    {
        if (tree[i].left >=0)
        {
            findRoot[tree[i].left] = false;
        }
        if (tree[i].right >=0)
        {
            findRoot[tree[i].right] = false;
        }
    }
    for (i = 0; i < num; i++)
    {
        if (findRoot[i])
        {
            return i;
        }
        else
        {
            continue;
        }
    }
    return -1;
}

void addQueue(Queue* queue, Tree tree)
{
    queue->rear = (queue->rear + 1) % MAXSIZE;
    queue->tree[queue->rear] = tree;
}

int deleteQueue(Queue* queue)
{
    queue->front = (queue->front + 1) % MAXSIZE;
    
    return queue->tree[queue->front].self;
}

03-树3 Tree Traversals Again (25分)
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

      
    
Sample Output:
3 4 2 6 5 1

//2020/4/15
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode *PtrtoTNode;
struct TNode
{
    int X;
    PtrtoTNode left;
    PtrtoTNode right;
};
typedef PtrtoTNode Tree;

typedef struct SNode *PtrtoSNode;
struct SNode
{
    PtrtoTNode node;
    PtrtoSNode next;
};
typedef PtrtoSNode Stack;

Tree createTree(int*, int);
void postOrderTraversal(Tree, int);
void push(Stack, Tree);
Tree pop(Stack);

int main()
{
    int N, i, *Array, first;
    Tree tree;
    
    scanf("%d\n", &N);
    Array = (int*)calloc(2 * N, sizeof(int));
    for (i = 0; i < 2 * N; i++)
    {
        if(!scanf("Push %d\n", &Array[i]))
        {
            Array[i] = -1;
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    tree = createTree(Array, N);
    first = tree->X;
    postOrderTraversal(tree, first);
}

Tree createTree(int* Array, int N)
{
    Stack s;
    Tree tree, t, temp;
    int i;
    
    s = (Stack)malloc(sizeof(struct SNode));
    tree = (Tree)malloc(sizeof(struct TNode));
    tree->X = Array[0];
    t = tree;
    push(s, t);
    for(i = 1; i < 2 * N; i++)
    {
        if (Array[i] != -1)
        {
            temp = (Tree)malloc(sizeof(struct TNode));
            temp->X = Array[i];
            temp->left = NULL;
            temp->right = NULL;
            if (Array[i-1] != -1)
            {
                t->left = temp;
                push(s, t);
                t = t->left;
            }
            else
            {
                t->right = temp;
                t = t->right;
            }
            if (Array[i+1] == -1)
            {
                push(s, t);
            }
        }
        else
        {
            t = pop(s);
        }
    }
    return tree;
}

void postOrderTraversal(Tree tree, int first)
{
    if (tree != NULL)
    {
        postOrderTraversal(tree->left, first);
        postOrderTraversal(tree->right, first);
        printf("%d", tree->X);
        if (tree->X != first)
        {
            putchar(' ');
        }
    }
}

void push(Stack s, Tree t)
{
    Stack temp;
    
    temp = (Stack)malloc(sizeof(struct SNode));
    temp->node = t;
    temp->next = s->next;
    s->next = temp;
}

Tree pop(Stack s)
{
    Stack temp;
    
    temp = s->next;
    s->next = temp->next;
    
    return temp->node;
}
*/
