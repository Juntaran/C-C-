#include <stdio.h>
#include <string.h>


#define swap(a,b){char tempBuf[10]; memcpy(tempBuf, &a, sizeof(a)); memcpy(&a, &b, sizeof(b)); memcpy(&b, tempBuf, sizeof(b));}

int main()
{
    double a = 2.3;
	double b = 1.5;
	
	swap(a,b);
	printf("%lf %lf \n",a,b);
	return 0;
}d