#include <stdio.h>
#include <stdlib.h>

struct employee
{
	char ssn[10];
	char name[20];
	char depart[50];
	char design[10];
	char salary[10];
	char phone[10];
	struct employee *llink;
	struct employee *rlink;
};
typedef struct employee node;

node *start=NULL;
node* create()
{
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
	{
		printf("error");
	}
	else 
	{	
		printf("Enter the employee details\n");
		printf("SSN\n");
		scanf("%s",newnode->ssn);
		printf("Name:\n");
		scanf("%s",newnode->name);
		printf("Department\n");
		scanf("%s",newnode->depart);
		printf("Designation\n");
		scanf("%s",newnode->design);
		printf("Salary\n");
		scanf("%s",newnode->salary);
		printf("phone no.\n");
		scanf("%s",newnode->phone);
		newnode->llink=NULL;
		newnode->rlink=NULL;
		return newnode;
	}
}

void create_list()
{
	int n,i;
	node *new,*temp;
	printf("Enter the no. of employee details to be entered:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		new=create();
		if(start==NULL)
		{
			start=new;
		}
		else
		{
			temp=start;
			while(temp->rlink!=NULL)
			{
				temp=temp->rlink;
			}
			temp->rlink=new;
			new->llink=temp;
		}
	}
}	
void status()
{
	node *temp;
	int count=0;
	if(start==NULL)
	{
		printf("Empty list\n");
		return;
	}
	temp=start;
	printf("Employee details are:\n");
	
	while(temp!=NULL)
	{
		printf("\nSSN %s\n NAME %s\nDepatment %s\n Designation%s\nSalary%s\n PHONE NO.%s\n",temp->ssn,temp->name,temp->depart,temp->design,temp->salary,temp->phone);
		temp=temp->rlink;
		count++;
	}
	printf("The number of node are %d\n",count);
}

void insert_front()
{
	node *new;
	new=create();
	if(start==NULL)
	{
		start=new;
		return;
	}
	new->rlink=start;
	start->llink=new;
	start=new;
}

void insert_end()
{
	node *new,*temp;
	new=create();
	if(start==NULL)
	{
		start=new;
		return;
	}
	else
	{
		temp=start;
		while(temp->rlink!=NULL)
		{
			temp=temp->rlink;
		}
		temp->rlink=new;
		new->llink=temp;
	}
}

void delete_front()
{
	node *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("Empty list");
		return;
	}
	else if(temp->rlink==NULL)
	{
		printf("The deleted name is %s\n",temp->name);
		free(temp);
		start=NULL;
	}
	else
	{
		start=start->rlink;
		printf("the deleted employee name is %s\n ",temp->name);
		free(temp);
		start->llink=NULL;
	}
}

void delete_end()
{
	node *temp,*cur;
	temp=start;
	if(start==NULL)
	{
		printf("No nodes found\n");
		return;
	}
	else if (temp->rlink==NULL)
	{
		printf("The deleted name is %s\n",temp->name);
		free(temp);
		return;
	}
	cur=NULL;
	temp=start;
	while(temp->rlink!=NULL)
	{
		cur=temp;
		temp=temp->rlink;
	}
	printf("The deleted name is %s\n",temp->name);
	cur->llink=NULL;
	free(temp);
}

void double_ended_queue()
{
	int ch;
	while(1)
	{
		printf("double ended queue\n");
		printf("1:insert front\n2:delete front\n3:insert end\n4:delete end\n5:Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: insert_front();
				break;
			case 2: delete_front();
				break;
			case 3: insert_end();
				break;
			case 4: delete_end();
				break;
			case 5: exit(0);
			default: printf("\nInvalid choice");	
		}
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Doubly Linked list\n");
		printf("\n1:Create list\n2:insert end\n3:status\n4:delete end\n5:delete front\n6:double ended queue implementation\n7:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: create_list();
				break;
			case 2: insert_end();
				break;
			case 3: status();
				break;
			case 4: delete_end();
				break;
			case 5: delete_front();
				break;
			case 6: double_ended_queue();
				break;
			case 7: return 0;
			
			default: printf("\nInvalid choice");
		}
	}
	return 0;
}










