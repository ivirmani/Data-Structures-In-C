#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int ch,s[SIZE],item,ditem,top=-1,i=0;
void push()
{
	if(top==SIZE-1)
	{
		printf("Stack Overflow\n\n");
	}
	else
	{
		printf("Enter The Element\n");
		scanf("%d",&item);
		s[++top]=item;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("Stack Underflow\n\n");
	}
	else
	{
		printf("%d\n\n",s[top--]);
	}
}
void display()
{
	if(top==-1)
	{
		printf("Stack Is Empty\n\n");
	}
	else
	{
		for(i=0;i<=top;i++)
			printf("%d--> ",s[i]);
	}
	printf("\n");
}
void main()
{
	while(1)
	{
		printf("\n\nMENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter A Choice\n");
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
		}
	}
}
