#include <stdio.h>
int factorial (int n)
{
	if (n==0||n==1)
	{
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}
int main()
{
	int n,fact;
	printf("Enter the number to find factorial: ");
	scanf("%d",&n);
	fact=factorial(n);
	printf("%d!=%d",n,fact);
	return 0;
}


