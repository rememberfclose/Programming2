#include <stdio.h>
#include <stdlib.h>

int prvi_veci(int *a, int n, int k){
	
	int levi=0;
	int desni=n-1;
	while(levi<=desni){

	
	int srednji=(levi+desni)/2;

	if(a[srednji]>k && (a[srednji-1]<=k || srednji==0))
		return a[srednji];

	if(a[srednji]>k)
		desni=srednji-1;
	if(a[srednji]<=k)
		levi=srednji+1;



	}

return -1;

}

int main(int argc, char const *argv[])
{
	int a[100];

	for (int i = 0; i < argc-1; ++i)
	{
		a[i]=atoi(argv[i+1]);
	}

	int k;


	scanf("%d",&k);

	printf("%d\n", prvi_veci(a,argc-1,k));

	return 0;
}