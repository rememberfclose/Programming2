#include <stdio.h>

int unesi_niz(int* a){
	int i=0;
	while(1){
		scanf("%d",&a[i]);
		if(a[i]==0)
			return i;
		i++;
	}


}
int happenstance(int* a, int n){

	for (int i = 0; i < n; ++i)
	{
		if(a[i]==i)
			return i;
	}

return -1;
}


int main(int argc, char const *argv[])
{	int a[100];
	int n=unesi_niz(a);
	int trazeni=happenstance(a,n);

	printf("%d\n", trazeni);

	return 0;
}