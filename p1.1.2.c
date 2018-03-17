#include <stdio.h>
#include <string.h>
int main()
{
	char s[257];

	scanf("%s", s);
	int duzina=strlen(s);
	for (int i = 0; i < duzina; ++i)
	{
		if (s[i]!=s[duzina-1-i])
		{
			printf("nije\n");
		return 0;
		}
	}
	printf("jeste\n");


	return 0;
}