#include <bits/stdc++.h>
using namespace std;

/**
 * 快排的partition思想，以及其两个应用：O(n)求第K大数，以及O(nlogn)快速排序
 * nowcoder. 最小的K个数
 */
class Solution {
public:
	int partition(vector<int> &arr, int low, int high) {	// 注意第一个参数用的是引用，如果是数组则不需加引用
		if (low > high || low <0 || high >= arr.size()) return -1;
		if (low == high) return low;

		// 注意比较用的符号：low和high比较全部用严格小于或者严格大于，而元素比较用非严格的小于等于或者大于等于
		int pivot = arr[low];	
		while (low < high) {
			while (high > low && arr[high] >= pivot) high--;
			arr[low] = arr[high];
			while (low < high && arr[low] <= pivot) low++;
			arr[high] = arr[low];
		}
		arr[low] = pivot;
		return low;
	}

	/**
	 * 利用partition思想求第K大数
	 */
	vector<int> get_least_numbers(vector<int> input, int k) {
		vector<int> ans;
		if (k > input.size() || k <= 0) return ans;

		// 二分查找第k大数位置
		int low = 0, high = input.size() - 1;
		int mid = -1;
		while (true) {
			int pos = partition(input, low, high);
			if (pos == k - 1) {	// 结束条件：最后一定会遇到这个结束条件
				mid = pos; break;
			}
			else if (pos < k - 1) 
				low = pos + 1;
			else 
				high = pos - 1;
		}

		// 取出前k大的数并排序，直接输出input[mid]即为第k大数
		for (int i = 0; i <= mid; i++)
			ans.push_back(input[i]);
		sort(ans.begin(), ans.end());
		return ans;
	}

	/**
	 * 利用partition思想进行快速排序
	 */
	void quick_sort(vector<int> &nums, int low, int high) {
		if (nums.size() <= 0 || low < 0 || high >= nums.size()) return;
		
		if (low < high) {
			int pos = partition(nums, low, high);
			quick_sort(nums, low, pos - 1);
			quick_sort(nums, pos + 1, high);
		}
	}
};

int partition_main() {
	Solution *solver = new Solution();
	
	vector<int> v = { 4,5,1,6,2,7,3,8 };
	//vector<int> v = { 7,9,8,2,5,3,9,8,2 };
	
	//vector<int> ans = solver->get_least_numbers(v, 4);
	solver->quick_sort(v, 0, 8);
	
	for (int e : v)
		cout << e << " ";
	cout << endl;
	
	system("pause");
	return 0;
}

