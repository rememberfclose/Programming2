#include <stdio.h>

void f(int *a, int n){
	int *b=a+n-1;
	while(a<b){
		++*a++;
		--*b--;


	}


}



int main(int argc, char const *argv[])
{
	int a[100];
	int i=0;
	while(scanf("%d",&a[i])!=EOF)i++;

	int n=i;

	f(a,n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}