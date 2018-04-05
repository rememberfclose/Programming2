#include <stdio.h>

double sum(double *a, int n){
	double s=0;

	while (n--)
	{
		s+=*a++;
	}

	return s;
}

double prod(double *a, int n){
	double s=1;

	while (n--)
	{
		s*=*a++;

	}

	return s;
}

double min(double *a, int n){
	double min=*a;

	while(n--){
		if(*a++<min)
			min=*(a-1);
	}
	return min;

}
double max(double *a, int n){
	double min=*a;

	while(n--){
		if(*a++>min)
			min=*(a-1);
	}
	return min;

}



int main(int argc, char const *argv[])
{
	double a[100];
	int i=0;
	while(scanf("%lf",&a[i])!=EOF)i++;

	int n=i;


	printf("sum:%lf\n", sum(a,n));
	printf("prod:%lf\n", prod(a,n));
	printf("min:%lf\n", min(a,n));
	printf("max:%lf\n", max(a,n));
	return 0;
}