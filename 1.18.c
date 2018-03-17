#include <stdio.h>
unsigned neparan(unsigned n);
unsigned paran(unsigned n){
	if(n==0)
		return 1;
	return neparan(n/10);
}
unsigned neparan(unsigned n){
	if(n==0)
		return 0;
	return paran(n/10);

}

int main(int argc, char const *argv[])
{	int x;
	while(1){scanf("%d",&x);
		printf("%u\n", neparan(x));}
	return 0;
}