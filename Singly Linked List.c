#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start=NULL,*temp,*ptr,*cur;
void insert_end()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
}
void insert_pos()

{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Node Data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    int count=1,i=0;
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
        count++;
    }
    printf("\nEnter the position of node to be inserted\n");
    int pos1;
    scanf("%d",&pos1);
    if(pos1==1)
        insert_beg();
    else if(pos1==count)
        insert_end();
    else if(pos1>1&&pos1<count)
    {
        ptr=start;
        for(i=1;i<pos1;i++)
        {
            cur=ptr;
            ptr=ptr->link;
        }

        cur->link=temp;
        temp->link=ptr;

    }
    else
        printf("\nInvalid position entered\n");

    }

void insert_beg()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter The Data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        temp->link=start;
        start=temp;
    }
}
void delete_end()
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            cur=ptr;
            ptr=ptr->link;
        }
        printf("\nDeleted element is %d\n",ptr->data);
        cur->link=NULL;
        free(ptr);
    }
}
void delete_beg()
{
    if(start==NULL)
        printf("Linked list is empty\n");
    else
    {
        temp=start;
        start=start->link;
        printf("\nDeleted element is %d\n",temp->data);
        free(temp);
    }
}
void delete_pos()
{
    int count=1,i=0;
    ptr=start;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
        count++;
    }
    printf("\nEnter the position of node to be deleted\n");
    int pos;
    scanf("%d",&pos);
    if(pos==1)
        delete_beg();
    else if(pos==count)
        delete_end();
    else if(pos>1&&pos<count)
    {
        ptr=start;
        for(i=1;i<pos;i++)
        {
            cur=ptr;
            ptr=ptr->link;
        }

        cur->link=ptr->link;
        printf("\nDeleted element is %d\n",ptr->data);

        free(ptr);

    }
    else
        printf("\nInvalid position entered\n");
}
void alt()
{
    if(start==NULL)
        printf("Invalid\n");
    else
    {
        cur=start;
        temp=start->link;
        while(cur!=NULL&&temp!=NULL)
        {
            cur->link=temp->link;
            printf("Deleted Element Is %d\n",temp->data);
            free(temp);
            cur=cur->link;
            if(cur!=NULL)
                temp=cur->link;
        }
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
			ptr=ptr->link;
		}
	}

}
void main()
{
    int ch;
        while(1)
	{
		printf("\n1.Insert Beginning\n2.Insert End\n3.Insert position\n4.Delete End\n5.Delete Beginning\n6.Delete any position\n7.Display\n8.Delete every alternate node\n9.Exit\nEnter The Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:insert_beg();
		      break;
		case 2:insert_end();
		      break;
		case 3:insert_pos();
		      break;
		case 4:delete_end();
		      break;
		case 5:delete_beg();
		      break;
		case 6:delete_pos();
		      break;
        	case 7:display();
              	      break;
        	case 8:delete_alt();
                      break;
        	case 9:exit(0);
		}
	}
}
