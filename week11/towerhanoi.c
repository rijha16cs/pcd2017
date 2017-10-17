#include <stdio.h>
void tower(int n,char src,char temp,char dest)
{	
	
	if(n==1)
	{
		printf("\n%d disc is moved from %c to %c\n",n,src,dest);
		return ;
	}
	tower(n-1,src,dest,temp);
	printf("\n%d is moved from %c to %c\n",n,src,dest);
	tower(n-1,temp,src,dest);
}
int main()
{
	int n;
	char src,temp,dest;
	printf("\nEnter the number of disc in source\n");
	scanf("%d",&n);
	
	tower(n,'A','B','C');
	return 0;
}
	
