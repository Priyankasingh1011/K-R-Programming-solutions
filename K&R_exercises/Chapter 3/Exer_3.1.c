#include<stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n-1;
	while(low<=high && v[mid] != x)
	{
		mid = (low+high)/2;
		if(x < v[mid])
		   high = mid+1;
		
		else
		   low = mid+1;
	}
	
    return v[mid] !=x ? -1: mid;
}

int main(void)
{
	int arr[11] = {2, 4, 7, 8, 9, 23, 34, 54, 57, 78, 99};
	int index = binsearch(23, arr, 11);
	printf("%d\n", index);
}
