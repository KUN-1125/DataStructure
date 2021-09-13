#include "c.h"
#define Elemtype int

typedef struct BiNode
{
    Elemtype data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

struct Tree
{
    BiTree root;
};

// 插入结点
void Insert(Tree *Tree, Elemtype value)
{
    BiNode *node;
    node = (BiTree)malloc(sizeof(BiNode));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;

    if (Tree->root == NULL)
    {
        Tree->root = node;
    }
    else
    {
        BiNode *temp = Tree->root;
        while (temp != NULL)
        {
            if (value < temp->data)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = node;
                    return;
                }
                else
                {
                    temp = temp->lchild;
                }
            }
            else
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = node;
                    return;
                }
                else
                {
                    temp = temp->rchild;
                }
            }
        }
    }
}

// 先序遍历
void preorder(BiTree node)
{
    if (node != NULL)
    {
        printf("%d\n", node->data);
        preorder(node->lchild);
        preorder(node->rchild);
    }
}

// 中序遍历
void inorder(BiTree node)
{
    if (node != NULL)
    {
        inorder(node->lchild);
        printf("%d\n", node->data);
        inorder(node->rchild);
    }
}

// 后序遍历
void postorder(BiTree node)
{
    if (node != NULL)
    {
        postorder(node->lchild);
        postorder(node->rchild);
        printf("%d\n", node->data);
    }
}

// 求树高
int Get_height(BiNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int Left_hight = Get_height(node->lchild);
        int Right_hight = Get_height(node->rchild);
        int max = Left_hight;
        if (max > Right_hight)
        {
            return max + 1;
        }
        else
        {
            return Right_hight + 1;
        }
    }
}

int main()
{
    int arr[7] = {6, 3, 8, 2, 5, 1, 7};
    Tree tree;
    tree.root = NULL;

    int i;
    for (i = 0; i < 7; i++)
    {
        Insert(&tree, arr[i]);
    }
    preorder(tree.root);
    printf("---------\n");
    inorder(tree.root);
    int height;
    height=Get_height(tree.root);
    printf("--------\n");
    printf("%d\n",height);
    return 0;
}