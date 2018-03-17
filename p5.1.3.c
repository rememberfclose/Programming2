#include <stdio.h>
#include <math.h>

double binarna(){

double levi=3;
double desni=5;
while(levi<=desni)
{
	double srednji=(desni+levi)/2;
	double trenutni=(sin(srednji)+cos(sqrt(3)*srednji));
	if(trenutni>0 && trenutni<0.001)
		return srednji;
	if((trenutni)<0)
		desni=srednji-0.001;
	else
		levi=srednji+0.001;


}


}

int main(int argc, char const *argv[])
{
		printf("%.4lf\n", binarna());

	return 0;
}