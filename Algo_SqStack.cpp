#include "c.h"
#define MaxSize 10
typedef int Elemtype;

// 定义顺序栈
typedef struct SqStack
{
    Elemtype data[MaxSize];
    int top;
} SqStack;

typedef struct BCStack
{
    char data[MaxSize];
    int top;
} BCStack;

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

// 括号匹配
bool BracketCheck(char str[], int length)
{
    BCStack S;
    S.top = -1;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            // Push(S,str[i]);
            if (S.top == MaxSize - 1)
                return false;
            S.data[++S.top] = str[i];
        }
        else
        {
            // StackEmpty(S);
            if (S.top == -1)
                return false;
            // Pop(S,topElem);
            char topElem;
            topElem = S.data[S.top--];
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    if (S.top == -1)
        return true;
    return false;
}

int main()
{
    // SqStack S;
    // InitStack(S);
    // Push(S, 8);
    // Push(S, 1);
    // Push(S, 9);
    // Stack_Print(S);
    // int x;
    // Pop(S, x);
    // printf("x = %d\n", x);
    // Stack_Print(S);
    // return 0;
    char str[10];
    strcpy(str,"({}{[]}]");
    int x;
    bool i;
    i=BracketCheck(str,8);
    if(i==true)
        x=1;
    if(i==false)
        x=0;
    printf("%d",x);
}