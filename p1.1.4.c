#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
	FILE* ulaz;
	ulaz=fopen(argv[1],"r");
	char s[50];
	int brpon=0;
	for (int i = 0; fscanf(ulaz,"%s",s)==1; ++i)
	{
		if(strcmp(s,argv[2])==0)
			brpon++;
	}
	printf("%d\n", brpon);
	return 0;
}