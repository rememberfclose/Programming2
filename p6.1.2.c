#include <stdio.h>
#include <string.h>
void swap(char*a, char*b){
	char temp=*a;
	*a=*b;
	*b=temp;
}

void sort_string(char* s){
	char max;
//koristim ovde selection sort cisto jer sam sa drugim slabiji
	int len=strlen(s)-1;

	while(len>0){
	max=0;
	for (int i = len; i >=0 ; --i)
	{
		if(s[max]<s[i])
			max=i;
	}
	swap(&s[max],&s[len]);

	len--;
}
}

//znam da je cluster-fuck al radi
char same_boi(char*s){
	//ovde je maximalan broj ponavljanja
	int max=0;
	//trenutni total ponavljanja nekog chara koji countuje
	int total=1;
	//ovde cuva taj char sa max ponavljanja
	char max_c=s[0];
	//one i-ti boi
	int i=0;
	
	//ako unese samo 1 char, u while uslovu ce
	// dobiti segmentation fault tako da ovako se fixuje to
	if (strlen(s)==1)
	{
		return max_c;
	}



		//sve dok su trenutni i onaj posle njega isti udji
		while(s[i]==s[i+1] || i<strlen(s)-2)
			{
			//ako nisu isti, vrati running total na 1
			if(s[i]!=s[i+1])
				total=1;
			//ako jesu povecaj total
			if(s[i]==s[i+1])
			total+=1;
			//ako je total veci od maxa on je novi max
			if(total>max)
				{max=total;
				max_c=s[i];}
			i++;
			}

	return max_c;
}




int main(int argc, char const *argv[])
{
	char s[30];
	scanf("%s",s);
	sort_string(s);
	printf("%c\n", same_boi(s));
	return 0;
}