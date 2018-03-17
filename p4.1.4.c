#include <stdio.h>
int strogo(int* a, int k, int n){

	if (n==1)
	{
		if(a[0]<k)
			return 1;
		else return 0;
	}
	
	if(a[n-1]<k)
	return 1 + strogo(a,k,n-1);
	else 
		return strogo(a,k,n-1);





}




int main(int argc, char const *argv[])
{
	int k;
	int a[100];
	int i;
	scanf("%d",&k);
	for(i=0;1;i++){

		if(scanf("%d",&a[i])!=1)
			break;
	}
	int n=i;
	printf("%d\n", strogo(a,k,n));


	return 0;
}