#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[4]= {1,2,3,4};
    int *ptr=(int*)(&a+1);
    printf("%d",*(ptr-1));
}