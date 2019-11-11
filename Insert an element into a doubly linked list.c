#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *start=NULL,*temp,*cur,*ptr;
struct node* insert_beg()
{
    temp=(struct node*)malloc(sizeof( struct node));
    printf("\nEnter the data\n");
    int value;

    scanf("%d",&value);
    temp->data=value;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        temp->rlink=start;
         // printf("%d\n",temp->rlink->data);
        start->llink=temp;
        start=temp;

       // printf("%d\n",start->data);

    }
    return temp;

}
void insert_end()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data\n");
    int value;
    scanf("%d",&value);
    temp->data=value;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(start==NULL)
            start=temp;
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL)
            ptr=ptr->rlink;
        ptr->rlink=temp;
        temp->llink=ptr;
    }
}
void insert()
{

    struct node* tempo=insert_beg();



    ptr=tempo->rlink;
    printf("%d\n",ptr->data);
    printf("%d\n",tempo->data);
    while(ptr!=NULL && (tempo->data>ptr->data))
    {
        int cur=ptr->data;
        ptr->data=tempo->data;
        tempo->data=cur;
        ptr=ptr->rlink;
        tempo=tempo->rlink;
    }
}
void display()
{
    if(start==NULL)
		printf("List Is Empty\n\n");
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("%d-->",ptr->data);
			ptr=ptr->rlink;
		}
	}
}
void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Display\n2.Insert_beg\n3.Insert_end\n4.Insert\n5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:display();
                    break;
            case 2: insert_beg();break;
            case 3:insert_end();
                    break;
            case 4:insert();
                    break;
            case 5:exit(0);
        }
    }
}
