#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>

#define Initsize 10   //定义初始长度

typedef struct Dynamic_Sequentiallist  //用动态方式实现顺序表
{
    int *data;
    int length;
    int MaxSize;
} Sqlist;//重命名

void Initlist(Sqlist *L)  //初始化顺序表
{
    L->data = (int *)malloc(Initsize * sizeof(int));
    if (L->data == NULL)
    {
        printf("Memory allocation failed");
    }
    L->length = 0;
    L->MaxSize = Initsize;
}

void Increasesize(Sqlist *L, int length) //增加动态数组的长度
{
    int *p = L->data;
    L->data = (int *)malloc((L->MaxSize + length) * sizeof(int));
    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i];
    }
    L->MaxSize = L->MaxSize + length;
    free(p);
}

bool Listinsert(Sqlist *L,int i,int e)//向动态数组中插入元素
{
    if(i<1||i>L->length+1){
        return false;
    }
    if(L->length>=L->MaxSize){
        return false;
    }
    for (int j = L->length; j >= i;j--){
        L->data[j] = L->data[j - 1];
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool Listdelete(Sqlist *L, int i )//删除元素
{
    if(i<1||i>L->length+1){
        return false;
    }
    if (L->length > L->MaxSize)
    {
        return false;
    }
    for (int j = i; j < L->length;j++){
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

void Getelem(Sqlist *L,int i)//按位查找
{
    printf("第%d位数据是：%d\n", i, L->data[i - 1]);
}

void Locateelem(Sqlist *L,int e) //按值查找
{
    int bol = 0;
    for (int i = 0; i < L->length;i++){
        if(L->data[i]==e){
            printf("元素%d位置是：%d\n", e, i + 1);
            bol = 1;
        }
    }
    if(bol==0)
        printf("未找到元素%d\n", e);
}

int main()
{
    Sqlist l;  //声明一个动态顺序表
    Initlist(&l);  //初始化顺序表
    for (int i = 0; i < l.MaxSize; i++)//赋值
    {
        l.data[i] = 0;
        l.length++;
    }
    for (int i = 0; i < l.MaxSize; i++)//输出
    {
        printf("%d,", l.data[i]);
    }
    printf("\n");//换行

    Increasesize(&l, 5);//增加动态数组的长度
    for (int i = l.length;i<l.MaxSize;i++){
        l.data[i] = 1;
        l.length++;
    }
    for (int i = 0; i < l.MaxSize;i++){
        printf("%d,", l.data[i]);
    }
    printf("\n");

    Increasesize(&l, 5);
    if(Listinsert(&l, 6, 2)) //插入元素
        printf("添加成功\n");
    else
        printf("操作失败\n");
    for (int i = 0; i < l.length;i++){
        printf("%d,", l.data[i]);
    }
    printf("\n");
    
    if(Listdelete(&l,6))//删除元素
        printf("删除成功\n");
    else
        printf("操作失败\n");
    for (int i = 0; i < l.length; i++)
    {
        printf("%d,", l.data[i]);
    }
    printf("\n");

    Getelem(&l, 6);

    Listinsert(&l, 6, 2);
    Locateelem(&l, 2);

    free(l.data); // 释放内存
    return 0;
}