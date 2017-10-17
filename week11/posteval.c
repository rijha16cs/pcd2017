#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define max 20

int top=-1;
float s[max];

void push(float ele)
{
	if(top==max-1)
		printf("overflow");
	else
	{	
		top=top+1;	
		s[top]=ele;
	}
}

float pop()
{
	float del;
	if(top==-1)
		printf("underflow");
	else
	{
		del=s[top];
		top=top-1;
	}
	return (del);
}

float operation(char op,float op1,float op2)
{
	switch(op)
	{
		case '+' :	return(op1+op2);
		case '-' :	return(op1-op2);
		case '*' :	return(op1*op2);
		case '/' :	return(op1/op2);
		case '%' :	return(fmod(op1,op2));
		case '^' :	return(pow(op1,op2));
		default:
			printf("Invalid ");
	}
}
void postfix_exp(char postfix[])
	{ float op1,op2,res;
		int i;
		for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
			push(postfix[i]-'0');
		else
		{
			op2=pop();
			op1=pop();
			res=operation(postfix[i],op1,op2);
			push(res);
		}
	}
	res=pop();
	printf("Value=\t\n%f",res);
}
			

void main()
{
	char postfix[100];
	
	printf("Postfix\n");
	scanf("%s",postfix);
	postfix_exp(postfix);
}
	
	

