#include <stdio.h>

unsigned binomni_koef(int i, int j){
	if(i==0 || j==0)
		return 1;
	static char setup=1;
	//** za paskalovu notaciju kolona **//
	// if(setup)
	// {int tempi=i-j;
	// 	setup=0;
	// 	return binomni_koef(tempi,j);
	// }
	
	
	return binomni_koef(i-1,j)+binomni_koef(i,j-1);

}

unsigned binomni_zbir(int i){
	static int zbir=0;
	if(i==-1)
		return 1;

	return zbir+=binomni_zbir(i-1);

}


int main()
{	int n,k;
	scanf("%d%d",&n,&k);

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j+i <= n; ++j)
		{
			printf("%2d ", binomni_koef(i,j));
		}
		printf("\n");
	}


	printf("\n%d\n", binomni_zbir(k));
	return 0;
}