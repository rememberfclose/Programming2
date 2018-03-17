#include <stdio.h>
#include <string.h>
typedef struct {
	int p1,p2;
	char username[30];
} student;



int main(int argc, char const *argv[])
{	student studenti[1000];
	FILE* ulaz=fopen(argv[1],"r");


	
	if(strcmp(argv[2],"-max")==0)
{	int flag=1;
	float max;
	int maxi=0;
	//// RACUNA MAX
	for (int i = 0; fscanf(ulaz,"%s %d %d", studenti[i].username, &studenti[i].p1, &studenti[i].p2)==3; ++i)
	{	flag?(max=((float)studenti[0].p1+studenti[0].p2)/2),flag=0:flag==1;
		if(((float)studenti[i].p1+studenti[i].p2)/2>max)
			{max=((float)studenti[i].p1+studenti[i].p2)/2;
				maxi=i;}

	}
	printf("%s\n", studenti[maxi].username);
}
	if(strcmp(argv[2],"-min")==0)
{	int flag=1;
	float min;
	int mini=0;
	//RACUNA MIN
	for (int i = 0; fscanf(ulaz,"%s %d %d", studenti[i].username, &studenti[i].p1, &studenti[i].p2)==3; ++i)
	{	flag?(min=((float)studenti[0].p1+studenti[0].p2)/2),flag=0:flag==1;
		if(((float)studenti[i].p1+studenti[i].p2)/2<min)
			{min=((float)studenti[i].p1+studenti[i].p2)/2;
				mini=i;}

	}
	printf("%s\n", studenti[mini].username);
	
}
	


	return 0;
}