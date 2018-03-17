#include <stdio.h>
#include "b.h"
unsigned prebroj_bitove_1(int x){
unsigned vel=sizeof(int)*8;
unsigned mask=1;
unsigned zbir=0;
for(;mask;mask<<=1){
	if(x&mask)
		zbir++;
}
return zbir;
}
unsigned prebroj_bitove_2(int x){
unsigned vel=sizeof(int)*8;
unsigned mask=1<<(vel-1);
unsigned zbir=0;
for(;x;x<<=1){
	if(x&mask)
		zbir++;
}
return zbir;
}


int main()
{	int x;
	scanf("%x",&x);
	int a;
	scanf("%d", &a);
	if(a==1)
	printf("%u\n", prebroj_bitove_1(x));
	else if(a==2)
	printf("%u\n", prebroj_bitove_2(x));
	else
		printf("greska\n");


	return 0;
}