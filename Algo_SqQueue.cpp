#include "c.h"
#define MaxSize 10
typedef int ElemType;
// 定义队列
typedef struct SqQueue
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

// 初始化
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

// 判队空
bool QueueEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    return false;
}

// 入队
bool EnQueue(SqQueue &Q, ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 打印队
bool PrintQueue(SqQueue Q)
{
    if (Q.front == Q.rear)
        return false;
    printf("Q : ");
    int p = Q.front;
    while (p != Q.rear)
    {
        printf("%d ", Q.data[p]);
        p = (p + 1) % MaxSize;
    }
    printf("\n");
    return true;
}

int main()
{
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, 8);
    EnQueue(Q, 1);
    EnQueue(Q, 9);
    PrintQueue(Q);
    int x;
    DeQueue(Q, x);
    printf("x : %d\n", x);
    PrintQueue(Q);
}