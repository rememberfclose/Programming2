#include <stdio.h>



int main(int argc, char const *argv[])
{
	void* pp=NULL;
	int x=2;
	char c='a';

	pp=&x;
	*(int*)pp=6;
	printf("adresa xa:%p\n", &x);
	printf("vrednost%d adresa %p i defadresa %p\n", *(int*)pp,pp,(int*)pp);
	pp=&c;
	printf("adres ca:%p\n", &c);
	printf("%c %p \n", *(char*)pp,pp);

	return 0;
}