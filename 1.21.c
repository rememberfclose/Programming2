#include <stdio.h>

int fib1(int n,int a,int b){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	n=n-1;
	
	int rez=1;
	int i = 0;
	int j=1;
	while (n--)
	{	
		rez=(i*=b)+(j*=a);
		int temp=j;
		j=i+j;
		i=temp/a;
	
		
	}
	return rez;
}
	int pozivi;
int fib2(int n,int a, int b){
	
	if (n==0)
		return 0;
	if (n==1)
		return 1;
	return a*fib2(n-1,a,b)+b*fib2(n-2,a,b);
}

int fib3(int n,int a, int b){
	static int shtek[100];
	if(shtek[n])
		return shtek[n];
	if (n==0)
		return 0;
	if (n==1)
		return 1;
	return a*(shtek[n-1]=fib3(n-1,a,b))+(shtek[n-2]=b*fib3(n-2,a,b));
}



int main(int argc, char const *argv[])
{
	int met,poz,a,b;	
	scanf("%d%d%d%d",&met,&poz,&a,&b);
	if(met==1)
	printf("%d ", fib1(poz,a,b));
	if(met==2)
	printf("%d ", fib2(poz,a,b));
	if(met==3)
	printf("%d ", fib3(poz,a,b));

	
	return 0;
}