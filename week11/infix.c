#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define max 20

int top=-1;
char s[max];

void push(char ele)
{
	if(top==max-1)
		printf("overflow");
	else
	{	
		top=top+1;	
		s[top]=ele;
	}
}

char pop()
{
	char del;
	if(top==-1)
		printf("underflow");
	else
	{
		del=s[top];
		top=top-1;
	}
	return (del);
}

int priority(char c)
{
	if(c=='#')
		return 0;
	else if(c=='+'||c=='-')
		return 2;
	else if(c=='(')
		return 1;
	else if(c=='*'||c=='/'||c=='%')
		return 3;
	else if(c=='^')
		return 4;
}

int main()
{
	int i=0,j=0;
	char infix[max],postfix[max];
	printf("Enter the infix string\n");
	scanf("%s",infix);
	push('#');
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]=='(')
			push(infix[i]); 
		else if(isalnum(infix[i]))
		{
			postfix[j++]=infix[i];
			
		}
		
		else if(infix[i]==')')
		{
			while(s[top]!='(')
			{
				postfix[j++]=pop();
			}
			top--;
		}
		
		else 
		{
			while(priority(s[top])>=priority(infix[i]))
			{
				postfix[j++]=pop();							
			}
			push(infix[i]);
		}
	}

	while (s[top]!='#')
	{
		postfix[j++]=pop();	
	}
	postfix[j]='\0';
	printf("postfix is:\t %s\n",postfix);
	return 0;
}

















 
