//
//  main.c
//  upload
//
//  Created by 申 on 2019/1/22.
//  Copyright © 2019 C_Project. All rights reserved.
//

#include <stdio.h>


//将n个圆盘从x柱子上借助y柱子移动到z柱子上
void mov(int n, char x, char y, char z)
{
    if(n == 1)
        printf("圆盘编号 %d :从 %c 移动到 %c\n",n,x,z);
    else
        {
            mov(n-1,x,y,z);
            printf("圆盘编号 %d:从 %c 移动到 %c\n",n,x,z);
            mov(n-1,y,x,z);
        }
}
int main()
{
   
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';
    int n;   //n代表圆盘的个数
    printf("请输入圆盘的个数：");
    scanf("%d",&n);
    mov(n,ch1,ch2,ch3);
    return 0;
}
