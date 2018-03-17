#include <stdio.h>

int zbir1(int n, int* a){
	if(n-1==0)
		return a[0];
	return a[n-1]+zbir1(n-1,a);


}
int zbir2(int n, int* a){
	static int i=0;
	
	if(i==n-1)
		return a[n-1];

	return a[i++]+zbir2(n,a);

}




int main(int argc, char const *argv[])
{	int n, a[100];
	int met;

	scanf("%d%d",&met,&n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	if(met==1)
	printf("%d\n", zbir1(n,a));
if(met==2)
	printf("%d\n", zbir2(n,a));
	return 0;
}