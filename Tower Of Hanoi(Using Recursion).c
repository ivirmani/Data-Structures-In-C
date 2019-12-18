#include<stdio.h>
void main()
{
	int n;
	char from_rod='A',aux_rod='B',to_rod='C';
	printf("Enter Number Of Disks\n");
	scanf("%d",&n);
	toh(n,from_rod,to_rod,aux_rod);
}

void toh(n,from_rod,to_rod,aux_rod)
{
	if(n==1)
		printf("Move Disk 1 From %c To %c\n",from_rod,to_rod);
	else
	{
		toh(n-1,from_rod,aux_rod,to_rod);
		printf("Move Disk %d From %c To %c\n",n,from_rod,to_rod);
		toh(n-1,aux_rod,to_rod,from_rod);
	}
}
