#include <stdio.h>
void izbaci(int*a, int lb){
	
	
	int i;
	
	
	for( i=1;lb+i<6;i++){
		a[lb+i-1]=a[lb+i];
	}

}
int sredi(int *a, int duz){
int i,j, q;
for (i = 1; i < duz-1; ++i)
	{
		for ( j = 0; j < i; ++j)
		{
			if(a[i]>=a[j])
				break;
			if(j==i-1)
				{izbaci(a,i);duz--;i--;}
		}

	}
	return duz;
}

int main()
{
	int a[20];
	int j, i=0;
	scanf("%d",&a[0]);
	while(a[i++]!=0){
	scanf("%d", &a[i]);

	}


	

	int duz=sredi(a,i);


	
for (i = 0; i < duz-1; ++i)
	{
		printf("%d ", a[i]);
	}


	return 0;
}