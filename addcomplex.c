#include<stdio.h>
 struct complex

{
	float real;
	float imag;
};


struct complex getcomplex()
{
	struct complex c;
	printf("\nenter real and imaginary part of the complex number :");
	scanf("%f%f",&c.real,&c.imag);
	return c;
}


struct complex add(struct complex x,struct complex y)
{
	struct complex c;
	c.real=x.real+y.real;
	c.imag=x.imag+y.imag;
	return c;
}

void printcomplex(struct complex c)
{
	printf("\nthe sum of two complex numbers :");
        printf("%f+i%f",c.real,c.imag);
}
	

int main()
{
	struct complex p;
	struct complex q;
	struct complex c;
	p=getcomplex();
	q=getcomplex();
	c=add(p,q);
	printcomplex(c);
}
