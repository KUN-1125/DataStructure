#include "c.h"

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *NoHeadList;

// 判断链表是否为空
int List_Empty(NoHeadList L)
{
    if (L == NULL)
        return 0;
    return 1;
}

// 头插法建立链表
NoHeadList List_HeadInsert(NoHeadList &L)
{
    L = (NoHeadList)malloc(sizeof(LNode));
    L = NULL;
    int x;
    LNode *s;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L;
        L = s;
        scanf("%d", &x);
    }
    return L;
}

// 尾插法建立链表
NoHeadList List_TailInsert(NoHeadList &L)
{
    L = (NoHeadList)malloc(sizeof(LNode));
    L = NULL;
    int x;
    LNode *s;
    LNode *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        if (r == NULL)
        {
            L = s;
            r = s;
        }
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return L;
}

// 打印链表
void Print_List(NoHeadList L)
{
    int flag;
    flag = List_Empty(L);
    if (flag == 0)
        printf("链表为空\n");
    if (flag == 1)
    {
        LNode *p = L;
        printf("L: ");
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

int main()
{
    NoHeadList L;
    printf("头插法建立链表：（9999结束）\n");
    List_HeadInsert(L);
    Print_List(L);
    printf("尾插法建立链表：（9999结束）\n");
    List_TailInsert(L);
    Print_List(L);
    return 0;
}