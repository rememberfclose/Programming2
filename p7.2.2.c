#include <stdio.h>

void flip(int a[], int pos){

	for (int i = 0; i <= pos/2; ++i)
	{	int temp;
		temp=a[i];
		a[i]=a[pos-i];
		a[pos-i]=temp;
	}


}

void printa(int a[], int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int pancakeboi(int a[], int n){
	
	int bottom=n-1;
	int flips=0;
	while(bottom>1){
		int max=0;
		for (int i = 0; i <= bottom; ++i)
		{	
			if(a[i]>a[max])
				max=i;
		}
		flip(a,max);
		flip(a,bottom--);
		flips+=2;
	}
		return flips;
}





int main(int argc, char const *argv[])
{
	
	int a[100];
	int i=0;
	while(scanf("%d",&a[i])!=EOF)i++;

	int n=i;
	
	printf("Number of flips:%d\n", pancakeboi(a,n));
	printa(a,n);
	
	return 0;
}