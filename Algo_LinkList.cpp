#include "c.h"

// 定义一个结点/单链表
// LNode *：强调结点
// LinkList：强调单链表
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 头插法建立单链表(即逆向建立单链表)
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x = 0;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) //输入9999即结束插入
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 尾插法建立单链表(正向)
LinkList List_TailInsert(LinkList &L)
{
    LNode *s;
    int x = 0;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *r = L; //r为表尾指针
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 打印链表L
bool Print_LinkList(LinkList L)
{
    if (L->next == NULL)
        return false;
    LNode *p;
    p = L->next;
    printf("L : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return true;
}

int main()
{
    LinkList L;
    List_HeadInsert(L);
    Print_LinkList(L);
    List_TailInsert(L);
    Print_LinkList(L);
    return 0;
}