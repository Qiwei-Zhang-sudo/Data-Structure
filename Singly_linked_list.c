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
    Linklist l;
    Initlist(&l);
    return 0;
}