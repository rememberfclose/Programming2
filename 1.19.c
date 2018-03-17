#include <stdio.h>

int faptorijel_1(int x, int total){
	if (x==0)
		return total;

	return faptorijel_1(x-1, total*x);
}
int faptorijel(int x){
	return faptorijel_1(x,1);
}



int main(int argc, char const *argv[])
{
	int x;
	scanf("%d",&x);

	printf("%d\n", faptorijel(x));
	return 0;
}