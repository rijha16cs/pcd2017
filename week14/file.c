#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fp_usn,*fp_studentname,*fp_output;
	char name[20], usn[20];	
	fp_usn=fopen("usn.txt","r");
        fp_studentname=fopen("studentname.txt","r");
	fp_output=fopen("output.txt","w");
	if (fp_usn==NULL)
	{
		printf("Error in opening file 'usn.txt'\n");
		exit(0);
	}
	
	
	else if (fp_studentname==NULL)
	{
		printf("Error in opening file 'studentname.txt'\n");
		exit(0);
	}
	
	fprintf(fp_output,"USN\t Student Name\n");
	while (1)
	{
			
		fscanf(fp_studentname,"%s",name);
		fscanf(fp_usn,"%s",usn);
		
		if(!feof(fp_studentname) && !feof(fp_usn))
		{
			fprintf(fp_output,"%s\t %s\n",usn,name);
		}
		
		else
		{
			break;
		}
		
         }				
		
	fclose(fp_usn);
	fclose(fp_studentname);
	fclose(fp_output);
	return 0;
	
}

