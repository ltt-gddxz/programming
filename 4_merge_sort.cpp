#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void merge(vector<int> &v, int i, int j, int k) {
	int p1 = i, p2 = j+1;
	vector<int> tmp;
	while (p1 <= j && p2 <= k) {
		if (v[p1] <= v[p2]) 
			tmp.push_back(v[p1++]);
		else
			tmp.push_back(v[p2++]);
	}
	while (p1 <= j) tmp.push_back(v[p1++]);
	while (p2 <= k) tmp.push_back(v[p2++]);

	int size = tmp.size();
	for (int p = 0; p < (k - i + 1); p++)
		v[i + p] = tmp[p];
}

void merge_sort(vector<int> &v, int i, int j) {
	if (j - i <= 0) return;
	int mid = (i + j) / 2;
	merge_sort(v, i, mid);
	merge_sort(v, mid + 1, j);
	merge(v, i, mid, j);
}

int merge_sort_main() {
	
	vector<int> v = {7, 9, 8, 2, 5, 3, 9, 8, 2};

	merge_sort(v, 0, v.size() - 1);
	
	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}