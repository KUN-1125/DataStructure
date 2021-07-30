#include"c.h"

// 定义顺序表(静态分配)
#define MaxSize 10
typedef struct 
{
    int data[MaxSize];
    int length = 0;
}SqList;

// 在L的第i个位置(位序)插入元素e
bool InsertSqList(SqList &L, int i, int e){
    if(i < 1 || i > L.length + 1)
        return false;
    if(L.length >= MaxSize)
        return false;
    for(int j = L.length; j >= i; j--){
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除L中的第i个元素(位序)赋值给e并返回
bool DeleteSqList(SqList &L, int i, int &e){
    if(i < 1 || i > L.length)
        return false;
    if(L.length == 0)
        return false;
    e = L.data[i - 1];
    for(int j = i; j < L.length; j++){
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

int main(){
    SqList L;
    InsertSqList(L, 1, 3);
    InsertSqList(L, 2, 1);
    InsertSqList(L, 3, 9);
    InsertSqList(L, 4, 7);
    InsertSqList(L, 5, 6);
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    int e;
    DeleteSqList(L, 1, e);
    printf("e = %d\n", e);
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    printf("L.length = %d", L.length);
}