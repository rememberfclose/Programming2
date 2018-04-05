#include <stdio.h>
#include <math.h>
#include <string.h>
//returns lenght of line segment
float duzina(int x1,int y1,int x2,int y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
// returns k of line segment
float koef(int x1,int y1,int x2,int y2){
	return ((float)y1-y2)/((float)x1-x2);
}	


typedef struct 
{
	int x1;
	int y1;
	int x2;
	int y2;
	float len;
	float k;
}duz;
//napravi da bi mogao da checkujes sta se desava sa nizom
void printlines(duz lines[],int n){
	for (int i = 0; i < n; ++i)
	{
	printf("%3d %3d %3d %3d k:%20f len:%20f\n", lines[i].x1,lines[i].y1, lines[i].x2,lines[i].y2,lines[i].k,lines[i].len);
		
	}
}

void switchero(duz *a, duz *b){
	duz temp=*a;
	*a=*b;
	*b=temp;
}


//uzo da probam quick boya, took me some time al ako uzmes i nacrtas sta se desava ima smisla
//mozemo jedan dan pred kol da sljakamo malo
void quickboi_k(duz ls[], int l,int d){
	if(l>d)
	return;
	//pivot je taj koga pozicioniramo
	float pivot=ls[l].k;
	int i=l+1,j=d;
	while(i<=j)
	{
		//ako se nadju dvojica na razlicitim stranama niza a da su obojica in the wrong neighbourhood
		//to jest, da bi trebalo da se zamene, swap em
		if(ls[i].k> pivot && ls[j].k<pivot)
			switchero(&ls[i],&ls[j]);
		//ako je broj levo a treba i ta bude pomerimo indeks a broj ne diramo
		if(ls[i].k<=pivot)
			i++;
		//isto tako za desnu stranu
		if(ls[j].k>=pivot)
			j--;

	}
	//e sad tog pivota koji je bio na prvom mestu, moramo da stavimo bas na j-ti boj
	//jer je to bas kad je j-ti boi dosao na boarder izmedju onih vecih od pivota
	// i onih manjih, bas gde ide taj pivot
	switchero(&ls[j],&ls[l]);
	//sad sortujemo levu i desnu stranu analogno
	quickboi_k(ls,l,j-1);
	quickboi_k(ls,j+1,d);
}







void fuse(duz ls[],int l, int s, int d){
	//dva pomocna niza
	duz levi[50];
	duz desni[50];
	//quick maths
	int n1=s-l+1,n2=d-s;
	//napunimo ta dva pomocna
	for (int i = 0; i < n1; ++i)
		levi[i]=ls[l+i];

	for (int i = 0; i < n2; ++i)
	desni[i]=ls[s+i+1];
	//
	
	
	//k pocinje od l jer da pocne od 0 svaki put kad pozovemo
	//pisao bi na isto mesto
	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2){
		//ako je levi manji ubaci ga u niz u suprotnom obratno uradi
		if(levi[i].len<desni[j].len)
			ls[k++]=levi[i++];
		else
			ls[k++]=desni[j++];

	}

	//ono sto je preostalo u jednom od ta dva prespi samo na kraj
	while(i<n1)
	ls[k++]=levi[i++];

	while(j<n2)
	ls[k++]=desni[j++];
}
void merge_sort(duz ls[],int l, int d){
	
	if(l<d)
		{
				int s=(l+d)/2;
				merge_sort(ls,l,s);
				merge_sort(ls,s+1,d);
				fuse(ls,l,s,d);
		}

}



int main(int argc, char const *argv[])
{	duz lines[100];
	FILE* f=fopen(argv[2],"r");
	int n;
	int i=0;
	for (i = 0; fscanf(f,"%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2)!=EOF; ++i)
	{
		lines[i].len=duzina(lines[i].x1,lines[i].y1,lines[i].x2,lines[i].y2);
		lines[i].k=koef(lines[i].x1,lines[i].y1,lines[i].x2,lines[i].y2);
	}
	fclose(f);
	n=i;
	f=fopen(argv[3],"w");

	if(strcmp(argv[1],"-d")==0)
	{merge_sort(lines,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		fprintf(f, "%d %d %d %d\n", lines[i].x1,lines[i].y1,lines[i].x2,lines[i].y2);
	}
	}
	else if(strcmp(argv[1],"-k")==0)
	{quickboi_k(lines,0,n-1);
	for (int i = 0; i < n; ++i)
	{
		fprintf(f, "%d %d %d %d\n", lines[i].x1,lines[i].y1,lines[i].x2,lines[i].y2);
	}
	}
	else printf("GRESKA");


	fclose(f);
	return 0;
}