#include <stdio.h>
#include <stdlib.h>

int uzastopni_alt(unsigned x){
	static unsigned mask=1;
	
	if(mask==0)
		return 0;
	
	mask=mask<<1;
	
	return ((mask>>1&x && mask&x)?1:0) + uzastopni_alt(x);

}

int main(int argc, char const *argv[])
{		unsigned x;
		 scanf("%d",&x);
		 printf("%d\n", uzastopni_alt(x));

	return 0;
}