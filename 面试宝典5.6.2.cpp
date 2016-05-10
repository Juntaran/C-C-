#include <stdio.h>


bool MaxBool( int a, int b )
{
    return a>b;
}
int getMax( int a, int b ){
	bool flag = MaxBool(a,b);
	return flag*a + (1-flag)*b;
}

int main()
{
    int a = 3;
    int b = 5;
    int maxoftwo = getMax(a,b);
    printf("max is %d\n", maxoftwo);
    return 0;
}