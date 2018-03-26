#include <stdio.h>
void swap(int *a, int *b){
	int tmp=a[0];
		a[0]=b[0];
		b[0]=tmp;
}
void selection(int*a,int n){
	int start=0;

	for(int j=0;j<n;j++){
		int min=start;
		for (int i = start; i < n; ++i)
		{
			if(a[i]<a[min])
				min=i;
		}
		
		swap(&a[min],&a[start]);

		start++;

	}
}


void bubble(int*a, int n){
	int swapped=1;

	for(int j=0;swapped;j++){
			swapped=0;
			for (int i = 0; i < n-1-j; ++i)
			{		
				if(a[i]>a[i+1])
					{swap(&a[i],&a[i+1]);
					swapped=1;}
			}	
	}
}




void merge_aux(int*a,int l,int s, int d){
	int i=0,j=0,k=l;
	int n1=s+1-l;
	int n2=d-s;
	int left[n1];
	int right[n2];
	for ( i = 0; i < n1; ++i)
	{
		left[i]=a[l+i];
		right[i]=a[i+s+1];

	}
	i=0;
	while(i<n1 && j<n2){

		if(left[i]<=right[j])
			{
				a[k]=left[i];
				i++;
			}
		else
			{
				a[k]=right[j];
				j++;
			}
		k++;
	}

	while(i<n1){
		a[k]=left[i];
		k++;
		i++;
	}
	while(j<n2){
		a[k]=right[j];
		k++;
		j++;
	}
}

void mergeSort(int*a, int l, int d){
	if(l<d)
	{	int s=(l+d)/2;
		mergeSort(a,l,s);
		mergeSort(a,s+1,d);
		merge_aux(a,l,s,d);
	}




}

void insert(int* a, int n){
	for (int i = 0; i < n; ++i)
	{int temp=a[i];
		for (int j = i-1; j >= 0 && temp<a[j]; j--)
			swap(&a[j+1],&a[j]);

	}
}



int part(int a[],int l, int d){
	int i=l+1;
	int pivot=a[l];

	for (int j = i; j<=d; ++j)
	{
		if(a[j]<pivot)
			{swap(&a[i],&a[j]);i++;}
		
	}
	swap(&a[l],&a[i-1]);
	return i-1;
}

void quick(int *a,int l, int d){
	if(l<d){
		int piv_pos=part(a,l,d);
		quick(a,l,piv_pos-1);
		quick(a,piv_pos+1,d);

	}

}


void shell(int*a,int n){
int h=n/2;
while(h>0){

	for (int i = h; i < n; i++)
	{	int temp=a[i];
	
		for (int j= i; j>=h && a[j-h]>temp; i-=h)
		{
			swap(&a[i],&a[j-h]);
			swap(&a[j],&a[j-h]);
		}

	}

	h/=2;
}




}



int main(int argc, char const *argv[])
{
	int a[]={123,634,12,677,-12,-1231,677,0,0,11};
	int n=10;

shell(a,n);

	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}

printf("\n");
	return 0;
}