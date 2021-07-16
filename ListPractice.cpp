#include"c.h"
#include"ListPractice.h"

int main(){
    SqList L;
    InsertSqList(L,1,3);
    InsertSqList(L,2,6);
    InsertSqList(L,3,4);
    InsertSqList(L,4,2);
    InsertSqList(L,5,5);
    InsertSqList(L,6,7);
    InsertSqList(L,7,9);
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");

    printf("\n测试DeleteMin():\n");
    int m;
    DeletMin(L,m);
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");
    printf("m = %d\n", m);

    Reverse(L);
    printf("\n测试Reverse():\n");
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");

    InsertSqList(L,7,4);
    InsertSqList(L,8,8);
    InsertSqList(L,9,4);
    printf("\n测试Del_x_L():\n");
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    Del_x_L(L,4);
    printf("\n");
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");

    Del_st_L(L,4,8);
    printf("\n测试Del_st_L():\n");
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");

    InsertSqList(L,4,9);
    InsertSqList(L,5,3);
    InsertSqList(L,6,8);
    InsertSqList(L,7,3);
    InsertSqList(L,8,9);
    InsertSqList(L,9,8);
    printf("\n测试Del_Same():\n");
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    Del_Same(L);
    printf("\n");
    printf("L : ");
    for(int i = 0; i < L.length; i++){
        printf("%d ",L.data[i]);
    }
    printf("\n");

    SqList A, B, C;
    InsertSqList(A,1,1);
    InsertSqList(A,2,2);
    InsertSqList(A,3,3);
    InsertSqList(B,1,1);
    InsertSqList(B,2,2);
    InsertSqList(B,3,3);
    InsertSqList(B,4,4);

    printf("\n测试Merge():\n");
    printf("A : ");
    for(int i = 0; i < A.length; i++){
        printf("%d ",A.data[i]);
    }
    printf("\n");
    printf("B : ");
    for(int i = 0; i < B.length; i++){
        printf("%d ",B.data[i]);
    }
    printf("\n");

    Merge(A,B,C);
    printf("C : ");
    for(int i = 0; i < C.length; i++){
        printf("%d ",C.data[i]);
    }
    printf("\n");

}