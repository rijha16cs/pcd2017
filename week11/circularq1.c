#include <stdio.h>
#define SIZE 5
int f=-1;
int r=-1;


void insert(char q[])
{
	char item;
	printf("enter the character\t");
	scanf(" %c",&item);
	if((r==SIZE-1&&f==0) || f==r+1)
	{
		printf("Overflow");
		return;
	}
	if(f==-1)
		f=0;

	r=(r+1)%SIZE;
	q[r]=item;

}	

void delete(char q[])
{
	char del;
	if(f==-1&&r==-1)
		printf("Queue is empty");
	else
	{
		del=q[f];
		printf("Deleted item=%c",del);
		f=(f+1)%SIZE;
		if(f>r)
		{
			f=-1;
			r=-1;
		}
	}
}

void display(char q[])
{
	int i;
	for(i=f;i!=(r+1);i=(i+1)%SIZE)
	{
		printf("%c \t",q[i]);
	}
}

int main()
{
	int ch;
	char q[SIZE];
	while(1)
	{
		printf("\ncircular queue\n");
		printf("\n1:Insert\n2:delete\n3:display\n4:Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:	insert(q);
				break;
			case 2:	delete(q);	
				break;
			case 3: display(q);
				break;
			case 4: return 0;
			default: printf("Invalid");
				break;
		}
	}
	return 0;
}
	























