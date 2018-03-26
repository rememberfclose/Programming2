#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void bubble(int*a, int n){
	int swapped=1;
	while(swapped){
		swapped=0;
		for (int i = 0; i < n; ++i)
		{
			if(a[i]>a[i+1])
				{swap(&a[i],&a[i+1]);
				swapped=1;
				}
		}
	
	}
}

int formula(int*a, int n, int p, int q, int w){

	for (int i = 0; i < n; ++i)
	{
		int levi=i+1;
		int desni=n-1;
		while(levi<=desni){
			int srednji=(levi+desni)/2;
		
			if((p*a[i]+q*a[srednji])==w || (p*a[srednji]+q*a[i])==w)
				{return 1;}
			if((p*a[i]+q*a[srednji])<w)
				levi=srednji+1;
			else if((p*a[i]+q*a[srednji])>w)
				desni=srednji-1;

		}

	}
	return -1;

}



int main(int argc, char const *argv[])
{
	int a[256];
	int i=0;
	do{scanf("%d",&a[i]);
	}while(a[i++]!=0);
	int n=i-2;

	bubble(a,n);

	printf("%d\n", formula(a,n,atoi(argv[1]),atoi(argv[2]),atoi(argv[3])));


	return 0;
}