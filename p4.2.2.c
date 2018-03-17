#include <stdio.h>

void hanoi(int n,char a, char b, char c){
	if(n==0)
		return;
	hanoi(n-1,a,c,b);
	printf("Move %d from %c to %c\n",n, a, b);
	hanoi(n-1,c,b,a);
}


void hanoi_4boi(int n, char a, char b, char c, char d){
	if (n==0)
		return;
	if (n==1)
		{
			printf("Move %d from %c to %c.\n", n, a, d);
			return;
		}
	hanoi_4boi(n-2,a,c,d,b);
	printf("Move %d from %c to %c.\n", n-1, a, c);
	printf("Move %d from %c to %c.\n", n, a, d);
	printf("Move %d from %c to %c.\n", n-1, c, d);
	hanoi_4boi(n-2,b,a,c,d);

}

int main(int argc, char const *argv[])
{
	int duzina;

	scanf("%d",&duzina);


	hanoi_4boi(duzina,'A','B','C','D');
	return 0;
}