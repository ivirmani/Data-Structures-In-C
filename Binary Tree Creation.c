#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *root,*tree,*temp;
void main()
{
    root=(struct node*)malloc(sizeof(struct node));
    printf("Enter The Data\n");
    scanf("%d",&root->data);
    root->llink=NULL;
    root->rlink=NULL;
    create(root);
    printf("Inorder expression of the tree is ");
    inorder(root);
}
int is_lc(struct node *tree)
{
    int ch;
    printf("Do you want to create a left child?\n");
    printf("Press 1 for Yes & 0 for No\n");
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else
        return 0;
}
int is_rc(struct node *tree)
{
    int ch;
    printf("Do you want to create a right child?\n");
    printf("Press 1 for Yes & 0 for No\n");
    scanf("%d",&ch);
    if(ch==1)
        return 1;
    else
        return 0;
}
void create(struct node *tree)
{
    if(is_lc(tree)==1)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data\n");
        scanf("%d",&temp->data);
        tree->llink=temp;
        create(temp);
    }
    else
        tree->llink=NULL;
    if(is_rc(tree)==1)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data\n");
        scanf("%d",&temp->data);
        tree->rlink=temp;
        create(temp);
    }
    else
        tree->rlink=NULL;
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        printf("%d",tree->data);
        inorder(tree->rlink);
    }
}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d",tree->data);
        inorder(tree->llink);
        inorder(tree->rlink);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
        inorder(tree->llink);
        inorder(tree->rlink);
        printf("%d",tree->data);
    }
}
