#include"c.h"
#include"AlgoSeqList.h"

int main(){
    SeqList L;
    InitSeqList(L);
    InsertSeqList(L, 1, 3);
    InsertSeqList(L, 2, 1);
    InsertSeqList(L, 3, 9);
    InsertSeqList(L, 4, 7);
    InsertSeqList(L, 5, 6);
    InsertSeqList(L, 1, 3);
    InsertSeqList(L, 2, 1);
    InsertSeqList(L, 3, 9);
    InsertSeqList(L, 4, 7);
    InsertSeqList(L, 5, 6);
    InsertSeqList(L, 1, 3);
    InsertSeqList(L, 2, 1);
    InsertSeqList(L, 3, 9);
    InsertSeqList(L, 4, 7);
    InsertSeqList(L, 5, 6);
    printf("测试插入操作\n");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\nL.length = %d\n", L.length);

    int e;
    DeleteSeqList(L, 3, e);
    printf("\n测试删除操作\n");
    printf("e = %d\n", e);
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\nL.length = %d\n", L.length);

    int x = 8;
    ChangeSeqList(L, 4, x);
    printf("\n测试改值操作\n");
    printf("e = %d\n", x);
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\nL.length = %d\n", L.length);

    int p;
    ValueSearch(L, p, 8);
    printf("\n测试按值查找操作(单值相同)\n");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\np = %d\n", p);

    SeqList L1;
    InitSeqList(L1);
    VSearch(L, L1, 9);
    printf("\n测试按值查找操作(多值相同)\n");
    printf("L1 : ");
    for(int j=0; j<L1.length; j++){
        printf("%d ", L1.data[j]);
    }
    printf("\n");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\nL1.length = %d\n", L1.length);
}