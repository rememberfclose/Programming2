#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int unesi(int*a){
	int i=0;
	while(scanf("%d",&a[i++])==1);
	return i-1;
}


void bubble(int*a, int n){
	int i=0;
	int swapped=1;
	while(swapped){
	swapped=0;
	for (int i = 0; i < n-1; ++i)
	{
		if(a[i]>a[i+1])
			{swap(&a[i],&a[i+1]);swapped=1;}

		
	}
	}
}

int finder(int*a, int n, int k){
	int sum=-1;
	for (int i = 0; i < n; ++i)
	{
		if(a[i+1]-a[i]==k)
			sum=a[i+1]+a[i];
	}

	return sum;
}


int main(int argc, char const *argv[])
{	//checks for stupid user
	if(argc!=2)
		return -1;

	int a[100];
	//gets the length of the array and scans it
	int n=unesi(a);
	//sort that shit out
	bubble(a,n);
	//prints the bad boi
	printf("%d",finder(a,n,atoi(argv[1])));

	return 0;
}