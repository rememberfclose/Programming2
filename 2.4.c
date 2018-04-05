#include <stdio.h>

int main(int argc, char const *argv[])
{	
	
	char mod;

	printf("Argumenti %d\n", argc);
	scanf("%c",&mod);
	if(mod=='I'){
		for (int i = 0; i < argc; ++i)
		{
			printf("%d %s\n",i, argv[i] );
		}
		for (int i = 0; i < argc; ++i)
		{
			printf("%c ", argv[i][0] );
		}
	}
	if(mod=='P'){
		
		int n=argc;
	
		while(n--)
			printf("%d %s\n",argc-n-1, *argv++);
		
		n=argc;
		argv=argv-n;
		
		while(n--)
			printf("%c ", *(argv++)[0]);
	}
	return 0;
}