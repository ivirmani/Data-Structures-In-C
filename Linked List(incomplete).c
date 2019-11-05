#include<stdio.h>
#include<stdlib.h>
int i=0;
struct node
{
	int data;
	struct node *link;
};struct node *ptr,*start=NULL,*temp,*cur;
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
		if(start->link==NULL)
		{
			start=NULL;
		}
		ptr=start;
		start=start->link;
		free(ptr);
	}
}
void delete_pos()
{
	int count=0,i,pos;
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("Enter the position of ther node to be deleted\n");
	scanf("%d",&pos);
	if(pos==1)
		delete_beg();
	else if(pos==count)
		delete_end();
	else if(pos>1&&pos<count)
	{
		ptr=start;
		for(i=2;i<pos;i++)
			ptr=ptr->link;
			temp=ptr->link;
			ptr->link=temp->link;
			printf("\nDeleted %d\n",temp->data);	
			free(temp);
			count--;
		
	}
}
void delete_end()
{
	if(start==NULL)
		printf("Empty\n");
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		{
			cur=ptr;
			ptr=ptr->link;
		}
		cur->link=NULL;
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
		printf("1.Insert Beginning\n2.Insert End\n3.Display\n4.Delete End\n5.Delete Beginning\n6.Delete any position\nEnter The Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:insert_beg();
		      break;
		case 2:insert_end();
		      break;
		case 3:display();
		      break;
		case 4:delete_end();
		      break;
		case 5:delete_beg();
		      break;
		case 6:delete_pos();
		      break;
		}
	}
}
