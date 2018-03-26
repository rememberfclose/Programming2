#include <stdio.h>
#include <string.h>
void swap(int*a, int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int unesi(int*a){
	int i=0;
	while(scanf("%d",&a[i++])==1);
	return i-1;
}

void insert(int* a, int n){
	for (int i = 0; i < n; ++i)
	{int temp=a[i];
		for (int j = i-1; j >= 0 && temp<a[j]; j--)
			swap(&a[j+1],&a[j]);

	}
}

void equals_three(int*a, int n){
	int test;
	for (int i = 0; i < n-2 ; ++i)
	{	//ako su prvi drugi i treci za redom isti, a ako je jedan pre ili jedan posle isti
		//to znaci da ih ima vise od 3 sto nam ne treba, a ovo test ovde sluzi da ne bi zatrazio
		//adresu od -1 elementa u nizu
		if(a[i]==a[i+1] && a[i]==a[i+2] && a[i]!=a[i+3] && (test=(i==0?1:(a[i]!=a[i-1]))))
			printf("%d ", a[i]);
		
	}

//moglo je ove brojke koje zadovoljavaju da se u neki niz strpaju al ono, didn't specify


}


int main(int argc, char const *argv[])
{	int a[256];
	int n=unesi(a);

	insert(a,n);

	equals_three(a,n);
	return 0;
}