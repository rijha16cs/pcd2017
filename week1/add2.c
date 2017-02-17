#include<stdio.h>

int add(int a,int b)
{
	int c;
	c=a+b;
	return c;
}

int main()
{
	int x,y,z;
	printf("Enter two numbers");
	scanf("%d%d",&x,&y);
	z=add(x,y);
	printf("\nThe sum of two numbers =%d",z);
}

