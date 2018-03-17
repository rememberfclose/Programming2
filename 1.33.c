#include <stdio.h>

int isti(int*a, int*b, int n){
	for (int i = 0; i < n; ++i)
	{
		if(a[i]!=b[i])
			return 0;
	}

	return 1;
}

void obrni(int*a, int n){
	int temp[100];

	for (int i = 0; i < n; ++i)
	{
		temp[i]=a[i];
	}

	for (int i = 0; i < n; ++i)
	{
		a[i]=temp[n-1-i];
	}

}
void kopija(int *a, int *copy, int n){
	for (int i = 0; i < n; ++i)
	{
		copy[i]=a[i];
	}

return;
}
void stampaj(int* a, int n){
	
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}

void permutacije1(int*a, int n,int real_n){

	if(n==1)
		stampaj(a,real_n);
	else{
		for (int i = 0; i < n-1; ++i)
		{
			permutacije1(a,n-1,real_n);
			if(n%2==0)
			{	int temp=a[i];
				a[i]=a[n-1];
				a[n-1]=temp;

			}
			else
				{	int temp=a[0];
				a[0]=a[n-1];
				a[n-1]=temp;

			}
		}
		permutacije1(a,n-1,real_n);
}





}


void permutacije(int*a, int n){
	permutacije1(a,n,n);
}



int main(int argc, char const *argv[])
{
	int a[100];
	int n;

	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		a[i]=i+1;
	}
permutacije(a,n);
	return 0;
}