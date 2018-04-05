#include <stdio.h>
#include <string.h>
typedef struct 
{
	char ime[16];
	char pime[16];
}person;

void rotation(person ppl[], int a, int b){
	person temp=ppl[a];
	ppl[a]=ppl[b];
	ppl[b]=temp;
}

void swap(int c[], int a, int b){
	int temp=c[a];
	c[a]=c[b];
	c[b]=temp;
}

void shell(person a[], int n){
	int h=n/2;
char temp[100];
char temp1[100];
	while(h>0){
		
		for (int i = h; i < n; ++i)
		{	
			strcpy(temp,a[i].pime);
			strcpy(temp1,a[i].ime);
			for (int j = i; j >=h && (strcmp(a[j-h].pime,temp)>0 || (strcmp(a[j-h].pime,temp)==0)&&strcmp(a[j-h].ime,temp1)>0); i-=h)
			{
				rotation(a,i,j-h);
				rotation(a,j,j-h);
			}

		}
h/=2;
	}


}



void bubble(person ppl[],int n){
	int indik=1;

	while(indik){
		indik=0;
		for (int i = 0; i < n-1; ++i)
			if(strcmp(ppl[i].ime,ppl[i+1].ime)>0)
					{rotation(ppl, i,i+1);
					indik++;}
	}
}



int main(int argc, char const *argv[])
{	
	FILE* f;

	// dali postoji fajl
	if(!(f=fopen("glasackispisak.txt","r"))){
		printf("GRESKA\n");
		return -1;
	}
	person ppl_ime[1000];
	person ppl[1000];
	int k=0;
	while(fscanf(f,"%s%s",ppl[k].ime,ppl[k].pime)!=EOF){
		ppl_ime[k]=ppl[k];
		k++;
	}
	int n=k;
	fclose(f);
	shell(ppl,n);
	bubble(ppl_ime,n);
	int brojac=0;
	for (int i = 0; i < n; ++i)
		if(strcmp(ppl[i].ime,ppl_ime[i].ime)==0 && strcmp(ppl[i].pime,ppl_ime[i].pime)==0)
			brojac++;
	
	
	printf("%d\n", brojac);




	return 0;
}