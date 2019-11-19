#include<stdio.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;		
};
struct node* ptr,root=NULL,parent,temp;
void create()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter The Data\n");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;
	
}
