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

unsigned zameni_bajtove(unsigned x, unsigned i, unsigned j){
	unsigned rez=x;
	if(i<1 || j>4){
		return -1;
	}
	for (int q = 0; q < 8; ++q)
	{
		rez=zameni(rez,((i-1)*(8))+q,((j-1)*(8))+q);
	}
return rez;
}




unsigned invertuj(unsigned x){
	int vel=sizeof(unsigned)*8;
	unsigned rez=x;
for (int i = 0; i < vel; i=i+3)
{	if(stajetu(x,i)==1)
			rez=postavi_0(rez,1,i);
	else rez=postavi_1(rez,1,i);
}

return rez;
}
unsigned invertuj_mesto(unsigned x, unsigned p){
	unsigned vel=sizeof(unsigned)*8;
	unsigned rez;
	unsigned mask=1<<p;
	if(x&mask)
	{
		rez=postavi_0(x,1,p);
	}
	else
		rez=postavi_1(x,1,p);


return rez;
}
unsigned invertuj_31(unsigned x){
	unsigned mask=1<<31;
	if(x&mask)
	{
		x=x&(~mask);
	}
	else
		x=x|mask;
	return x;
}

long unsigned invertuj_preklop(unsigned x, unsigned y){
	long unsigned rez=x;
	unsigned vel=sizeof(unsigned)*8;
	unsigned lokacije[vel];

	for (int i = 0; i < vel; ++i)
	{	
		if(stajetu(x,i)==stajetu(y,i))
			rez=invertuj_mesto(rez, i);
	}
	if(stajetu(x,31)==stajetu(y,31))
		rez=invertuj_31(rez);

return rez;
}

unsigned vrati_bitove_skroz_desno(unsigned x, unsigned n, unsigned p){

	unsigned vel=sizeof(unsigned)*8;
	return (((((x)>>(p-n+1))<<(p-n+1))<<(vel-p-1))>>(vel-p-1))>>(p-n+1);
}
int broj_oktalnih_petica(unsigned x){
unsigned vel=sizeof(unsigned)*8;
	int  petica=0;
 	for(int i=2;i<vel;i=i+3)
 	if(vrati_bitove_skroz_desno(x,3,i)==5)
 		petica++;
 	return petica;
}

int main(int argc, char* argv[])
 {	unsigned x;
 	scanf("%d",&x);
printf("%d\n", broj_oktalnih_petica(x));

	return 0;

}