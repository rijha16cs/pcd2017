#include<stdio.h>
int reverse(int n)
{
int d,rev=0;
while(n!=0)
{
d=n%10;
rev=(rev+d)*10;
n=n/10;
}
rev/=10;
return rev;
}
int main()
{
int num,n2;
printf("Enter the number:");
scanf("%d",&num);
n2=reverse(num);
if(num==n2)
{
printf("The number is a palindrome");
}
else
{
printf("The number is not a palindrome");
}
return 0;
}
