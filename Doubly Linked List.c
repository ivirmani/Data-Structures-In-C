#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *start=NULL,*temp,*cur,*ptr;
void insert_beg()
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
void delete_end()
{
     if(start==NULL||start->rlink==NULL)
        delete_beg();
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL)
            ptr=ptr->rlink;
        ptr->llink->rlink=NULL;
        printf("Deleted node is %d\n",ptr->data);
        free(ptr);
    }
}
void delete_any()
{
    int pos,count=1,i=1;
    ptr=start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
            count++;
        }
    printf("Deleting position\n");
    scanf("%d",&pos);
    if(pos>count)
        printf("Out of Bounds\n");
    else if(pos==1)
        delete_beg();
    else if(pos==count)
        delete_end();
    else
    {
        ptr=start;
        while(i<pos)
        {
            ptr=ptr->rlink;
            i++;
        }
        ptr->llink->rlink=ptr->rlink;
        ptr->rlink->llink=ptr->llink;
        printf("Deleted node is %d\n",ptr->data);
    }
}
void insert_any()
{
    int pos,count=1,i=1;
    ptr=start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
            count++;
        }
    printf("Insert position\n");
    scanf("%d",&pos);
    if(pos>count)
        printf("Out of Bounds\n");
    else if(pos==1)
        insert_beg();
    else if(pos==count)
        insert_end();
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data\n");
        scanf("%d",&temp->data);
        temp->llink=NULL;
        temp->rlink=NULL;
        ptr=start;
        while(i<pos)
        {
            ptr=ptr->rlink;
            i++;
        }
        temp->llink=ptr->llink;
        temp->rlink=ptr;
        ptr->llink=ptr->llink->rlink=temp;

    }
}
void delete_beg()
{
    if(start==NULL)
        printf("List is empty\n");
    else if(start->rlink==NULL)
        {
            printf("Deleted node is %d\n",start->data);
            free(start);
            start=NULL;

        }
    else
    {
        ptr=start;
        start=ptr->rlink;
        ptr->rlink->llink=NULL;
        printf("Deleted node is %d",ptr->data);
        free(ptr);
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
        printf("\n1.Display\n2.Insert_beg\n3.Insert_end\n4.Delete_beg\n5.Delete_end\n6.Insert_any\n7.Delete_any\n8.Exit\nEnter a choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:display();
                    break;
            case 2:insert_beg();
                    break;
            case 3:insert_end();
                    break;
            case 4:delete_beg();
                    break;
            case 5:delete_end();
                    break;
            case 6:insert_any();
                    break;
            case 7:delete_any();
                    break;
            case 8:exit(0);
                    break;
        }
    }
}
