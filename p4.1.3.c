#include <stdio.h>
#include <stdlib.h>
int zkc (int x){
	if(x<0)
		x=abs(x);
	if(x/10==0)
		return x*x*x;

	return (x%10)*(x%10)*(x%10)+zkc(x/10);


}




int main(int argc, char const *argv[])
{
	int x;

	scanf("%d",&x);

	printf("%d\n", zkc(x));
	return 0;
}