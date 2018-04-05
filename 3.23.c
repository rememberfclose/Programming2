#include <stdio.h>
typedef struct 
{	int barkod;
	char ime[20];
	char proiz[20];
	int cena;	
}proizvod;

void printa(int a[],int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int a[],int x, int y){
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}


void fuse(proizvod a[],int l, int d){
	proizvod levi[50];
	proizvod desni[50];
	int s=(l+d)/2;
	int n1=s-l+1;
	int n2=d-s;
	for (int i = 0; i < n1; ++i)
	{
		levi[i]=a[i+l];
	}
	for (int i = 0; i < n2; ++i)
	{
		desni[i]=a[i+1+s];
	}
	int i=0,j=0,k=l;

	while(i<n1 && j<n2){
		if(levi[i].barkod<desni[j].barkod){
			a[k++]=levi[i++];
		}
		else
			a[k++]=desni[j++];
	}

	while(i<n1){
		a[k++]=levi[i++];
	}
	while(j<n2){
		a[k++]=desni[j++];
	}




}

void mergesort(proizvod a[],int l, int d){
	if(l<d){
		int s=(l+d)/2;
		mergesort(a,l,s);
		mergesort(a,s+1,d);
		fuse(a,l,d);

	}
}

int binarna(proizvod a[],int n, int bk){
	int l=0;
	int d=n-1;

	while(l<=d){
		int s=(l+d)/2;

		if(a[s].barkod==bk)
			return s;
		if(a[s].barkod>bk)
			d=s-1;

		if(a[s].barkod<bk)
			l=s+1;

	}

return -1;
}




int main(int argc, char const *argv[])
{
	FILE* f=fopen("artikli.txt","r");
	proizvod ps[100];
	int i=0;
	while((fscanf(f,"%d %s %s %d",&ps[i].barkod,ps[i].ime, ps[i].proiz,&ps[i].cena))!=EOF)i++;
	int n=i;
	fclose(f);


	mergesort(ps,0,n-1);

	printf("\t\tASORTIMAN\n\n");
	fprintf(stdout,"%4s %12s %12s %12s\n","KOD","IME", "FIRMA","CENA");
	for (int i = 0; i < n; ++i)
	{
		fprintf(stdout,"%4d %12s %12s %12d\n",ps[i].barkod,ps[i].ime, ps[i].proiz,ps[i].cena);
	}
	int racun=0;
	while(1){
		int temp;
		racun =0;
		printf("Unesite novi artikal za novi racun:\n");
		while(1)
		{
			if(scanf("%d",&temp)==EOF){printf("kraj rada kase\n");return 2;}
			if(temp==0)break;
		int poz=binarna(ps,n,temp);
		if(poz==-1)
		{
			printf("Nepostoji\n");
			continue;
		}
		racun+=ps[poz].cena;
		printf("Uzeli ste %s %d\nUnesite novi artikal ili 0 za kraj:\n",ps[poz].ime,ps[poz].cena);}
		printf("%d je vas racun\n", racun);
		}
		

	return 0;
}