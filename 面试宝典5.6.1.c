#include <stdio.h>

int getMax( int a, int b )
{
    int max = ((a+b) + abs(a-b))/2;
    return max;
}


int main()
{
    int a = 3;
    int b = 5;
    int max = getMax(a,b);
    printf("max is %d\n", max);
    return 0;
}