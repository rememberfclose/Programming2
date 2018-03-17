#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int linearna(int* a, int n, int x){
	for (int i = 0; i < n; ++i)
	{
		if(a[i]==x)
			return i;
	}
return -1;

}
int binarna(int* a, int n, int x){
int levi=0;
int desni=n-1;

while(levi<=desni){
	int srednji=(levi+desni)/2;

	if(a[srednji]==x)
		return srednji;

	if(a[srednji]<x)
	levi=srednji+1;
	else if(a[srednji]>x)
		desni=srednji-1;




}
return -1;

}

int interpolaciona(int* a, int n, int x){
int levi=0;
int desni=n-1;

while(levi<=desni){
	int srednji=levi+ ((x-a[levi])/(a[desni]-a[levi])*(desni-levi));

	if(a[srednji]==x)
		return srednji;

	if(a[srednji]<x)
	levi=srednji+1;
	else if(a[srednji]>x)
		desni=srednji-1;




}
return -1;

}



int main(int argc, char const *argv[])
{	struct timespec t1,t2,t3,t4,t5,t6;
	int len=atoi(argv[1]);
	int x=atoi(argv[2]);
	int a[1000000];
	srand(time(NULL));
	a[0]=0;
	int k;
	FILE* izlaz;

	izlaz=fopen("vreme.txt","a");
	for (int i = 1; i < len; ++i)
	{
		a[i]=rand()%(len/3)+a[i-1];
		printf("%d ", a[i]);
	}
	clock_gettime(CLOCK_REALTIME,&t1);
	printf("Linearna %d\n", k=linearna(a,len,x));
	clock_gettime(CLOCK_REALTIME,&t2);

	clock_gettime(CLOCK_REALTIME,&t3);
	printf("Binarna %d\n", binarna(a,len,x));
	clock_gettime(CLOCK_REALTIME,&t4);

	clock_gettime(CLOCK_REALTIME,&t5);
	printf("Interpolaciona %d\n", interpolaciona(a,len,x));
	clock_gettime(CLOCK_REALTIME,&t6);

	fprintf(izlaz, "Dimenzija:%d\nLinearno:%ld\n",len, ((t2.tv_sec-t1.tv_sec)*10000000)+(t2.tv_nsec-t1.tv_nsec));
fprintf(izlaz, "Binarna:%ld\n", ((t4.tv_sec-t3.tv_sec)*10000000)+(t4.tv_nsec-t3.tv_nsec));
fprintf(izlaz, "Interpolaciona:%ld\n\n", ((t6.tv_sec-t5.tv_sec)*10000000)+(t6.tv_nsec-t5.tv_nsec));
	
	return 0;
}