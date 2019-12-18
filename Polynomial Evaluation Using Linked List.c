#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct node
{
  int coeff;
  int power;
  struct node *link;
}node;

node*start=NULL,*ptr,*temp,*cur;

void create()
{
    temp=(node*)malloc(sizeof(node));
    printf("Enter The Coeff And Power\n");
    scanf("%d%d",&temp->coeff,&temp->power);
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else if(start->power<temp->power)
    {
        temp->link=start;
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr!=NULL&&ptr->power>=temp->power)
        {
            cur=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL)
            cur->link=temp;
        else
        {
            temp->link=cur->link;
            cur->link=temp;
        }
    }
}

void display()
{
    if(start==NULL)
        printf("List Is Empty\n");
    else
    {
        ptr=start;
        while(ptr!=NULL)
        {
            printf("%d %d->>",ptr->coeff,ptr->power);
            ptr=ptr->link;
        }
    }
}

void evaluate()
{
    int sum=0,x;
    if(start==NULL)
        printf("No data in list\n");
    else
    {
        printf("Enter The value Of X\n");
        scanf("%d",&x);
        ptr=start;
        while(ptr!=NULL)
        {
            sum=sum+ptr->coeff*pow(x,ptr->power);
            ptr=ptr->link;
        }
        printf("The Expression Result Is %d\n",sum);
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display\n3.Evaluate\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:evaluate();
            break;
            case 4:exit(0);
            default:printf("Invalid choice\nTry Again\n");
            break;
        }
    }
}
