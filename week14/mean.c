#include <stdio.h>
#include <math.h>
int main()
{
	int i,n;
	float a[50],sum=0,mean,var=0,sd=0;
	printf("Enter the value of n:");
		
	scanf("%d",&n);
	printf("Enter the %d numbers:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%f",(a+i));
	}
	
	for(i=0;i<n;i++)
	{
		sum=sum+(*(a+i));
	}
	printf("Sum=%f\n",sum);
	mean=sum/n;
	printf("Mean=%f\n",mean);
	
	for(i=0;i<n;i++)
	{
		var=var+pow(*(a+i)-mean,2);
	}
	var=var/n;
	sd=sqrt(var);
	printf("Standard deviation=%f\n",sd);
	return 0;
}
	
