#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} Node;
typedef struct
{
    Node *root;
} Tree;
void Charu (Tree *tree,int charu)
{
    Node* node=malloc(sizeof(Node));
    node->data=charu;
    node->lchild=NULL;
    node->rchild=NULL;
    if(tree->root==NULL)
        tree->root=node;
    else
    {
        Node *temp=tree->root;
        while(temp)
        {
            if(charu<temp->data)
            {
                if(temp->lchild==NULL)
                {
                    temp->lchild=node;
                    return ;
                }
                else
                    temp=temp->lchild;
            }
            else
            {
                if(temp->rchild==NULL)
                {
                    temp->rchild=node;
                    return ;
                }
                else
                    temp=temp->rchild;
            }
        }
    }

}
void xxpl(Node *node)
{
    if(node!=NULL)
    {
        printf("%d  ",node->data);
        xxpl(node->lchild);
        xxpl(node->rchild);
    }
}
void zxbl(Node *node)
{
    if(node!=NULL)
    {
        zxbl(node->lchild);
        printf("%d  ",node->data);
        zxbl(node->rchild);
    }
}
void hxbl(Node *node)
{
    if(node!=NULL)
    {
        hxbl(node->lchild);
        hxbl(node->rchild);
        printf("%d  ",node->data);
    }
}

int main()
{
    Tree tree;
    tree.root=NULL;
 //   printf("%d",tree.root.data);
    int i,a[8]= {7,3,1,8,9,4,2};
    for(i=0; i<8; i++)
    {
        Charu(&tree,a[i]);
    }
    printf("前序遍历\n");
    xxpl(tree.root);
    printf("\n");
    printf("中序遍历\n");
    zxbl(tree.root);
    printf("\n");
    printf("后序遍历\n");
    hxbl(tree.root);

}
