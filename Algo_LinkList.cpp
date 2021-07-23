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
    while (x != 9999) // 输入9999即结束插入
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
    LNode *r = L; // r为表尾指针
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

// 按序号查找结点值
LNode *GetElem(LinkList L, int i)
{
    int j = 1; // 计数
    LNode *p;
    p = L->next;
    if (i == 0)
        return L; // i=0，返回头结点L
    if (i < 1)
        return NULL;
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找表结点
// 从单链表的第一个结点开始，由前往后依次比较各结点数据域的值，若等于e，则返回该结点的指针，若没找到，返回NULL
LNode *LocateElem(LinkList L, int e)
{
    LNode *p;
    p = L->next;
    while (p && p->data != e)
        p = p->next;
    return p;
}

// 插入结点操作
// 将值为x的新结点插入到单链表的第i个位置上
// 先检查插入位置的合法性，再找到第i-1个结点，再在其 后 插入新结点
LinkList LNode_Insert(LinkList &L, int i)
{
    if (i < 0)
        return L;
    LNode *p;
    p = GetElem(L, i - 1);
    int x;
    LNode *s;
    s = (LNode *)malloc(sizeof(LNode));
    scanf("%d", &x);
    s->data = x;
    s->next = p->next;
    p->next = s;
    return L;
}

// 删除结点操作
// 将第i个位置的结点删除并返回L
// 先检查i的合法性，再找到第i-1个结点，删除i结点
LinkList LNode_Delete(LinkList &L, int i)
{
    if (i < 1)
        return L;
    LNode *p, *q;
    p = GetElem(L, i - 1);
    q = p->next;
    p->next = q->next;
    free(q);
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
    LNode *p;
    p = GetElem(L, 3);
    printf("%d\n", p->data);
    LNode_Insert(L, 3);
    Print_LinkList(L);
    LNode_Delete(L, 3);
    Print_LinkList(L);
    return 0;
}