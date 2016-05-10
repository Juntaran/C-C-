#include <iostream>

using namespace std;

int Add1( int x, int y )
{
    return ((x&y)+((x^y)>>1))<<1;
}

int Add2( int x, int y )
{
    if( y==0 )
    {
        return x;
    }
	int sum, carry;
	
	sum = x^y;
	carry = (x&y)<<1;
    return Add2(sum,carry);
}


int main()
{
    int a = Add1(729, 271);
    int b = Add2(729, 271);
    printf("%d\n%d\n",a,b);
    return 0;
}