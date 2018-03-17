#include <stdio.h>

int suma(int n, int* a, int* b){

	if(n==1)
		return a[0]*a[0]*b[0]*b[0];

	return a[n-1]*a[n-1]*b[n-1]*b[n-1]+suma(n-1,a,b);



}


int main(int argc, char const *argv[])
{
	int n;
	int a[20];
	int b[20];

	scanf("%d",&n);
	
	if(n<=0 || n>=256)
		{fprintf(stderr, "-1\n");
	return -1;}


	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&b[i]);
	}

	printf("%d\n", suma(n,a,b));

	return 0;
}