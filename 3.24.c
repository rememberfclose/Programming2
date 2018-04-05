#include <stdio.h>
#include <string.h>
typedef struct 
{
	char ime[21];
	char prezime[26];
	int pris;
	int zad;
}st;

void swap(st sts[],int a, int b){
	st temp=sts[a];
	sts[a]=sts[b];
	sts[b]=temp;
}

void bubble(st a[], int n){
	int changed=1;

	while(changed){
		changed=0;
		for (int i = 0; i < n-1; ++i)
			if(strcmp(a[i].ime,a[i+1].ime)>0 || (strcmp(a[i].ime,a[i+1].ime)==0 && strcmp(a[i].prezime,a[i+1].prezime)>0))
				{swap(a, i, i+1);
					changed=1;
				}
	}
}

int part(st sts[], int l, int d){
	st pivot=sts[l];
	int i=l+1;
	int j=d;
	while(i<=j){
		if((sts[i].zad<pivot.zad && sts[j].zad>pivot.zad))
			swap(sts,i,j);
		if(sts[i].zad>=pivot.zad)
			i++;
		if(sts[j].zad<=pivot.zad)
			j--;
	}
	swap(sts,l,j);

	return j;
}
int part1(st sts[], int l, int d){
	st pivot=sts[l];
	int i=l+1;
	int j=d;
	while(i<=j){
		if((sts[i].pris<pivot.pris && sts[j].pris>pivot.pris))
			swap(sts,i,j);
		if(sts[i].pris>=pivot.pris)
			i++;
		if(sts[j].pris<=pivot.pris)
			j--;
	}
	swap(sts,l,j);

	return j;
}

void quick(st sts[], int l, int d){
	if(l<d){
		int p=part(sts,l,d);
		quick(sts,l,p-1);
		quick(sts,p+1,d);
	}

}

void quick1(st sts[], int l, int d){
	if(l<d){
		int p=part1(sts,l,d);
		quick1(sts,l,p-1);
		quick1(sts,p+1,d);
	}

}

void bubble_help(st a[], int n){
	int changed=1;

	while(changed){
		changed=0;
		for (int i = 0; i < n-1; ++i)
			if(strlen(a[i].ime)>strlen(a[i+1].ime) && a[i].zad==a[i+1].zad)
				{swap(a, i, i+1);
					changed=1;
				}
	}
}

void bubble_help1(st a[], int n){
	int changed=1;

	while(changed){
		changed=0;
		for (int i = 0; i < n-1; ++i)
			if(a[i].zad<a[i+1].zad && a[i].pris==a[i+1].pris)
				{swap(a, i, i+1);
					changed=1;
				}
	}
}
void bubble_help2(st a[], int n){
	int changed=1;

	while(changed){
		changed=0;
		for (int i = 0; i < n-1; ++i)
			if(a[i].zad==a[i+1].zad && a[i].pris==a[i+1].pris && strcmp(a[i].prezime,a[i+1].prezime)<0)
				{swap(a, i, i+1);
					changed=1;
				}
	}
}



int main(int argc, char const *argv[])
{
	st sts[500];
	FILE* f=fopen("aktivnost.txt","r");
	int i=0;
	while((fscanf(f,"%s %s %d %d",sts[i].ime,sts[i].prezime,&sts[i].pris,&sts[i].zad))!=EOF)i++;
	int n=i;
	fclose(f);


	bubble(sts,n);
	


	f=fopen("dat1.txt","w");
	for ( i = 0; i < n; ++i)
	{
		fprintf(f,"%20s %20s %3d %3d\n",sts[i].ime,sts[i].prezime,sts[i].pris,sts[i].zad);
	}
	fclose(f);

	quick(sts,0,n-1);
	bubble_help(sts,n);

	f=fopen("dat2.txt","w");
	for (i = 0; i < n; ++i)
	{
		fprintf(f,"%20s %20s %3d %3d\n",sts[i].ime,sts[i].prezime,sts[i].pris,sts[i].zad);
	}
	fclose(f);

	quick1(sts,0,n-1);
	bubble_help1(sts,n);
	bubble_help2(sts,n);
	
	f=fopen("dat3.txt","w");
	for (i = 0; i < n; ++i)
	{
		fprintf(f,"%20s %20s %3d %3d\n",sts[i].ime,sts[i].prezime,sts[i].pris,sts[i].zad);
	}
	fclose(f);



	return 0;
}