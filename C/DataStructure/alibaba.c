
/*
//第一题
#include <stdio.h>
#include "stdlib.h"

long Abs(long);

int main()
{
    int n, i, j;
    long *a, temp, sum = 0;
    
    scanf("%d", &n);
    a = (long*)calloc(n, sizeof(long));
    for (i = 0; i < n; i++)
    {
        scanf("%ld", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i+1;j < n; j++)
        {
            if (Abs(a[j%n]-a[(j-1)%n])+Abs(a[(j+1)%n]-a[(j+2)%n]) < Abs(a[j%n]-a[(j+2)%n])+Abs(a[(j-1)%n]- a[(j+1)%n]))
            {
                temp = a[j%n];
                a[j%n] = a[(j+1)%n];
                a[(j+1)%n] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        sum += Abs(a[i] - a[(i+1)%n]);
    }
    printf("%ld\n",sum);
    for (i = 0; i < n; i++)
    {
        printf("%ld",a[i]);
        if (i != n-1)
        {
            putchar(' ');
        }
    }
}

long Abs(long n)
{
    return (n > 0) ? n : -n;
}
*/
//第二题
#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, i, j;
    long (*array)[2];
    double sum = 0,X,Y,Z;
    
    scanf("%d", &n);
    array = (long (*)[2])malloc(sizeof(long)*2*n);
    for (i = 0; i < n; i++)
    {
        scanf("%ld %ld",&array[i][0], &array[i][1]);
    }
    for (i = 0;i < n-1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            X =  (double)(array[i][0] + array[j][0]) /2;
            Y =  (double)(array[i][0] + array[j][0]) /2;
            Z = (X > Y)? Y : X;
            if (Z > sum)
            {
                sum = Z;
            }
        }
    }
    printf("%.1lf",sum);
}

