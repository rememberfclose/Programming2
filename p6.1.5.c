#include <stdio.h>



int merge(int*a,int n1,int*b,int n2,int*c,int n3){
	int k=0,i=0,j=0;
	while( i < n1 && j<n2)
	{	
		while(a[i]<b[j]){
			c[k++]=a[i++];
			if(!( i < n1 && j<n2))
			break;
		}

		while(a[i]>=b[j]){
			c[k++]=b[j++];
			if(!( i < n1 && j<n2))
			break;
		}
		
	}
	while(i<n1)
		{c[k++]=a[i++];}
	while(j<n2)
		{c[k++]=b[j++];}


}
int scan_arr(int*a){
	int i=0;
	do{scanf("%d",&a[i]);
	}while(a[i++]!=0);
	return i-1;

}


int main(int argc, char const *argv[])
{	int i;
	int a[100];
	int b[100];
	int c[100];
	int n1=scan_arr(a);
	int n2=scan_arr(b);
	int n3=n1+n2;
	
	merge(a,n1,b,n2,c,n3);

	
	for (int i = 0; i < n3; ++i)
	{
		printf("%d ", c[i]);
	}



	return 0;

}