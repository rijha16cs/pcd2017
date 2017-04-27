#include <stdio.h>
#include <string.h>
struct student
{
	char names[20],grade[2];
	int roll;
	float marks;
};

int main()
{
	struct student s[5];
	int i;
	char search[20];
	for(i=0;i<5;i++)
	{
		printf("Enter the name");
		scanf("%s",s[i].names);
		printf("Enter the roll number");
		scanf("%d",&s[i].roll);
		printf("Enter the marks");
		scanf("%f",&s[i].marks);
		printf("Enter the grade");
		scanf("%s",s[i].grade);
	}

	printf("Enter the search name");
	scanf("%s",search);
	
	//linear search
	for (i=0;i<5;i++)
	{
		if(strcmp(search,s[i].names)==0)
		{
			printf("Marks of the student is %f",s[i].marks);
			printf("Roll number of the student is %d",s[i].roll);
			printf("Grade of the student is %s",s[i].grade);
return 0;
		}
	}
	
	printf("Record not found");
return 0;
	
}
	

