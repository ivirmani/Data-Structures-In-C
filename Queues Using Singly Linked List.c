#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
}node;

node *temp,*ptr,*start=NULL,*cur;

int c=1;

void count()
{
    if(start==NULL)
        c=0;
    else
    {
        c=1;
        ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
            c++;
        }
    }
}

void push()
{
    count();
    if(c>4)
        printf("Queue Is Full\n");
    else
    {
        temp=(node*)malloc(sizeof(node));
        temp->link=NULL;
        printf("Enter Node data\n");
        scanf("%d",&temp->data);
        if(start==NULL)
            start=temp;
        else
        {
            temp->link=start;
            start=temp;
        }
    }
}

void pop()
{
    if(start==NULL)
        printf("No data in queue\n");
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            cur=ptr;
            ptr=ptr->link;
        }
        printf("Deleted Item Is %d\n",ptr->data);
        free(ptr);
        cur->link=NULL;
        c--;
    }
}

void display()
{
    if(start==NULL)
        printf("No data in Queue\n");
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("<<-%d",ptr->data);
            ptr=ptr->link;
        }
    }
}

void main()
{
    while(1)
    {
        int ch;
        printf("\n1.Insert\n2.Delete\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("Invalid Choice\nTry Again\n");
        }
    }
}
