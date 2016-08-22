#include <stdio.h>
void DiscMove(int n,char source,char dest,char spare )      //recursive function for tower hanoi algorithm
{
	if(n==1)
	{
		printf("\n Move disk 1 from peg A To peg C");
		return;                                            //returns void to avoid execution afinction listed below 
	                                                       //saves from segmentation fault
	}
	DiscMove(n-1,source,dest,spare);
    printf("\n Move disk %d from peg %c to peg %c\n",n,source,dest);
    DiscMove(n-1,spare,dest,source);
}
int main()
{
   printf("Number of disks  :\n");               //prompt user to input value
   int n;
   scanf("%d",&n);
   DiscMove(n,'A','B','C');                     //recursive call for tower hanoi algorithm starts
   return 0;
}
