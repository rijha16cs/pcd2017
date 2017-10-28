#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct polynomial
{
	int coef,x,y,z;
	struct node *next;
};

typedef struct polynomial poly;
poly head=NULL;
poly *insert_end(poly *head,int coef,int x,int y,int z)
{
	poly *new, *temp;
	new=(poly*)malloc(sizeof(poly));
	new->coef=coef;
	new->x=x;
	new->y=y;
	new->z=z;
	if(head->next==head)
	{
		head->next=new;
		new->next=head;
		return head;
	}
	temp=head->next;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next=head;
	return head;
}

void input(poly *head)
{
	poly *new,*temp;
	int coef,x,y,z;
	while(1)
	{
		printf("Enter coeffient:\n");
		scanf("%d",&coef);
		if(coef==0)
		{
			break;
		}
		printf("Enter the power of x:\n");
		scanf("%d",&x);
		printf("Enter the power of y:\n");
		scanf("%d",&y);
		printf("Enter the power of z:\n");
		scanf("%d",&z);
		insert_end(head,coef,x,y,z);
	}
}

void display(poly *head)
{
	poly *temp;
	temp=head->next;
	while(temp->next!=head)	
	{
		printf("%d(x)^%d(y)^%d(z)^%d+\n",temp->coef,temp->x,temp->y,temp->z);
		temp=temp->next;
	}
	printf("%d(x)^%d(y)^%d(z)^%d\n",temp->coef,temp->x,temp->y,temp->z);
}

int evaluate(poly *head,int vx,int vy,int vz)
{
	poly *temp;
	int sum=0;
	temp=head->next;
	while(temp!=head)
	{
		sum=sum+(temp->coef*pow(vx,temp->x)*pow(vy,temp->y)*pow(vz,temp->z));
		temp=temp->next;
	}
	return sum;
}

poly *poly_add(poly *head1,poly *head2,poly *head3)
{
	poly *temp1,*temp2;
	int flag;
	temp1=head1->next;
	while(temp1!=head1)
	{
		flag=0;
		temp2=head2->next;
		while(temp2!=head2)
		{
			if((temp1->x==temp2->x)&&(temp1->y==temp2->y)&&(temp1->z==temp2->z))
			{
				head3=insert_end(head3,(temp1->coef)=(temp2->coef),temp2->x,temp2->y,temp2->z);
				temp1->coef=0;
				flag=1;
				break;
			}
			else
			{
				temp2=temp2->next;
			}
		}
		if(flag==0)
		{
			head3=insert_end(head3,temp1->coef,temp1->x,temp1->y,temp1->z);
			temp1=temp1->next;
		}
	}
	temp2=head2->next;
	while(temp2!=head2)
	{
		if(temp2->coef!=0)
		{
			head3=insert_end(head3,temp2->coef,temp2->x,temp2->y,temp2->z);
			temp2=temp2->next;
		}
	}
	return head3;
}

int main()
{
	poly *head1,*head2,*head3;
	int vx,vy,vz,res;
	head1=(poly*)malloc(sizeof(poly));
	head1=head1->next;
	head2=(poly*)malloc(sizeof(poly));
	head2=head2->next;
	head3=(poly*)malloc(sizeof(poly));
	head3=head3->next;
	printf("Polynomial Evaluatuion:\n");
	
	printf("Enter the polynomial1:\n");
	input(head1);
	printf("Entered polynomial1 is:\n");
	display(head1);
	printf("Enter the polynomial2:\n");
	input(head2);
	printf("Entered polynomial2 is:\n");
	display(head2);
	
	head3=poly_add(head1,head2,head3);
	printf("poly1 + poly2 =\n");
	display(head3);
	
	printf("Enter the value of Vx, Vy, Vz\n");
	scanf("%d%d%d",&vx,&vy,&vz);
	
	res=evaluate(head3,vx,vy,vz);
	printf("Evaluated result is %d\n",res);
	
	return 0;
}





