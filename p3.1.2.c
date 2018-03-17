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
unsigned broj_parova(unsigned x)
{	unsigned nula=0;
	unsigned rezultat=0;
	unsigned vel=sizeof(unsigned)*8;
	unsigned mask=1<<(vel-1);

	for (; mask; mask>>=1)
	{
		if(x&mask)
			{
			nula=0;
			}
		else {
			if(nula)
				rezultat++;
			else
			nula=1;
			
		}
	}
return rezultat;
}




int main()
{	unsigned x;
	scanf("%d",&x);

	printf("%d\n",broj_parova(x) );
	stampaj_bint(x);

	return 0;
}