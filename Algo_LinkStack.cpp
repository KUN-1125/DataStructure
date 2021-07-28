#include "c.h"
typedef int ElemType;

// 定义链栈
typedef struct Linknode
{
    ElemType data;
    struct Linknode *next;
} * LinkStack;

// 初始化
void InitStack(LinkStack &S)
{
    S = (LinkStack)malloc(sizeof(Linknode));
    S = NULL;
}

// 判栈空
bool StackEmpty(LinkStack S)
{
    if (S == NULL)
        return true;
    return false;
}

// 进栈
LinkStack Push(LinkStack &S, ElemType x)
{
    Linknode *s;
    s=(Linknode*)malloc(sizeof(Linknode));
    s->data = x;
    if (S == NULL)
    {
        s->next = NULL;
        S = s;
    }
    else
    {
        s->next = S;
        S = s;
    }
    return S;
}

// 出栈
bool Pop(LinkStack &S, ElemType &x){
    if(S==NULL)
        return false;
    x=S->data;
    S=S->next;
    return true;
}

// 读取栈顶元素
bool GetTop(LinkStack S, ElemType &x){
    if(S==NULL)
        return false;
    x=S->data;
    return true;
}

// 打印栈
bool Stack_Print(LinkStack S){
    Linknode *p;
    if(S==NULL)
        return false;
    p=S;
    printf("S : ");
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return true;
}

int main()
{
    LinkStack S;
    InitStack(S);
    Push(S, 8);
    Push(S, 1);
    Push(S, 9);
    Stack_Print(S);
    int x;
    Pop(S, x);
    printf("x = %d\n", x);
    Stack_Print(S);
    return 0;
}