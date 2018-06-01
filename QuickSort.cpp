
#include "QuickSort.h"

const int maxn = 100;

int QuickSortMain()
{
	int n;
	int arr[maxn];
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n-1);
	for (int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}