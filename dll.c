#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *start=NULL,*temp,*cur,*ptr;
void insert_beg(struct node *temp)
{
    if(start==NULL)
        start=temp;
    else
    {
        temp->rlink=start;
        start->llink=temp;
        start=temp;
    }
}
void insert_end()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data\n");
    scanf("%d",&temp->data);
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
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data\n");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
    insert_beg(temp);
    ptr=start->rlink;
    while((temp->data>ptr->data)&&ptr!=NULL)
    {
        cur->data=ptr->data;
        ptr->data=temp->data;
        temp->data=cur->data;
        ptr=ptr->rlink;
        temp=temp->rlink;
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

            case 3:insert_end();
                    break;
            case 4:insert();
                    break;
            case 5:exit(0);
        }
    }
}
