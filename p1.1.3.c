#include <stdio.h>

int main()
{	float ars=0;
	int a[32];
	int i;

		while(1)
	{
		scanf("%d", &a[i]);
		if(a[i]==0)
			break;
		ars=ars+a[i];
		i++;
	}
	int n=i;
ars=ars/i;
for (int i = 0; i < n; ++i)
{
	if(a[i]>ars)
	{
		a[i]=a[i]*a[i];
	}
}
for (int i = 0; i < n; ++i)
{
	printf("%d\n", a[i]);
}

	
	return 0;
}