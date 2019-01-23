//
//  main.c
//  双链表
//
//  Created by 申 on 2019/1/23.
//  Copyright © 2019 C_Project. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//节点结构体，每个节点分别保存了一个指向前一个节点的指针和指向后一个节点的指针，以及保存数据的指针
struct _node{
        struct _node *prevNode;
        struct _node *nextNode;
        void *data;
};


//链表结构体，记录了链表的首节点和尾节点指针，以及节点总个数
struct _list{
        struct _node *firstNode;
        struct _node *lastNode;
        int len;
};


// 头部加入节点
void lpush(struct _list *list, void *data)
{
        struct _node *node = malloc(sizeof(struct _node));
        bzero(node, sizeof(struct _node));
        node->data = data;
        node->nextNode = list->firstNode;
        if (list->firstNode != NULL)
            {
                    list->firstNode->prevNode = node;
                }
        list->firstNode = node;
        if (list->len == 0)
            {
                    list->lastNode = node;
                }
        list->len++;
}


// 尾部加入节点
void rpush(struct _list *list, void *data)
{
        struct _node *node = malloc(sizeof(struct _node));
        bzero(node, sizeof(struct _node));
        node->data = data;
        node->prevNode = list->lastNode;
        if (list->lastNode != NULL)
            {
                    list->lastNode->nextNode = node;
                }
        list->lastNode = node;
        if (list->len == 0)
            {
                    list->firstNode = node;
                }
        list->len++;
}


// 头部弹出节点
void lpop(struct _list *list)
{
        if (list->firstNode == NULL)
            {
                    return;
                }
    
    
        if (list->firstNode->nextNode != NULL)
            {
                    list->firstNode = list->firstNode->nextNode;
                    free(list->firstNode->prevNode);
                    list->firstNode->prevNode = NULL;
                }
        else
            {
                    free(list->firstNode);
                    list->firstNode = NULL;
                }
    
    
        list->len--;
    
    
        if (list->len == 0)
            {
                    list->lastNode = NULL;
                }
}




// 尾部弹出节点
void rpop(struct _list *list)
{
        if (list->lastNode == NULL)
            {
                    return;
                }
    
    
        if (list->lastNode->prevNode != NULL)
            {
                    list->lastNode = list->lastNode->prevNode;
                    free(list->lastNode->nextNode);
                    list->lastNode->nextNode = NULL;
                }
        else
            {
                    free(list->lastNode);
                    list->lastNode = NULL;
                }
    
    
        list->len--;
        if (list->len == 0)
            {
                    list->firstNode = NULL;
                }
}


// 获取指定位置上的节点值
void *getVal(struct _list list, int pos)
{
        if (pos < 0)
            {
                    return NULL;
                }
    
    
        int i;
        struct _node *curNode = list.firstNode;
        for(i = 0; i < pos; i++)
            {
                    if(curNode->nextNode != NULL)
                        {
                                curNode =  curNode->nextNode;
                            }
                    else
                        {
                                curNode = NULL;
                                break;
                            }
                }
    
    
        if (curNode == NULL){
                return NULL;
            }
        return curNode->data;
}






static void print_r(struct _list list)
{
        printf("-----------------------------------------\n");
        printf("list.len = %d\n", list.len);
        int i = 0;
        struct _node *node = list.firstNode;
        while(1)
            {
                    if (node == NULL)
                        {
                                break;
                            }
            
            
                    printf("list[%d]: %s\n", i, node->data);
                    node = node->nextNode;
                    i++;
                }
}




int main()
{
        struct _list list = {NULL, NULL, 0};
    
    
        lpush(&list, "node 0");
        lpush(&list, "node 1");
        lpush(&list, "node 2");
        rpush(&list, "node 3");
        rpush(&list, "node 4");
        print_r(list);
    
    
        lpop(&list);
        rpop(&list);
        print_r(list);
    
    
        lpop(&list);
        lpop(&list);
        lpop(&list);
        rpop(&list);
        rpop(&list);
        print_r(list);
    
    
        rpush(&list, "hello node");
        print_r(list);
    
    
}
