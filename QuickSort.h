/*
程序功能：实现快速排序算法
算法描述：
	1、先编写一趟排序函数partition，参数为数组以及下标的上下限
		取首位，作为划分的中间数，记为pivotkey
		初始化两个指针low=0,high=length-1
		先从右往左遍历，若碰到比pivotkey严格小的，则将arr[low]=arr[high];(前提low<=high)
		再从左往右遍历，若碰到比pivotkey严格大的，则将arr[high]=arr[low];(前提low<=high）
		若low>high，则将arr[high]=pivotkey
	2、写总函数quickSort,递归调用Partition函数，参数为数组以及下标的上下限
	3、输出结果
*/
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivotkey = arr[low];
	while (low < high)	// 注意为小于而不是小于等于
	{
		while (high>low && arr[high]>=pivotkey) high--;	// 注意为大于等于而不是大于
		arr[low] = arr[high];
		while (low<high && arr[low]<=pivotkey) low++;	// 注意为小于等于而不是小于
		arr[high] = arr[low];
	}
	arr[low] = pivotkey;
	return low;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int middle = partition(arr, low, high);
		quickSort(arr, low, middle-1);
		quickSort(arr, middle+1, high);
	}
}
