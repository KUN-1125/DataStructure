#include "c.h"

// 定义一个双链表
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 判断非空
int DL_Empty(DLinkList L)
{
    if (L->next == NULL)
        return 0;
    return 1;
}

// 头插法建立双链表
DLinkList DL_HeadInsert(DLinkList &L)
{
    L = (DLinkList)malloc(sizeof(DNode));
    L->next = NULL;
    L->prior = NULL;
    int x;
    DNode *s;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next = L->next;
        s->prior = L;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 打印链表
void DL_Print(DLinkList L)
{
    int flag;
    flag = DL_Empty(L);
    if (flag == 0)
        printf("链表为空\n");
    if (flag == 1)
    {
        printf("L: ");
        DNode *p;
        p = L->next;
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
    DLinkList L;
    printf("头插法建立双链表：（9999结束）\n");
    DL_HeadInsert(L);
    DL_Print(L);
    return 0;
}