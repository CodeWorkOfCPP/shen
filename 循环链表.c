//
//  main.c
//  循环链表
//
//  Created by 申 on 2019/1/22.
//  Copyright © 2019 C_Project. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;//指针域
    int size;//循环链表的长度
}node,*linklist;//linklist为定义的指针结构体变量

void create_list_head(linklist *l)//头插法建立循环链表
{
    int i,j,x;
    linklist p,q;
    printf("please input length");
    scanf("%d",&j);
    (*l)=(node*)malloc(sizeof(node));
    (*l)->next=NULL;//必须定义，缺少error
    (*l)->size=j;
    for(i=0;i<j;i++)//头插法输入数据
    {
        scanf("%d",&x);
        p=(node*)malloc(sizeof(node));
        p->data=x;
        p->next=(*l)->next;
        (*l)->next=p;
    }
    //q=(node*)malloc(sizeof(node));
    q=(*l)->next;
    while(q->next!=NULL)//找到最后一个结点
    {
        q=q->next;
    }
    //printf("%d",q->data);
    q->next=(*l)->next;//将最后一个结点指向第一个结点
    
    
    
}

void create_list_tail(linklist *l)//尾插法建立循环链表
{
    int i,j,x;
    linklist p,r,t;
    printf("please input the length");
    scanf("%d",&j);
    (*l)=(node*)malloc(sizeof(node));
    (*l)->next=NULL;
    (*l)->size=j;
    t=(*l);
    for(i=0;i<j;i++)
    {
        scanf("%d",&x);
        p=(node*)malloc(sizeof(node));
        p->data=x;
        t->next=p;
        t=p;//每新建一个结点在结束时都为最后一个结点，下一个节点在这个结点后面插入
        
    }
    t->next=NULL;
    r=(*l)->next;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    r->next=(*l)->next;
}

void print_list_he(linklist *l)//打印输出
{
    int i;
    linklist p;
    p=(*l)->next;
    for(i=0;i<(*l)->size;i++)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}

int main()
{
    linklist a;
    create_list_head(&a);
    create_list_tail(&a);
    print_list_he(&a);
    return 0;
    
}
    
    
