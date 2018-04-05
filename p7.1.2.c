#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX 30
typedef struct 
{
char ime[MAX+1];
char prezime[MAX+1];
int godiste;
}dete;

void swap(dete kids[],int i, int j){
	dete temp=kids[i];
	kids[i]=kids[j];
	kids[j]=temp;
}




int part(dete kids[], int l, int d){
	//taj po kom delimo ostale
	int pivot=l;
	//tu cemo imati poziciju nekog koji je veci od pivota
	//a ako nije veci od pivota bice na tom mestu pozicija od joti boja
	//sto znaci da u tom slucaju swap-u element sam sa sobom
	//al ovako izgleda fino iskreno
	int p=l;
	int j;

	//ovo je algoritam sa predavanja koji mi je
	//hella confusing ali radi, ako te ne mrzi nacrtaj sta se desava
	

	// pomeri prethodni levo ako [takes deep breath] je manji od pivota ili 
	//(je isti ko pivot i(ili je prvi po prezimenu ili(je isti po prezimenu a prvi po imenu)))
	
	for(j=l+1;j<=d;j++)
		{if(kids[j].godiste<kids[pivot].godiste)
				swap(kids,++p,j);
		else if(kids[j].godiste==kids[pivot].godiste){
			if(strcmp(kids[j].prezime,kids[pivot].prezime)<0)
				swap(kids,++p,j);
			if(strcmp(kids[j].prezime,kids[pivot].prezime)==0 && strcmp(kids[j].ime,kids[pivot].ime)<0)
				swap(kids,++p,j);
		}
		}

	//na mestu p se nalazi neki broj manji od pivota i onda ih zamenimo
	swap(kids,p,l);
	//i vratimo lokaciju naseg pivota nazad f-ji
	//da bi mogla da zna kako da deli niz
	return p;
}


void quick_sort(dete kids[],int l, int d){
	if(l<d){
		//razdeli niz tako da sa leve budu svi manji od nekog broja
		//a sa desne svi veci
		int p=part(kids,l,d);
		//sad taj levi i desni niz sto si dobio sortiraj
		quick_sort(kids,l,p-1);
		quick_sort(kids,p+1,d);
		//notice that sortira od l do p-1 i od p+1 do d, nigde se ne sortira
		//p-ti element jer je on vec na svom mestu


	}



}




int main(int argc, char const *argv[])
{	dete kids[128];

	if(argc!=3){
		printf("greska\n");
		return 0;
	}

	FILE* f;
	int i=0;
	if(f=fopen(argv[1],"r")){
		
		while (fscanf(f,"%s%s%d",kids[i].ime,kids[i].prezime,&kids[i].godiste)!=EOF)
		i++;
		int n=i;		
		quick_sort(kids,0,n-1);
	
		fclose(f);
		f=fopen(argv[2],"w");
			for (int i = 0; i < n; ++i)
		{
			fprintf(f,"%s %s %d \n",kids[i].ime,kids[i].prezime,kids[i].godiste);
		}
		fclose(f);}
		else
			printf("greska\n");

	return 0;
}