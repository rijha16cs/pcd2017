#include <stdio.h>

int leap (int yr)
{
	if(yr%400==0)
	{
		return 0;
	}
	else if(yr%100==0)
	{
		return 1;
	}
	else if (yr%4==0)
	{
		return 2;
	}
	else {
		return -1;
	}
}

int main(){
	int n;
	printf("enter the year to be checked:");
	scanf("%d",&n);
	if(leap(n)){
		printf("it is a leap year");
	}
	else{
		printf("it is not a leap year");
	}
	return 0;
}


