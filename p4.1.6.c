#include <stdio.h>

void ponavljanje(int* niz, int a, int b){
	static int pos=0;
	if(niz[pos]==0)
		return;
	if(niz[pos]==a && niz[pos+1]==b)
	{
		niz[pos]=-1;
		niz[pos+1]=-1;
		
	}
pos++;
ponavljanje(niz,a,b);



}






int main(int argc, char const *argv[])
{	
	int a;
	int b;
	int niz[256];
	int i;
	scanf("%d%d",&a,&b);
	for (i = 0; 1; ++i)
	{
		scanf("%d",&niz[i]);
		if(niz[i]==0)
			break;
	}
	int len=i;
	ponavljanje(niz,a,b);

	for (int i = 0; i<len; ++i)
	{
		printf("%d ", niz[i]);
		
	}


	
	return 0;
}