#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;
node *start=NULL,*ptr,*temp,*cur,*last;


void insert_beg()
{
    temp=(node*)malloc(sizeof(node));
    temp->link=NULL;
    printf("Enter Node Data\n");
    scanf("%d",&temp->data);
    if(start==NULL)
    {
        start=temp;
        temp->link=start;
    }
    else
    {
        temp->link=start;
        ptr=start;
        while(ptr->link!=start)
            ptr=ptr->link;
        ptr->link=temp;
        start=temp;
    }
}


void delete_any()
{
    if(start==NULL)
        printf("No Elements In List\n");
    else
    {
        int pos,count=1,i;
        printf("Enter The Position To Be Deleted\n");
        scanf("%d",&pos);
        ptr=start;
        while(ptr->link!=start)
        {
            ptr=ptr->link;
            count++;
        }
        if(count==1)
        {
            printf("Deleted Element Is %d\n",start->data);
            free(start);
            start=NULL;
        }
        else if(pos==1)
        {
            cur=start->link;
            ptr=start;
            while(ptr->link!=start)
                ptr=ptr->link;
            ptr->link=cur;
            printf("Deleted Node Is %d\n",start->data);
            free(start);
            start=cur;
        }
        else if(pos>1&&pos<=count)
        {
            ptr=start;
            for(i=1;i<pos;i++)
            {
                cur=ptr;
                ptr=ptr->link;
            }
            printf("Deleted Node Is %d\n",ptr->data);
            cur->link=ptr->link;
            free(ptr);
        }
        else
            printf("Invalid Position\n");
    }
}


void display()
{
    if(start==NULL)
        printf("No Elements In List\n");
    else
    {
        ptr=start;
        while(ptr->link!=start)
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
        printf("\n1.Insert_beg\n2.Delete_any\n3.Display\n4.Exit\nEnter A Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert_beg();
            break;
            case 2:delete_any();
            break;
            case 3:display();
            break;
            default:exit(0);
        }
    }
}
