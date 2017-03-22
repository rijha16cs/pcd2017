#include <stdio.h>
#include <math.h>
unsigned int rightshift(unsigned int x,unsigned int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(x%2==0)
		{
			x=x>>1;
		}
		else
		{
			x=x>>1;
			x=x+(1<<31);
		}
	}
        return x;
	
}
void main()
{
	unsigned int a,b,result;
	printf("Enter the number\n");
	scanf("%u",&a);
	printf("Enter how many times to shift\n");
	scanf("%u",&b);
	result=rightshift(a,b);
	printf("The number after shift is: %u\n",result);
}


