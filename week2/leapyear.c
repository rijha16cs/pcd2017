#include<stdio.h>

int leap(int n){
	if(n%4==0){
        	if(n%100==0){
            		if (n%400==0){
               			return 1;
            		}
           		else{
                		return 0;
            		}
        	}
        	else{
                	return 1;
        	}
    	}
    	else{
            	return 0;
    	}	
}

int main(){
	int n;
	printf("enter the year to be checked:");
	scanf("%d",&n);
	if(leap(n)){
		printf("it is a leap year");
	}
	else{
		printf("it is not a leap year");
	}
	return 0;
}
