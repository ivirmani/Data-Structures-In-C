#include<stdio.h>
#include<stdlib.h>
int i=0;
struct node
{
	int data;
	struct node *link;
};struct node *ptr,*start=NULL,*temp;
void insert_beg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&(temp->data));
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else
	{
		temp->link=start;
		start=temp;
	}
}
void insert_end()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data\n");
	scanf("%d",&(temp->data));
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
void delete_beg()
{
	if(start==NULL)
		printf("Empty\n");
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
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
			
			printf("%d\n",ptr->data);
			ptr=ptr->link;
		}
	}
}
void main()
{
	int ch;
        while(1)
	{
		printf("1.Insert Beginning\n2.Insert End\n3.Display\nEnter The Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:insert_beg();
		      break;
		case 2:insert_end();
		      break;
		case 3:display();
		      break;
		case 4:exit(0);
		}
	}
}
