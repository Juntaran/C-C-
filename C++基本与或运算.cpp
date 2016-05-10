#include <iostream>
using namespace std;


void printx(int x){
	
	cout << x << endl;
}

int main(){
	
	int x = 2, y ,z;
	
	x *= ( y = z = 5 );
	printx(x);
	
	z = 3;
	x == ( y = z );
	printx(x);
	
	x = ( y == z );
	printx(x);
	
	x = ( y & z );
	printx(x);
	
	x = ( y && z );
	printx(x);
	
	y = 4;
	x = ( y | z );
	printx(x);
	
	x = ( y || z );
	printx(x);
	
	return 0;
	
}