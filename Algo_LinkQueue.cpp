#include "c.h"
typedef int ElemType;

// 定义结点
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;
// 定义链队
typedef struct LinkQueue
{
    LinkNode *front, *rear;
} LinkQueue;

// 初始化(带头结点)
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

// 判队空
bool QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
        return true;
    return false;
}

// 入队
bool EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *q;
    q = (LinkNode *)malloc(sizeof(LinkNode));
    q->data = x;
    q->next = NULL;
    Q.rear->next = q;
    Q.rear = q;
    return true;
}

// 出队
bool DeQueue(LinkQueue &Q, ElemType &x)
{
    if (Q.front == Q.rear)
        return false;
    LinkNode *p;
    p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (p == Q.rear)
        Q.rear = Q.front;
    free(p);
    return true;
}

// 打印队
bool PrintQueue(LinkQueue Q){
    if (Q.front == Q.rear)
        return false;
    LinkNode *p;
    p = Q.front->next;
    printf("Q : ");
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return true;
}

int main()
{
    LinkQueue Q;
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