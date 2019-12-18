#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;

node *start=NULL,*temp,*cur,*ptr,*temp1,*temp2;

void insert()
{
    temp=(node*)malloc(sizeof(node));
    temp->link=NULL;
    printf("Enter Node Data\n");
    scanf("%d",&temp->data);
    if(start==NULL)
        start=temp;
    else
    {
        temp->link=start;
        start=temp;
    }
}

void display()
{
    if(start==NULL)
        printf("No Data In List\n");
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

void rev()
{
    int count=1,i=0;
    if(start==NULL)
        printf("No Data In List\n");
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            cur=ptr;
            ptr=ptr->link;
            count++;
        }
        temp=cur->link;
        cur=cur->link;
        ptr=start;
        temp1=ptr->link;
        for(i=0;i<(count/2);i++)
        {
            temp2->data=ptr->data;

        }
    }
}

void main()
{
    while(1)
    {
        int ch;
        printf("\n1.Insert\n2.Reverse\n3.Display\n4.Exit\nEnter A Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
            break;
            case 2:rev();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            default:printf("Invalid Choice\nTry Again\n");
            break;
        }
    }
}
