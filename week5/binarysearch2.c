#include<stdio.h>
#include<string.h>
void main()
{
	int i,first,last,mid,n;
	char names[5][20],search[10];
	printf("Enter the number of strings\n");
	scanf("%d",&n);
	printf("Enter the strings \n");
	for(i=0;i<n;i++)
	  {
	    scanf("%s",names[i]);
	  }

	printf("Enter the string to be searched\n");
	scanf("%s",search);

	first=0;
	last=n-1;

	while(first<=last)
	 {
	  mid=(first+last)/2;
	  if(strcmp(names[mid],search)==0)
	    {
	      printf("The elememt is found and is in the position %d \n",mid+1);
	      break;
	    }
	  else if(strcmp(names[mid],search)>0)
	   {
	     last=mid-1;
	   }
	  else if(strcmp(names[mid],search)<0)
	   {
	     first=mid+1;
	   }
	  else
	   {
	   printf("The elments is not found\n");
	   }
	 }
}
