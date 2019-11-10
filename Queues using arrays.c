#include <stdio.h>
#include <stdlib.h>
#define size 30
int r=-1,f=-1,item,ditem,q[size],i=0;
void insert()
{
    if(r==size-1)
        printf("Queue is full\n");
    else
    {
        printf("Enter the number\n");
        scanf("%d",&item);
        if(f==-1&&r==-1)
        {
            r=0;
            f=0;
        }
        else
            r++;
        q[r]=item;
    }
}
void delete_1()
{
    if(f==-1)
        printf("Queue is empty\n");
    else
    {
        ditem=q[f];
        printf("Deleted item is %d\n",ditem);
        if(f==r)
            f=r=-1;
        else
            f++;
    }
}
void display()
{
    if(f==-1)
        printf("Queue is empty\n");
    else
    {
        for(i=f;i<=r;i++)
            printf("%d->",q[i]);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter a choice\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
                break;
            case 2:delete_1();
                break;
            case 3: display();
                break;
            case 4:exit(0);
                break;
        }
    }
