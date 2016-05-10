#include <iostream>

using namespace std;

int func( int x )
{
    int count = 0;

    while(x)
    {
        count ++;
        x = x&(x-1);
    }
    return count;
}

int main()
{
    cout << func(3) << endl;
    return 0;
}

/*

	3 -> 11
	
	x = 3; count = 1; x = 3 & 2 = 2
	x = 2; count = 2; x = 2 & 1 = 0
	
*/