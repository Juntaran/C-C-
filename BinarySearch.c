/*************************************************************************
	> File Name: BinarySearch.c
	> Author: Juntaran
	> Mail: JuntaranMail@gmail.com
	> Created Time: Mon 23 May 2016 18:15:23 PM CST
 ************************************************************************/

#include <stdio.h>

void quick_sort( int* nums, int left, int right )
{
    if( left < right )
    {
        int i = left;
        int j = right;
        int flag = nums[left];
        
        while( i < j )
        {
            while( i<j && nums[j]>=flag )	// 从右向左找第一个小于x的数  
            {
                j--;
            }
            if( i < j )
            {
                nums[i++] = nums[j];
            }
        
            while( i<j && nums[i]<flag )	// 从左向右找第一个大于等于x的数
            {
                i++;
            }
			if( i < j )
            {
                nums[j--] = nums[i];
            }
        }  
		nums[i] = flag;
		quick_sort( nums, left, i-1 );
		quick_sort( nums, i+1, right);
    }
}

int BinarySearch( int* nums, int numsSize, int key )
{
	quick_sort( nums, 0, numsSize-1 );
	int left = 0, right = numsSize-1, middle;
	
	while ( left <= right )
	{
		middle = ( left + right ) / 2;
		if ( nums[middle] == key )
		{
			return middle;
		}
		if ( nums[middle] > key )
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return -1;
}

int main()
{
	int nums[] = {1,2,2,1};
	int numsSize = 4;
	int key = 2;
	
	int ret = BinarySearch( nums, numsSize, key );
	printf( "%d\n", ret );
}