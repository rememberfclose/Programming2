#include <stdio.h>

void flip1(int a[], int n){
	for (int i = 0; i < n/2; ++i)
	{
		int temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}


}
void flip2(int a[], int l, int d){
	if(l<d){
		int temp=a[l];
	a[l]=a[d];
	a[d]=temp;
	flip2(a,l+1,d-1);
	}
}

void flip3(int *l, int *d){
	if(l<d){
	int temp=*l;
	*l=*d;
	*d=temp;
	flip3(l+1,d-1);
	}
}

void flip4(int *a, int n){
	int *l=a;
	int *d=a+n-1;

	while(l<d){
		int temp=*l;
		*l=*d;
		*d=temp;
		d--;
		l++;
	}
}



void printa(int a[], int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}


int main(int argc, char const *argv[])
{	int a[100];
	int i=0;
	while(scanf("%d",&a[i])!=EOF)i++;

	int n=i;
	
	printa(a,n);
	
	flip1(a,n);
	printa(a,n);
	
	flip2(a,0,n-1);
	printa(a,n);
	
	flip3(a,a+n-1);
	printa(a,n);
	
	flip4(a,n);
	printa(a,n);

	return 0;
}