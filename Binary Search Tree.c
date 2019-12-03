#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *ptr,*root=NULL,*parent,*temp;
void create()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter The Data\n");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        ptr=root;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(ptr->data==temp->data)
            {
                printf("Node Already Exists\n");
                return;
            }
            else if(temp->data<ptr->data)
                ptr=ptr->llink;
            else
                ptr=ptr->rlink;
        }
        if(parent->data<temp->data)
            parent->rlink=temp;
        else
            parent->llink=temp;
    }
}
void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->llink);
        printf("%d->",temp->data);
        inorder(temp->rlink);
    }
}
void main()
{   int ch=1;

    while(ch!=3)
    {
        printf("\nEnter your choice \n1.create\n2.Inorder\n3.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                break;
            case 2:inorder(root);
                break;
            case 3:exit(0);
        }
    }
}

