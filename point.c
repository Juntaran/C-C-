#include <stdio.h>

int main()
{
	int i = 0;
	int *p1 = i;
	int *p2 = &i;
	int *p3;
	p3 = &i;
	
	printf(" p1 is %d\n", p1);
	printf(" p2 is %d\n", p2);
	printf(" p3 is %d\n", p3);
	printf("&p1 is %d\n", &p1);
	printf("&p2 is %d\n", &p2);
	printf("&p3 is %d\n", &p3);
	printf("*p2 is %d\n", *p2);
	printf("*p3 is %d\n", *p3);
}