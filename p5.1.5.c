#include <stdio.h>
#include <stdlib.h>

int interpolaciona1(int *a, int n, int k, int levi, int desni){
	int srednji=levi+ ((k-a[levi])/(a[desni]-a[levi])*(desni-levi));

	if(a[srednji]==k)
		return srednji;
	if(levi>desni)
		return -1;

		if(a[srednji]>k)
			return interpolaciona1(a, n,  k, levi, srednji-1);
		if (a[srednji]<k)
			return interpolaciona1(a, n,  k, srednji+1, desni);


	
return -1;
}

int interpolaciona(int *a, int n, int k){
	return interpolaciona1(a,n,k,0,n-1);

}


int main(int argc, char const *argv[])
{
	int a[100];

	int k;
	scanf("%d",&k);

	int n=0;
	while(scanf("%d",&a[n++])==1);
	n=n-1;




	printf("%d\n", interpolaciona(a,n,k));

	return 0;
}