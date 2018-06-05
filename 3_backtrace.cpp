#include <bits/stdc++.h>
using namespace std;

/** nowcoder. 字符串的排列 */

class Solution {
public:
	/** 回溯产生子序列
	*   此函数的n和cur参数可以省去，但为了写成更加一般的模板形式，故在此加上
	* patameters:
	*		strs: 保留所有可行的结果，以引用形式存在，通过这个值来返回所有结果
	*		elems: 可供使用的基本元素
	*		visited: 访问标志，基本元素是否被访问过
	*		n: 阶段总数
	*		str: 当前的中间序列结果
	*		cur: 当前阶段
	*/
	void get_perutation(vector<string> &strs, string elems, vector<bool> visited, int n, string str, int cur) {
		// 回溯的边界条件
		if (cur == n) {
			strs.push_back(str);
			return;
		}

		for (int i = 0; i<visited.size(); i++) {
			if (!visited[i]) {
				str.push_back(elems[i]);	// 尝试探索下一个可行步骤
				visited[i] = true;		// 使用flag数组标志是否被访问过
				get_perutation(strs, elems, visited, n, str, cur+1);
				str.pop_back();		// 返回上一层状态，继续探索其他可能
				visited[i] = false;	// 清楚该情况的访问标志
			}
		}
	}

	vector<string> Permutation(string str) {
		vector<string> strs;
		if (str.size() == 0) return strs;

		sort(str.begin(), str.end());

		string elems = str;
		vector<bool> visited(str.size(), false);
		int n = str.size();
		str = "";
		int cur = 0;
		get_perutation(strs, elems, visited, n, str, cur);

		// 去重
		map<string, int> mp;
		sort(strs.begin(), strs.end());
		vector<string>::iterator temp_end = unique(strs.begin(), strs.end());
		strs.erase(temp_end, strs.end());

		return strs;
	}
};


int trackback_main() {
	Solution *solver = new Solution();
	vector<string> ans = solver->Permutation("abc");

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}