#include "c.h"
#define MaxSize 10
typedef int Elemtype;

// 定义顺序栈
typedef struct SqStack
{
    Elemtype data[MaxSize];
    int top;
} SqStack;

// 初始化
void InitStack(SqStack &S)
{
    S.top = -1;
}

// 判栈空
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true;
    return false;
}

// 进栈
bool Push(SqStack &S, Elemtype x)
{
    if (S.top == MaxSize - 1)
        return false; // 栈满
    S.data[++S.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &S, Elemtype &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

// 读取栈顶元素
bool GetTop(SqStack S, Elemtype &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

// 打印栈
bool Stack_Print(SqStack S)
{
    int i = S.top;
    if (i == -1)
        return false;
    printf("S : ");
    for (; i > -1; i--)
        printf("%d ", S.data[i]);
    printf("\n");
    return true;
}

int main()
{
    SqStack S;
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