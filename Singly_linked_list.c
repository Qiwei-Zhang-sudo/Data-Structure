#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
    int data;
    struct LNode *next;
} LNode ,*Linklist;

bool Initlist(Linklist *l)
{
    *l = (LNode *)malloc(sizeof(LNode));
    if(*l==NULL){
        return false;
    }
    (*l)->next = NULL;
    return true;
}

int main(){
    Linklist head,p,d;
    if(!Initlist(&head))
        printf("链表初始化失败！\n");
    p = head;
    printf("请输入0以外的数据，继续循环\n");
    do{
        d = (LNode *)malloc(sizeof(LNode));
        if(d==NULL)
            {
                printf("新节点分配失败\n");
                return -1;
            }
        printf("Please add your data:");
        scanf("%d", &d->data);
        if (d->data == 0)
        {
            free(d);
            break;
        }
        d->next = NULL;
        p->next = d;
        d = d;
    } while (1);
    p = head;
    while(p!=NULL){
        LNode *temp = p;
        p = p->next;
        free(temp);
    }
    return 0;
}