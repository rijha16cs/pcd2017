#include<stdio.h>

struct complex
{
float img,real;
};


struct complex ShowComplex(struct complex a)
{
char c;
c=a.img<0?'-':'+';

if(a.img<0)
a.img=0-a.img;

printf("the final complex number is %f%ci%f",a.real,c,a.img);
}

struct complex add(struct complex a,struct complex b)
{
struct complex c;

c.real=a.real+b.real;
c.img=a.img+b.img;

return c;
}

struct complex GetComplex()
{
struct complex a;
printf("enter the real part of the complex number : ");
scanf("%f",&a.real);
printf("enter the imaginary part of the complex number : ");
scanf("%f",&a.img);

return a;
}

int main()
{
struct complex a,b,c;
int n;
printf("how many complex numbers do you want to add?  ");
scanf("%d",&n);
for(int i=0;i<n-1;i++)
{
	if(i==0){		
a=GetComplex();
b=GetComplex();
c=add(a,b);
}
else{
a=GetComplex();
c=add(a,c);
}
}
ShowComplex(c);
return 0;
}
