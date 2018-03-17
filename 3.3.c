#include <stdio.h>
#include <string.h>
typedef struct
{
long unsigned index;
char ime[100];
char prezime[100];	
}student;

int prezime_search(student sts[], char* s, int n){

	for (int i = 0; i < n; ++i)
	{
		if(strcmp(sts[i].prezime,s)==0)
			return i;
	}
return -1;

}



int indeks_search(student sts[], long unsigned s, int n){

	int levi=0;
	int desni=n-1;

	while(levi<=desni){
		int srednji=(levi+desni)/2;

		if(sts[srednji].index==s)
			return srednji;

		if(sts[srednji].index<s){
			levi=srednji+1;
		}
		else
			desni=srednji-1;



	}

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
			int redni=indeks_search(sts,temp,i);
			printf("%lu %s %s\n", sts[redni].index,sts[redni].ime, sts[redni].prezime);
		}



	return 0;
}