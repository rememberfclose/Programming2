#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a[10]={10,11,12,13,14,15,16,17,18,19};

	int *p=a;



	printf("a=%d p=%d *a=%p *p=%p\n", *a,*p,a,p);

	for (int i = 0; i < 10; ++i)
	{
		printf("%p %p %p %p\n",&a[i],&p[i],a+i,p+i );
		
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d %d\n",a[i],p[i]);
		
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d %d\n",*(a+i),*(p+i));
		
	}






	return 0;
}