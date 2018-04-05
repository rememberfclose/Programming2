#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x=1,y=3;

	int* p;

	p=&x;

	printf("x=%d y=%d *p=%d\n",x,y,*p );
	y=*p;
	*p=0;
	printf("x=%d y=%d *p=%d\n",x,y,*p );
	
	p=&x;
	*p+=10;
	printf("x=%d y=%d *p=%d\n",x,y,*p );
	
	++*p;

	printf("x=%d y=%d *p=%d\n",x,y,*p );
	(*p)++;

	printf("x=%d y=%d *p=%d\n",x,y,*p );
	
	return 0;
}