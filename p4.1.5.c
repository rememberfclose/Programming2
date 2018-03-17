#include <stdio.h>
#include <string.h>
int shows_up(char c, char* s){
static int i;
if(s[i]=='\0')
	return 0;
char niska[2]={s[i++],'\0'};
char karakter[2]={c,'\0'};
	return ((strcasecmp(niska,karakter))==0?1:0) + shows_up(c, s);
}



int main(int argc, char const *argv[])
{	char* s,c;
	scanf("%c %[^\n]%*c",&c, s);
	printf("%d\n", shows_up(c,s));
	return 0;
}