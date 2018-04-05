#include <stdio.h>



int main(int argc, char const *argv[])
{
	double x=2.1,*px=&x;
	double y=0.1, *py=&y;


	printf("px=%p py=%p\n",px,py );

	printf("px=%lf py=%lf\n",*px,*py );

	if(px==py)
		printf("isti\n");
	else
		printf("razliciti\n");
	py=px;

		if(px==py)
		printf("isti\n");
	else
		printf("razliciti\n");

	printf("px=%p py=%p\n",px,py );

	printf("px=%lf py=%lf\n",*px,*py );
	x=1;
	y=2;

	px=&y;

	printf("px=%p py=%p\n",px,py );

	printf("px=%lf py=%lf\n",*px,*py );

	return 0;
}