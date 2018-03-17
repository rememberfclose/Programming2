#include <stdio.h>

int main()
{
	int a[32];
	int i=0;
	while(1)
	{
		scanf("%d", &a[i]);
		if(a[i]==0)
			break;
		i++;
	}
	int max=a[0];
	int mb=0;
	int n=i;
	for (; i >= 0; --i)
	{
		if(a[i]>max)
			{max=a[i];
				mb=i;}
	}

	a[mb]=0;

	int sec_max=a[0];
		for (i=0; i <= n; ++i)
		{
		if(a[i]>sec_max)
			sec_max=a[i];
		}
		printf("%d %d\n", sec_max, max);

	return 0;
}