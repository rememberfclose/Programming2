#include <stdio.h>

//use this guy to see what you're
//doing with the bits
void stampaj_bint(int x)
{
	int vel=sizeof(int)*8;
	// on mora biti unsigned jer ce ga pretvoriti
	// u negativan broj i messupovati
	unsigned mask=1<<(vel-1);
	//klasicna ona 
	for (; mask; mask>>=1)
	{
		if(x&mask)
			printf("1");
		else printf("0");
	}
	printf("\n");
}


//broji jedinice
int bnubz(int x){
	unsigned mask=1;
	int brojac=0;
	while(mask!=0){
		//u ovom if uslovu
		// NE ZABORAVI OVE DVE GLUPE ZAGRADE
		//  fucking prioriteti
		if((mask&x)!=0){
			brojac++;
		}

	mask<<=1;
	}
	return brojac;
}
void print_niz(int*a, int n){
	for (int i = 0; i < n; ++i)
	{printf("%d ", a[i]);
	}printf("\n");
}

//pomocna funkcija za merge sort
void fuse(int a[],int l, int d){
	int s=(l+d)/2;
	int levi[50];
	int desni[50];
	//duzina levog i desnog su n1 n2
	int n1=s-l+1;
	int n2=d-s;
	//trpaj u pomocne levo i desno
	for (int i = 0; i < n1; ++i)
		{levi[i]=a[l+i];}

	for (int i = 0; i < n2; ++i)
		desni[i]=a[s+1+i];
		
	//ako krenes od 0 za k svaki put ce pisati na isto mesto
	//tako da mroa da pise od l
	int i=0, j=0, k=l;

	//sve dok su obojica neprazni
	while(i<n1 && j <n2){
		//ako levi ima manje jedinica od desnog ili ako imaju isto a levi je manji,
		//ubaci levi, u suprotnom u desni
		if((bnubz(levi[i])<bnubz(desni[j])) || ((bnubz(levi[i])==bnubz(desni[j]) && (levi[i]<desni[j]))))
			a[k++]=levi[i++];
		else
			a[k++]=desni[j++];
	}

	//onaj visak koji ostane u njima
	while(i<n1){
		a[k++]=levi[i++];
	}
	while(j<n2){
		a[k++]=desni[j++];
	}
}

void merger(int a[], int l, int d){
	
	if(l<d){
		//nadji pola
		int s=(l+d)/2;
		//sredi prvu polovinu
		merger(a,l,s);
		//sredi drugu polovinu
		merger(a,s+1,d);
		//spoji ih
		fuse(a,l,d);


	}
}



int main(int argc, char const *argv[])
{
	FILE*f=fopen("brojevi.txt","r");
	int a[100];
	int i=0;

	while(fscanf(f,"%d",&a[i])!=EOF)
		i++;
	int n=i;



	printf("ulazni data: ");
	print_niz(a,n);
	
	// da ne pravim sad pomocnu koja zove ovu f-ju
	//zove se f-ja sa levim i desnim krajem niza
	merger(a,0,n-1);

	printf("sorted data: ");
	print_niz(a,n);

	return 0;
}