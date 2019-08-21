 /* 
 //计算代码数
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MAX 256

long total;

int countLines(const char *filename);
int isCode(const char *filename);
void findAllDirs(const char *path);

int countLines(const char *filename)
{
    FILE *fp;
    int count = 0;
    int temp;
    
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can not open the file: %s\n", filename);
        return 0;
    }
    
    while ((temp = fgetc(fp)) != EOF)
    {
        if (temp == '\n')
        {
            count++;
        }
    }
    
    fclose(fp);
    
    return count;
}

int isCode(const char *filename)
{
    int length;
    
    length = strlen(filename);
    
    if (!strcmp(filename + (length - 2), ".c"))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void findAllDirs(const char *path)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    
    if ((dp = opendir(path)) == NULL)
    {
        fprintf(stderr, "The path %s is wrong!\n", path);
        return;
    }
    
    chdir(path);
    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        
        if (!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name))
            continue;
        
        if (S_ISDIR(statbuf.st_mode))
        {
            findAllDirs(entry->d_name);
        }
        else
        {
            if (isCode(entry->d_name))
            {
                total += countLines(entry->d_name);
            }
        }
    }
    
    chdir("..");
    closedir(dp);
}

int main()
{
    char path[MAX] = ".";
    
    printf("计算中...\n");
    
    findAllDirs(path);
    
    printf("目前你总共写了 %ld 行代码！\n\n", total);
    
    return 0;
}

 //小甲鱼
#include "stdio.h"

int main()
{
    printf("Fish C.com no \"fish\"\n");
    return 0;
}

#include <stdio.h>

int main()
{
    printf("\n\
                 *     \n\
                / \\   \n\
                * *    \n\
                * *    \n\
                * *    \n\
            * * * * * *  \n\
          * * * * * * * * \n\
        * * * * * * * * * *\n\
                * *\n\
                * *\n\
              * * * *\n\
            * * * * * *\n");
}

#include "stdio.h"
#include "math.h"

int main()
{
    unsigned int result = pow(2,32)-1;
    printf("result = %u\n",result);
    return 0;
}

#include "stdio.h"

int main()
{
    char name[6]={'F','i','s','h','C','\0'};
    //char name[]={'F','i','s','h','C','\0'};
    //char name[]="FishC";
    printf("%s\n",name);
    return 0;
}

#include "stdio.h"

int main()
{
    int a = 3 , b = 3;
    (a=0)&&(b=5);
    printf("a=%d,b=%d\n",a,b);
    (a=1)||(b=5);
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
*/
#include <stdio.h>
  
int main(){  
    printf("Hello.\n");
    int u;  
    scanf("%d",&u);
    printf("%d",u*u);

    return 0;
}  