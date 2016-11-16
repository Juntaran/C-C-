#include <iostream>

using namespace std;

class Rectangle
{
	double length, width;
	public:
		Rectangle(double a=0.0, double b=0.0);
		double area();
};

Rectangle:: Rectangle(double a, double b) {
	length = a;
	width = b;
}
double Rectangle::area() {
	double s;
	s = length * width;
	return s;
}

int main() {
	Rectangle ob1;
	Rectangle ob2(1.5, 2.0);
	Rectangle ob3(2.5);

	cout << "Area of Rectangleob1 = " << ob1.area() << endl;
	cout << "Area of Rectangleob1 = " << ob2.area() << endl;
	cout << "Area of Rectangleob1 = " << ob3.area() << endl;
	return 0;
}