/*
#include <stdio.h>
#define CARD_ROW 5
#define CARD_COL 8
#define CHART_ROW 5
#define CHART_COL 5

int printCards(void);
void printChart(void);
void getNum(int);

int main()
{
    int whichCard;
    whichCard = printCards();
    printChart();
    getNum(whichCard);
}

int printCards(void)
{
    int i, j, k, num = 0;
    
    printf("I will guess the number(0 <= num <%d ):\n\n", CARD_ROW * CARD_COL * CHART_ROW * CHART_COL);
    for (i = 0; i < CHART_ROW * CHART_COL; i++)
    {
        printf("No.%d:\n", i);
        for (j = 0; j < CARD_ROW; j++)
        {
            for (k = 0; k < CARD_COL; k++)
            {
                printf("%3d ", num++);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    printf("Now tell me which card appears that number:");
    scanf("%d", &num);
    
    return num;
}

void printChart(void)
{
    int i, j, k, l, num;
    for (i = 0; i < CARD_ROW; i++)
    {
        for (j = 0; j < CARD_COL; j++)
        {
            num = i * CARD_COL +j;
            printf("Row:%d COL:%d\n", i, j);
            for (k = 0; k < CHART_ROW; k++)
            {
                for (l = 0; l < CHART_COL; l++)
                {
                    printf("%3d ",num);
                    num += CARD_ROW * CARD_COL;
                }
                putchar('\n');
            }
            putchar('\n');
        }
    }
}

void getNum(int whichCard)
{
    int row,col,num;
    
    printf("Now tell me which row and column have that number\n(eg:1 2):");
    scanf("%d %d", &row, &col);
    num = row * CARD_COL + col + whichCard * CARD_ROW * CARD_COL;
    printf("The number is %d\n",num);
}



#include <stdio.h>
#define CARD_ROW 4
#define CARD_COL 7
#define CHART_ROW 4
#define CHART_COL 5
#define NUM CARD_ROW * CARD_COL * CHART_ROW * CHART_COL

int printCards(void);
void printChart(void);
void getNum(int);
char sur[3*NUM+1] = "赵钱孙李周吴郑王冯陈褚卫蒋沈韩杨朱秦尤许何吕施张孔曹严华金魏陶姜戚谢邹喻柏水窦章云苏潘葛奚范彭郎鲁韦昌马苗凤花方俞仁袁柳酆鲍史唐费廉岑薛雷贺倪汤滕殷罗毕郝邬安常乐于时傅皮卞齐康伍余元卜顾孟平黄和穆萧尹姚邵湛汪祁毛禹狄米贝明臧计伏成戴谈宋茅庞熊纪舒屈项祝董梁杜阮蓝闵席季麻强贾路娄危江童颜郭梅盛林刁钟徐邱骆高夏蔡田樊胡凌霍虞万支柯咎管卢莫经房裘缪干解鹰宗丁宣贲邓郁单杭洪包诸左石崔吉钮龚程嵇邢滑裴陆荣翁荀羊於惠甄曲家封芮羿储靳汲邴糜松井段富巫乌焦巴弓牧隗山谷车侯宓蓬全郗班仰秋仲伊宫宁仇栾暴甘钭厉戎祖武符刘景詹束龙叶幸司韶郜黎蓟博印宿白怀蒲台从鄂索咸籍赖卓蔺屠蒙池乔阴郁胥能苍双闻莘党翟谭贡劳逄姬申扶堵冉宰郦雍却璩桑桂濮牛寿通边扈燕冀郏浦尚农温别庄晏柴瞿阎充慕连茹习宦艾鱼容向古易慎戈廖庾终暨居衡步都耿满弘匡国文寇广禄阙东殴殳沃利蔚越夔隆师巩厍聂晁勾敖融冷訾辛阚那简饶空曾毋沙乜养鞠须丰巢关蒯相查后荆红游竺权逯盖後桓公万俟司马上官欧阳夏侯诸葛闻人东方赫连皇甫尉迟公羊澹台公冶宗政濮阳淳于单于太叔申屠公孙仲孙轩辕令狐钟离宇文长孙慕容鲜于闾丘司徒司空亓官司寇仉督子车颛孙端木巫马公西漆雕乐正壤驷公良拓拔夹谷宰父谷粱晋楚闫法汝鄢涂钦段干百里东郭南门呼延归海羊舌微生岳帅缑亢况后有琴梁丘左丘东门西门商牟佘佴伯赏南宫墨哈谯笪年爱阳佟";

int main()
{
    int whichCard;
    whichCard = printCards();
    printChart();
    getNum(whichCard);
}

int printCards(void)
{
    int i, j, k, num = 0;
    
    printf("我将猜出你的姓氏:\n\n");
    for (i = 0; i < CHART_ROW * CHART_COL; i++)
    {
        printf("第%d张卡片:\n", i + 1);
        for (j = 0; j < CARD_ROW; j++)
        {
            for (k = 0; k < CARD_COL; k++)
            {
                printf("%c%c%c ", sur[3*num], sur[3*num+1], sur[3*num+2]);
                num++;
            }
            putchar('\n');
        }
        putchar('\n');
    }
    printf("请告诉我第几张卡片出现了你的姓氏:");
    scanf("%d", &num);
    
    return num-1;
}

void printChart(void)
{
    int i, j, k, l, num;
    for (i = 0; i < CARD_ROW; i++)
    {
        for (j = 0; j < CHART_ROW; j++)
        {
            for (k = 0; k < CARD_COL; k++)
            {
                num = i * CARD_COL +j * CARD_COL * CARD_ROW * CHART_COL + k;
                for (l = 0; l < CHART_COL; l++)
                {
                    printf("%c%c%c ", sur[3*num], sur[3*num+1], sur[3*num+2]);
                    num += CARD_ROW * CARD_COL;
                }
                putchar(' ');
                putchar(' ');
            }
            putchar('\n');
        }
        putchar('\n');
    }
}

void getNum(int whichCard)
{
    int row,col,num;
    
    printf("下面请你将卡片放到出现了你的姓氏的地方.\n请告诉我是第几行第几列(例如:1 2):");
    scanf("%d %d", &row, &col);
    row--;
    col--;
    num = row * CARD_COL + col + whichCard * CARD_ROW * CARD_COL;
    printf("你的姓氏是%c%c%c\n",sur[3*num], sur[3*num+1], sur[3*num+2]);
}

#include "stdio.h"
#define P 5.5
#define S(x) P*x*x//宏定义是形式化定义，不传参数

int main()
{
    int a = 1, b = 2;
    printf("S(a) = %.1f\n", S(a));
    printf("S(b) = %.1f\n", S(b));
    printf("S(a+b) = %.1f\n", S(a + b));//因此是P*a+b*a+b,而不是P*（a+b）*（a+b）
}
*/
