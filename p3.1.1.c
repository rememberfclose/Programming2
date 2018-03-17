#include <stdio.h>

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
void stampaj_bint(unsigned x)
{
	unsigned vel=sizeof(unsigned)*8;
	unsigned mask=1<<(vel-1);

	for (; mask; mask>>=1)
	{
		if(x&mask)
			printf("1");
		else printf("0");
	}
	printf("\n");
}

unsigned vrati_bitove(unsigned x, unsigned n, unsigned p){

	unsigned vel=sizeof(unsigned)*8;
	return ((((x)>>(p-n+1))<<(p-n+1))<<(vel-p-1))>>(vel-p-1);
}
int main()
{	unsigned x;
	scanf("%d",&x);
	unsigned vel=sizeof(unsigned)*8;
	if(prebroj_bitove_1(vrati_bitove(x,vel/2,vel-1))>prebroj_bitove_1(vrati_bitove(x,vel/2,vel/2-1)))
		printf("vise ima levo\n");
	else if (prebroj_bitove_1(vrati_bitove(x,vel/2,vel-1))<prebroj_bitove_1(vrati_bitove(x,vel/2,vel/2-1)))
		printf("vise ima desno\n");
	else
		printf("ima isto\n");
	stampaj_bint(x);

	return 0;
}