#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int pq[MAX],f=-1,r=-1,item,ditem,data=0,i=0,j=0;
void insert_prior()
{
    printf("enter the data\n");
    scanf("%d",&data);
    if(r==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    else if(r==-1&&f==-1)
    {
        r=0;
        f=0;
        pq[r]=data;
        return;
    }
    else
        check(data);
    r++;
}
void check(int data)
{
    for(i=0;i<=r;i++)
    {
        if(data>pq[i])
        {
            for(j=r;j>=i;j--)
                pq[j+1]=pq[j];
            pq[i]=data;
            return;
        }
    }
    pq[i]=data;
}
void del()
{
    if(f==-1)
        printf("Queue is empty\n");
    else
    {
        ditem=pq[f];
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
            printf("%d->",pq[i]);
    }
}
void main()
{
    int ch;
    while(1)
    {
        printf("\nEnter a choice\n1.InsertPrior\n2.Delete\n3.Display\n4.Check\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert_prior();
                break;
            case 2:del();
                break;
            case 3: display();
                break;
            case 4:check(data);
                break;
            case 5:exit(0);
        }
    }
}
