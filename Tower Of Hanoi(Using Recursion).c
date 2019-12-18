#include <stdio.h>
#include <stdlib.h>
void toh(int n,char from_rod,char to_rod,char aux_rod)
{
    if(n==1)
        printf("Move disk 1 from %c to %c\n",from_rod,to_rod);
    else
    {
        toh(n-1,from_rod,aux_rod,to_rod);
        printf("Move disk %d from %c to %c\n",n,from_rod,to_rod);
        toh(n-1,aux_rod,to_rod,from_rod);
    }

}

void main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    char from_rod='A',to_rod='C',aux_rod='B';
    toh(n,from_rod,aux_rod,to_rod);
}
