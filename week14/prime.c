#include <stdio.h>
int isprime(int n)
{
	int i;
	for(i=2;i<n/2;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
		return 1;
	}
}

int main()
{
	int i, n,n1,n2,check,range;
	printf("Enter the number to be checked for prime number");
	scanf("%d",&n);
	check=isprime(n);
	if(check==1)
	{
		printf("%d is prime number\n",n);
	}
	else
	{
		printf("%d is not prime number\n",n);
	}
	printf("Enter two numbers between which the prime number is to be find out\n");
	scanf("%d%d",&n1,&n2);
	printf("Prime numbers between %d and %d are:\n",n1,n2);
	for(i=n1+1;i<n2;i++)
	{
		range=isprime(i);
		if(range==1)
		{
			printf("%d\t",i);
		}
		printf("\n");
	}
	return 0;
}



		
