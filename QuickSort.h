/*
�����ܣ�ʵ�ֿ��������㷨
�㷨������
	1���ȱ�дһ��������partition������Ϊ�����Լ��±��������
		ȡ��λ����Ϊ���ֵ��м�������Ϊpivotkey
		��ʼ������ָ��low=0,high=length-1
		�ȴ��������������������pivotkey�ϸ�С�ģ���arr[low]=arr[high];(ǰ��low<=high)
		�ٴ������ұ�������������pivotkey�ϸ��ģ���arr[high]=arr[low];(ǰ��low<=high��
		��low>high����arr[high]=pivotkey
	2��д�ܺ���quickSort,�ݹ����Partition����������Ϊ�����Լ��±��������
	3��������
*/
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivotkey = arr[low];
	while (low < high)	// ע��ΪС�ڶ�����С�ڵ���
	{
		while (high>low && arr[high]>=pivotkey) high--;	// ע��Ϊ���ڵ��ڶ����Ǵ���
		arr[low] = arr[high];
		while (low<high && arr[low]<=pivotkey) low++;	// ע��ΪС�ڵ��ڶ�����С��
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
