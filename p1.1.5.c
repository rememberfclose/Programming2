#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* encode(char* s)
{
	int duzina=strlen(s);

for (int i = 0; i<duzina; ++i)
{
	if(isalpha(s[i]))
		{	if(isalpha(s[i]+3))
			s[i]+=3;
			else
				s[i]=s[i]-23;
		}

}
return s;
}



int main(int argc, char* argv[])
{
FILE* ul, *iz;
ul=fopen(argv[1], "r");
iz=fopen(argv[2], "w");

char s[100];


for (int i = 0; fscanf(ul,"%s",s)==1; ++i)
{	encode(s);
	fprintf(iz,"%s ",s);

}




	
	return 0;
}