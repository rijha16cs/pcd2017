#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct term
{
	int cf;
	int px;
	int py;
	int pz;
	int flag;
	struct term *link;
};
typedef struct term *node;
node create()
{
	node new;
	new=(node)malloc(sizeof(struct term));
	new->link=new;
	return new;
}
node insert_rear(int cof,int pox,int poy,int poz,node head)
{
	node new,temp;
	new=create();
	new->cf=cof;
	new->px=pox;		
	new->py=poy;
	new->pz=poz;
	temp=head->link;
	while(temp->link!=head)
	{
		temp=temp->link;
	}
	temp->link=new;
	new->link=head;
	return head;
}
node readp(node head)
{		
	node t;
	int cf,px,py,pz;
	for(;;)
	{
		printf("Enter the coefficent:");
		scanf("%d",&cf);
		if(cf==0)
			break;
		printf("Power of x,y and z");
		scanf("%d%d%d",&px,&py,&pz);
		head=insert_rear(cf,px,py,pz,head);
	}
	return head;
}

void display(node head)
{
	node temp;
	if(head->link==head)
	{
	printf("Empty");
	return;
	}
	temp=head->link;
	while(temp->link!=head)
	{
		printf("%dx^%dy^%dz^%d+",temp->cf,temp->px,temp->py,temp->pz);
		temp=temp->link;
	}
		if(temp->link=head)
		{
			printf("%dx^%dy^%dz^%d\n",temp->cf,temp->px,temp->py,temp->pz);
		}
}
void eval(node head)
{	
	node temp;
	int x,y,z;
	float sum=0;
	printf("Enter x ,y and z:\t");
	scanf("%d%d%d",&x,&y,&z);
	temp=head->link;
	while(temp!=head)
	{
		sum+=temp->cf*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz);
		temp=temp->link;
	}
	printf("\nSum=  %f",sum);
}
node add(node head1,node head2,node head3)	
{	
	node temp1,temp2;
	temp1=head1->link;
	int f;
	while(temp1!=head1)
	{
		temp2=head2->link;
		while(temp2!=head2)
		{
			f=0;
			if(temp1->px==temp2->px&&temp1->py==temp2->py&&temp1->pz==temp2->pz)
			{
				head3=insert_rear(temp1->cf+temp2->cf,temp1->px,temp1->py,temp1->pz,head3);
				temp2->cf=0;
				f=1;
				break;
			}
			else
				temp2=temp2->link;
		}
		if(f==0)
		{
			head3=insert_rear(temp1->cf,temp1->px,temp1->py,temp1->pz,head3);
		}
		temp1=temp1->link;
	}
	temp2=head2->link;
	while(temp2!=head2)
	{
		if(temp2->cf!=0)
		head3=insert_rear(temp2->cf,temp2->px,temp2->py,temp2->pz,head3);
		temp2=temp2->link;
	}
	return head3;
}
int main()
{	
	node head=create();
	node head1,head2,head3,t1;
	head1=create();
	head2=create();
	head3=create();
	int ch;
	while(1)
{
	printf("\n\tMENU\n1.Evaluation\n2.Addition\n3.Display\n4.Exit:");
	printf("\nEnter your choice:\n");	
	scanf("%d",&ch);	
	switch(ch)
	{
	case 1:readp(head);
		display(head);
		eval(head);
		break;
	case 2:head1=readp(head1);
		display(head1);
		head2=readp(head2);
		display(head2);
		head3=add(head1,head2,head3);
		printf("\nThe sum is:\n");
		display(head3);
		break;
	case 3:display(head1);
		break;
	case 4:return 0;
}
}
return 0;
}
