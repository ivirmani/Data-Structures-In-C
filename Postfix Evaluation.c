#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
char postfix[30],ch;
int num,res,s[30],top=-1,op2,op1,j;
void push(int num)
{
	s[++top]=num;
}
int pop()
{
	return(s[top--]);
}
void main()
{
	printf("Enter The Postfix Expression\n");
	gets(postfix);
	while(postfix[j]!='\0')
	{
		ch=postfix[j];
		if(isalpha(ch))
		{
			printf("Enter the number\n");
			scanf("%d",&num);
			push(num);
		}
		else
		{
			op1=pop();
			op2=pop();
		}
		switch(ch)
		{
			case'+':res=op1+op2;
				 push(res);
				 break;
			case'*':res=op1*op2;
				 push(res);
				 break;
			case'/':res=op1/op2;
				 push(res);
				 break;
			case'-':res=op1-op2;
				 push(res);
				 break;
		}
	j++;
	}
	printf("Output - %d\n",s[top]);
}
