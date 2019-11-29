#include <stdio.h>
#include <stdlib.h>
#define size 5
int cq[size],r=-1,f=-1,i=0,item,ditem;
void insert()
{
    if(r==f-1||(f==0&&r==size-1))
        printf("overflow\n");
    else
    {
        printf("Enter the element\n");
        scanf("%d",&item);
        if(f==-1)
            f=0;
        r=(r+1)%size;
        cq[r]=item;
    }

}
void delete()
{
    if(f==-1&&r==-1)
        printf("Underflow\n");
    else
    {
        ditem=cq[f];
        printf("Deleted item is %d",ditem);
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
            f=(f+1)%size;
    }
}
void display()
{
    if(f==-1&&r==-1)
        printf("CQ is empty\n");
    else
    {
        for(i=f;i<r;i=(i+1)%size)
            printf("%d->",cq[i]);
        printf("%d->",cq[i]);
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
            case 2:delete();
                break;
            case 3: display();
                break;
            case 4:exit(0);
                break;
        }
    }
}
