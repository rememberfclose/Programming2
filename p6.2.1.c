#include <stdio.h>


void fuse(float*a, int l,int s,int d){
	float levi[100];
	float desni[100];
	int n1=s-l+1;
	int n2=d-s;

	for (int i = 0; i < n1; ++i)
	{
		levi[i]=a[l+i];
	}
	for (int i = 0; i < n2; ++i)
	{
		desni[i]=a[s+1+i];
	}
	
	int i=0, j=0, k=l;
	while(1){
		if(i>=n1 || j>=n2)
			break;
		while(levi[i]<desni[j])
			{a[k++]=levi[i++];
					if(i>=n1 || j>=n2)
						break;}

		while(levi[i]>=desni[j])
			{a[k++]=desni[j++];
					if(i>=n1 || j>=n2)
						break;}
		if(i>=n1 || j>=n2)
						break;
	}

	while(i<n1)
		a[k++]=levi[i++];
	while(j<n2)
		a[k++]=desni[j++];

}

void msort(float*a, int l,int d){
	if(l<d){
		int s=(l+d)/2;
		
		msort(a,l,s);
		msort(a,s+1,d);
		fuse(a,l,s,d);}

}
void merge_sort(float*a,int n){
	return msort(a,0,n-1);
}


int main(int argc, char const *argv[])
{	float a[100];
	int n;
	scanf("%d",&n);



	for (int i = 0; i < n; )
	{
		scanf("%f",&a[i++]);
		merge_sort(a,i);
		if((i)%2==1 ){
			printf("Med:%.3f\n",a[(i)/2]);	
		}
	}

	return 0;
}