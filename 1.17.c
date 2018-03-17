#include <stdio.h>

int stepen_lin(int x, int k){

	if(k==0)
		return 1;
	return x*stepen_lin(x,k-1);

}
int stepen_log(int x, int k){
	static int pozivi=0;
	pozivi++;
	 if(k==0)
	 	return 1;	
	if(k==1)
		return x;
	if(k%2==0)
	return stepen_log(x,k/2)*stepen_log(x,k/2);
	
	return x*stepen_log(x,k/2)*stepen_log(x,k/2);
}




int main(int argc, char const *argv[])
{	int pok=0, x,k;
	scanf("%d", &pok);
		scanf("%d", &x);
			scanf("%d", &k);
	if(pok==1)
	printf("%d\n", stepen_lin(x,k));
	else if(pok==2)
	printf("%d\n", stepen_log(x,k));
	else if(pok==0 || x<0 || k<0)
		printf("greska\n");
	return 0;
}