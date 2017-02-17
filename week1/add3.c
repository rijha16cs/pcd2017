#include<stdio.h>

int add(int x, int y, int z)
{
	int p;
	p=x+y+z;
	return p;
}
int main()
{
	int a,b,c,d;
	printf ("enter three numbers");
	scanf("%d%d%d",&a,&b,&c);
        d=add(a,b,c);
	printf("sum of three numbers is %d",d);
}
        
