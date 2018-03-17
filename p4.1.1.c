#include <stdio.h>
int najmanja(int duzina, int* a){
static int minimum;
if(duzina==0)
	return a[0];

int poziv=najmanja(duzina-1,a);
if(a[duzina-1]<poziv)
	return a[duzina-1];
else 
	return poziv;
}


int main(int argc, char const *argv[])
{	
	int a[20];
int i;
	for ( i = 0; 1; ++i)
	{
		if(scanf("%d",&a[i])!=1)
			break;

	}


	printf("%d\n", najmanja(i,a));
	return 0;
}