#include <stdio.h>

void swad(int a[], int b, int c){
	int temp=a[c];
	a[c]=a[b];
	a[b]=temp;

}
void printa(int a[], int n){
	for (int i = 0; i < n; ++i)
		{
			printf("%d ", a[i]);
		}	
		printf("\n");
}
int part(int a[], int l, int d){
	int pivot=a[l];
	int i=l+1,j=d;

	while(i<=j){
		if(a[i]>pivot && a[j]<pivot)
			swad(a,i,j);
		if(a[i]<=pivot)i++;
		if(a[j]>=pivot)j--;

	}

	swad(a,l,j);

	return j;

}

void quick(int a[],int l, int d)
{	if(l<d){
	int p=part(a,l,d);
	quick(a,l,p-1);
	quick(a,p+1,d);
}
}

int ntapoz(int *a, int n, int poz,int l){
	quick(a,l,n-1);
	printf("%d ", a[poz-1]);

}

void shift(int a[], int start, int n){
	int b[100];
	for (int i = 0; i < n; ++i)
	{
		b[i]=a[i];
	}
	for (int i = start; i <= n; ++i)
	{
		a[i+1]=b[i];
	}
}


int main(int argc, char const *argv[]){
	int a[500];
 	int i=0;
 	char c;
// 	int poz;
	//metoda sa quickom
	/*/
	while(1){
		scanf("%c",&c);
		if(c=='U'){
			scanf("%d",&a[i++]);
		continue;
		}
		if(c=='N')
		{
			scanf("%d",&poz);
			ntapoz(a,i,poz,l);
		}
	}
	/*/

	//sa umetanjem
	int n=0;
	while(1){
		scanf("%c",&c);
		if(c=='U'){
			//printa(a,n);
			
			int temp;
			scanf("%d",&temp);
			i=0;
			while(temp>a[i] && i<n)i++;
			shift(a,i,n);
			a[i]=temp;
			n++;
			

				}
		else if(c=='N'){
			int poz;
			scanf("%d",&poz);
			printf("%d ", a[poz-1]);

			}
			}

	










	return 0;
}