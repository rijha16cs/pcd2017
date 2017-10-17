#include <stdio.h>
#include <stdlib.h>

struct student
{
	char usn[10];
	char name[20];
	char branch[50];
	char sem[5];
	char phone[10];
	struct student *link;
};
typedef struct student STUDENT;
STUDENT *start=NULL;
STUDENT* create()
{
	STUDENT* newnode;
	newnode=(STUDENT*)malloc(sizeof(STUDENT));
	if(newnode==NULL)
	{
		printf("error");
	
	}
	else 
	{
	printf("Enter the studen details\n");
	printf("USN\n");
	scanf("%s",newnode->usn);
	printf("Name:\n");
	scanf("%s",newnode->name);
	printf("Branch\n");
	scanf("%s",newnode->branch);
	printf("Semester\n");
	scanf("%s",newnode->sem);
	printf("phone no.\n");
	scanf("%s",newnode->phone);
	newnode->link=NULL;
	return newnode;
	}
}

void create_list()
{
	int i,n;
	STUDENT *node;
	printf("Enter the number of students\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		node=create();
		if(start==NULL)
		{
			start=node;
		}
		else
		{
			node->link=start;
			start=node;

		}
	}
}


void status()
{
	STUDENT *temp;
	int count=0;
	if(start==NULL)
	{
		printf("Empty list\n");
		return;
	}
	temp=start;
	printf("Student details are:\n");
	
	while(temp!=NULL)
	{
		printf("\nUSN %s\n NAME %s\nBRANCH %s\n SEM%s\n PHONE NO.%s",temp->usn,temp->name,temp->branch,temp->sem,temp->phone);
		temp=temp->link;
		count++;
	}
	printf("The number of node are %d",count);
}

void insert_end()
{
	STUDENT *node,*temp;
	node=create();
	if(start==NULL)
	{
		start=node;
		return;
	}
	else
	{
		temp=start;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=node;
	}
}

void delete_end()
{
	STUDENT *temp,*cur;
	temp=start;
	if(start==NULL)
	{
		printf("No nodes found\n");
		return;
	}
	else if (temp->link==NULL)
	{
		printf("The deleted name is %s\n",temp->name);
		free(temp);
		return;
	}
	cur=NULL;
	temp=start;
	while(temp->link!=NULL)
	{
		cur=temp;
		temp=temp->link;
	}
	printf("The deleted name is %s\n",temp->name);
	cur->link=NULL;
	free(temp);
}

void delete_front()
{
	STUDENT *temp;
	temp=start;
	if(temp==NULL)
	{
		printf("Empty list");
		return;
	}
	else if(temp->link==NULL)
	{
		printf("The deleted name is %s\n",temp->name);
		free(temp);
		start=NULL;
	}
	else
	{
		start=temp->link;
		printf("the deleted student name is %s\n ",temp->name);
		free(temp);
	}
}

void insert_front()
{
	STUDENT *node;
	node=create();
	if(start==NULL)
	{
		start=node;
		return;
	}
	node->link=start;
	start=node;
}

int main()
{
	int ch;
	while(1)
	{
		printf("Linked list\n");
		printf("\n1:Create list\n2:status\n3:insert end\n4;delete end\n5:insert front\n6:delete front\n7:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: create_list();
				break;
			case 2: status();
				break;
			case 3: insert_end();
				break;
			case 4: delete_end();
				break;
			case 5: insert_front();
				break;
			case 6: delete_front();
				break;
			case 7: return 0;
			
			default: printf("\nInvalid choice");
		}
	}
	return 0;
}

