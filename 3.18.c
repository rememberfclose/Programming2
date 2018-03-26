#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE* in1=fopen("text1","r"),*in2=fopen("text2","r");
	char ime1[30],ime2[30],pime1[30],pime2[30];
	int kraj1=0,kraj2=0;
	if(fscanf(in1,"%s %s",ime1,pime1)!=2)
			kraj1=1;
		if(fscanf(in2,"%s %s",ime2,pime2)!=2)
			kraj2=1;

	while(!kraj1 && !kraj2){
	



	int temp=strcmp(ime1,ime2);
	while(temp>0 || (temp==0 && strcmp(pime1,pime2)>0))
		{
			fprintf(stdout, "%s %s\n", ime2,pime2);
		if(fscanf(in2,"%s %s",ime2,pime2)!=2)
			kraj2=1;
		temp=strcmp(ime1,ime2);
		if(kraj2==1)break;		}
	 temp=strcmp(ime1,ime2);
	while(temp<0 || (temp==0 && strcmp(pime1,pime2)<0))
		{
			fprintf(stdout, "%s %s\n", ime1,pime1);
		if(fscanf(in1,"%s %s",ime1,pime1)!=2)
			kraj1=1;
		temp=strcmp(ime1,ime2);
		if(kraj1==1)break;
		}
	}
	while(!kraj1){
		fprintf(stdout, "%s %s\n", ime1,pime1);
		if(fscanf(in1,"%s %s",ime1,pime1)!=2)
			kraj1=1;
		
	}
	while(!kraj2){
		fprintf(stdout, "%s %s\n", ime2,pime2);
		if(fscanf(in2,"%s %s",ime2,pime2)!=2)
			kraj2=1;
		
	}




	return 0;
}