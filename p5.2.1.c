#include <stdio.h>
#include <math.h>
#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
typedef struct {
	float ax;
	float ay;
	float bx;
	float by;
}Prava;

char inter(float p0_x, float p0_y, float p1_x, float p1_y, float p2_x, float p2_y, float p3_x, float p3_y, float *i_x, float *i_y)
{
    float s1_x, s1_y, s2_x, s2_y;
    s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
    s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

    float s, t;
    s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        if (i_x != NULL)
            *i_x = p0_x + (t * s1_x);
        if (i_y != NULL)
            *i_y = p0_y + (t * s1_y);
        return 1;
    }

    return 0; // No collision
}

int prava_iznad(Prava prave,float ugao){
	float k=tan(degToRad(ugao));

	if(prave.ay<k*prave.ax && prave.by<k*prave.bx){
		return 0;
	}
return 1;
}

int tacka_ispod(Prava prave, float ugao){
	float k=tan(degToRad(ugao));
	if(prave.ay<k*prave.ax)
		return 0;
	if(prave.by<k*prave.bx)
		return 1;
}




double duzina_prava(Prava prave[], int n){
	double duzina=0;

	for (int i = 0; i < n; ++i)
	{	
		duzina+=sqrt((prave[i].bx-prave[i].ax)*(prave[i].bx-prave[i].ax)+(prave[i].by-prave[i].ay)*(prave[i].by-prave[i].ay));
	}

return duzina;
}



double duzina_prava_ispod(Prava prave[],int n, float ugao)
{	float duzina=0;
	float Tx=cos(degToRad(ugao)),Ty=sin(degToRad(ugao));
	
	for (int i = 0; i < n; ++i)
	{	float x_res, y_res;
		if(!inter((prave[i].ax),(prave[i].ay),(prave[i].bx),(prave[i].by),0.0f,0.0f,Tx*1000, Ty*1000,&x_res,&y_res) && !prava_iznad(prave[i], ugao))
		duzina+=sqrt((prave[i].bx-prave[i].ax)*(prave[i].bx-prave[i].ax)+(prave[i].by-prave[i].ay)*(prave[i].by-prave[i].ay));
		else if (inter((prave[i].ax),(prave[i].ay),(prave[i].bx),(prave[i].by),0.0f,0.0f,Tx*1000, Ty*1000,&x_res,&y_res)){
			float tackax,tackay;
			if(tacka_ispod(prave[i], ugao)==0)
				{ tackax=prave[i].ax;tackay=prave[i].ay;}
			if(tacka_ispod(prave[i], ugao)==1)
				{ tackax=prave[i].bx;tackay=prave[i].by;}

					duzina+=sqrt((tackax-x_res)*(tackax-x_res)+(tackay-y_res)*(tackay-y_res));
		

		
		}
	}
return duzina;
}

double ugao(Prava prave[], int n){
	char bit=1;
	float levi=0;
	float desni=90;
	while(desni>=levi){
	double srednji;
	if(bit){
		srednji=(levi+desni)/2;
	}
	double sveispod=duzina_prava_ispod(prave,n,srednji);
	double sveispod_manji=duzina_prava_ispod(prave,n,srednji-0.001);
	double tacno_pola=(duzina_prava(prave,n))/2;
		printf("sveispod%lf tacno_pola%lf\n",sveispod_manji, tacno_pola );
	if(fabs(sveispod-tacno_pola)<(0.01) && sveispod_manji!=tacno_pola)
		return srednji;
		if(fabs(sveispod-tacno_pola)<(0.01) && sveispod_manji==tacno_pola)
		{	bit=0;
			srednji=srednji-0.1;}
	else if(sveispod>tacno_pola)
		{desni=srednji-0.01;bit=1;}
	else
		{levi=srednji+0.01;bit=1;}


	}


	return -1;


}


int main(int argc, char const *argv[])
{	Prava prave[1000];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%f%f%f%f", &prave[i].ax,&prave[i].ay,&prave[i].bx,&prave[i].by);
	}

	printf("%.2lf\n", ugao(prave, n));

	return 0;
}