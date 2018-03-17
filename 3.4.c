#include <stdio.h>
#include <string.h>
typedef struct
{
long unsigned index;
char ime[100];
char prezime[100];	
}student;

int prezime_search(student sts[], char* s, int n){
	static int poziv=0;
	poziv++;

	if(strcmp(sts[0].prezime,s)==0)
			return 0;

	if(poziv==n)
		return -200;
	return 1+ prezime_search(sts+1,s, n);

}



int indeks_search(student sts[], long unsigned s, int n, int levi, int desni){
	if(desni<levi)
		return -1;
	int srednji=(levi+desni)/2;
	if(sts[srednji].index==s)
	return 0;
		
		

		if(sts[srednji].index<s)
			return srednji+indeks_search(sts+srednji+1,n,s,0,desni);
		else
			return indeks_search(sts,s,n,0,srednji-1);

return -1;

}


int main(int argc, char const *argv[])
{	student sts[1000];
	FILE* ulaz=fopen(argv[1],"r");
	int i;
	for ( i = 0; fscanf(ulaz,"%lu %s %s",&sts[i].index, sts[i].ime, sts[i].prezime)==3; ++i)
		;


	if(strcmp(argv[2],"-prezime")==0)
		{	char temp[100];
			scanf("%s",temp);
			int redni=prezime_search(sts,temp,i);
			printf("%lu %s %s\n", sts[redni].index,sts[redni].ime, sts[redni].prezime);
		}
		else if(strcmp(argv[2],"-index")==0)
		{	long unsigned temp;
			scanf("%lu",&temp);
			int redni=indeks_search(sts,temp,i,0,i-1);
			printf("%lu %s %s\n", sts[redni].index,sts[redni].ime, sts[redni].prezime);
		}



	return 0;
}