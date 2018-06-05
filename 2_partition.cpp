#include <bits/stdc++.h>
using namespace std;

/**
 * ���ŵ�partition˼�룬�Լ�������Ӧ�ã�O(n)���K�������Լ�O(nlogn)��������
 * nowcoder. ��С��K����
 */
class Solution {
public:
	int partition(vector<int> &arr, int low, int high) {	// ע���һ�������õ������ã�������������������
		if (low > high || low <0 || high >= arr.size()) return -1;
		if (low == high) return low;

		// ע��Ƚ��õķ��ţ�low��high�Ƚ�ȫ�����ϸ�С�ڻ����ϸ���ڣ���Ԫ�رȽ��÷��ϸ��С�ڵ��ڻ��ߴ��ڵ���
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
	 * ����partition˼�����K����
	 */
	vector<int> get_least_numbers(vector<int> input, int k) {
		vector<int> ans;
		if (k > input.size() || k <= 0) return ans;

		// ���ֲ��ҵ�k����λ��
		int low = 0, high = input.size() - 1;
		int mid = -1;
		while (true) {
			int pos = partition(input, low, high);
			if (pos == k - 1) {	// �������������һ�������������������
				mid = pos; break;
			}
			else if (pos < k - 1) 
				low = pos + 1;
			else 
				high = pos - 1;
		}

		// ȡ��ǰk�����������ֱ�����input[mid]��Ϊ��k����
		for (int i = 0; i <= mid; i++)
			ans.push_back(input[i]);
		sort(ans.begin(), ans.end());
		return ans;
	}

	/**
	 * ����partition˼����п�������
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

