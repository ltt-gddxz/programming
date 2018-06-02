#include <bits/stdc++.h>
using namespace std;

/** nowcoder. 字符串的排列 */

class Solution {
public:
	/** 回溯产生子序列
	  * patameters:
	  *		strs: 保留所有可行的结果，以引用形式存在
	  *		elem: 可供使用的基本元素
	  *		flag: 访问标志，基本元素是否被访问过
	  *		str: 当前的中间序列结果
	  */
	void get_per(vector<string> &strs, string elem, vector<bool> flag, string str) {
		// 回溯的边界条件
		if (str.size() == flag.size()) {
			strs.push_back(str);
			return;
		}
		
		for (int i = 0; i<flag.size(); i++) {
			if (!flag[i]) {
				str.push_back(elem[i]);	// 尝试探索下一个可行步骤
				flag[i] = true;		// 使用flag数组标志是否被访问过
				get_per(strs, elem, flag, str);
				str.pop_back();		// 返回上一层状态，继续探索其他可能
				flag[i] = false;	// 清楚该情况的访问标志
			}
		}
	}

	vector<string> Permutation(string str) {
		vector<string> strs;
		if (str.size() == 0) return strs;

		sort(str.begin(), str.end());
		string elem = str;
		vector<bool> flag(str.size(), false);
		str = "";
		get_per(strs, elem, flag, str);

		// 去重
		map<string, int> mp;
		vector<string> res;
		for (int i = 0; i<strs.size(); i++) {
			string temp = strs[i];
			if (mp[temp] == 0) {
				res.push_back(temp);
				mp[temp] = 1;
			}
		}

		return res;
	}
};


int main() {
	Solution *solver = new Solution();	
	vector<string> ans = solver->Permutation("abc");
	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}