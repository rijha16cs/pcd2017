#include<stdio.h>


int reverse(int num)
{
	int d,rev=0;
	while (num!=0)
	{
		d=num%10;
		rev=rev*10+d;
		num=num/10;
	}
return rev;
}
int main()
{	
	int num,rev;
	printf("Enter the number u want to reverse:\n");
	scanf("%d",&num);
	rev=reverse(num);
	printf("The reverse number is:%d\n",rev);
}

