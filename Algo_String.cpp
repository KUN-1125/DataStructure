#include "c.h"
#define MaxLen 255
typedef struct SString
{
    char ch[MaxLen];
    int length;
} SString;

// 暴力匹配算法
int Index(SString S, SString T)
{
    int i = 1, j = 1;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length)
        return i - T.length;
    else
        return 0;
}

int main()
{
    SString T;
    strcpy(T.ch, "lky");
    T.length = strlen(T.ch);
    printf("%d\n", T.length);
    SString S;
    strcpy(S.ch, "kahlfhuipwahglahilkyaoigius");
    int i;
    i = Index(S, T);
    printf("%d\n", i);
}