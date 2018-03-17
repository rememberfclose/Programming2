#include <stdio.h>
#include <math.h>
unsigned parne(unsigned x)
{	static int lvl=0;
	if(x/10==0)
		{if(x%2!=0)
			{
								return ((x%10)*pow(10,lvl)+pow(10,lvl));}
				else return x*pow(10,lvl);}

		
		return ((x%2!=0)?((x%10)*pow(10,lvl)+pow(10,lvl++)):(x%10)*pow(10,lvl++)) +parne(x/10);


}




int main(int argc, char const *argv[])
{	unsigned x;
	scanf("%d",&x);
	printf("%d\n", parne(x));
	return 0;
}