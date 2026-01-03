#include <stdio.h>
#define MaxSize 10
typedef int ElmeType;
typedef struct LinearList
{
    ElmeType data[MaxSize];
    int length;
} Sqlist;
void InitList(Sqlist *L)
{
    L->length = 0;
}
int main(){
Sqlist l;
InitList(&l);
for (int i = 0; i < MaxSize; i++)
{
    l.data[i] = 0;
    printf("data[%d]=%d/n", i, l.data[i]);
}
printf("%d", l.length);
return 0;
}
