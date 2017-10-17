#include<stdio.h>
#define max 10
int top=-1;
int s[max-1];

void push(int ele)
{
	if(top==max-1)
		printf("overflow");
	else
	{	
		top=top+1;	
		s[top]=ele;
	}
}

int pop()
{
	int del;
	if(top==-1)
		printf("underflow");
	else
	{
		del=s[top];
		top=top-1;
	}
	return del;
}

int pallindrome()
{
	int n,i,flag;
	printf("enter the number of digits");
	scanf("%d",&n);
	printf("enter the digits\n");
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		push(a[i]);
	}

	for(i=0;i<n;i++)
	{	
		if(a[i]==pop())
			flag=1;
		else
		{
			flag=0;			
			break;
		}
		return flag;
}
}
void display()
{
	int i;
	for(i=0;i>-1;i--)
	{
		printf("\t%d",s[i]);
	}
}
int status ()
{
	int r=top;
	return r;
}

void main()
{
	int  ch,f;
	while(1)
	{
		printf("....................\n");
		printf("stack operations\n");
		printf("\n1.push\n2.pull\n3.pallindrome\n4.display\n5.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:  printf("Enter the elemnts to push\n");
				 int ele;
				scanf("%d",&ele);
				 
				push(ele);
				 break;	
		        case 2:  if(top!=-1)
				{
					int d;
					d=pop();
					printf("%d",d);
				}
				else
				{
					printf("underflow\n");
				}
				break;

			case 3: f= pallindrome();
				if(f==0)
				{
					printf("entered element is not pallindrome");
				}
				else
				{
					printf("entered element is pallindrome");
				}
				break;     


			case 4: display();
				break;
			case 5: 
				break;
			default: printf("entered key is invalid");
	
			}
} 
}

	
		
		

