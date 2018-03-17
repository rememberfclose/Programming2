#include <stdio.h>
int prebroj(int x){
	if(x==0)
		return 0;

	return ((x&(1<<sizeof(int)*8-1))?1:0) + prebroj(x<<1);




}
int main(int argc, char const *argv[])
{	int x;
	scanf("%x",&x);
	printf("%d\n", prebroj(x));
	return 0;
}