#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertsort(int a[11],int n);
int main (void)
{
    int i,j;
    int t;
    int n;
    int a[11]={0};
    srand(time(NULL));
    for(i=0;i<10;i++)
    {
        a[i]=(rand()%100)+1;
       
    }//随机生成10个数存入数组
    for(i=0;i<10;i++)
    {
        for(j=0;j<9-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                
            }
        }
    }//冒泡排序
    
    printf("The original string is below:\n");
    for(i=0;i<10;i++)
    {
        printf("%3d",a[i]);
    }
    printf("\n\n");//输出原数组
    
    printf("Please enter the number you want to insert:");
    scanf("%d",&n);
    printf("\n\n");
    for(i=0;i<10;i++)
    {
        if(n<a[i])
        {
            for(j=11;j>i;j--)
            {
                a[j]=a[j-1];
            }
            a[i]=n;
            break;
            
        }
    }//插入排序
    printf("The inserted string is below:\n");
    for(i=0;i<11;i++)
    {
        printf("%3d",a[i]);
    }//输出新数组
    printf("\n\n");
    
     
    
    return 0;
    
}
