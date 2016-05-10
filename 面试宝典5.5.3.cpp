#include <iostream>

using namespace std;

int f( int x, int y )
{
    return (x&y)+((x^y)>>1);
}


int main()
{
	int a = f(729, 271);
	printf("%d\n",a);
    return 0;
}