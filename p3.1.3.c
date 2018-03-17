#include <stdio.h>
#include <stdlib.h>
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
unsigned stajetu(unsigned x, unsigned n){
	unsigned vel= sizeof(unsigned)*8;
	unsigned mask=1<<n;
	if(x&mask)
		return 1;
	else return 0;

}
unsigned postavi_1(unsigned x, unsigned n, unsigned p)
{
	unsigned mask=((~((~0<<(p+1))>>(p-n+1))<<(p-n+1)));
	return x|mask;
}
unsigned postavi_0(unsigned x, unsigned n, unsigned p){
	unsigned mask=(~(~((~0<<(p+1))>>(p-n+1))<<(p-n+1)));
	return x&mask;
}
unsigned zameni(unsigned x, unsigned i, unsigned j){
	unsigned rez;
	if(stajetu(x,i)!=stajetu(x,j))
		{
				rez=x;
				if(stajetu(x,i)==1)
					{rez=postavi_1(rez,1,j);
						}
				else
					{rez=postavi_0(rez,1,j);
				}
				if(stajetu(x,j)==1)
					{rez=postavi_1(rez,1,i);
				}
				else
					{rez=postavi_0(rez,1,i);
						}
			return rez;}
	else{
		
	return x;
	}

}






int main(int argc, char* argv[])
{	unsigned x;
	scanf("%d",&x);
	int i=atoi(argv[1]);
	int j=atoi(argv[2]);


	printf("%d\n", zameni(x,i,j));

	return 0;
}