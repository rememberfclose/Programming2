#include <stdio.h>
#include <string.h>

void obrni(char* s1){
		int duz=strlen(s1);
	char temp=s1[duz-1];
for(int i=0;i<duz;i++){
	s1[duz-1-i]=s1[duz-i-2];
}
s1[0]=temp;
}




int main()
{	char s1[51];
	char s2[51];
	scanf("%s", s1);
	scanf("%s", s2);
	int duz=strlen(s1);
for (int i = 0; i < duz; ++i)
{
	if(strcmp(s1,s2)==0)
		{printf("da\n"); return 0;}
	obrni(s1);
}
printf("ne\n");

	return 0;
}