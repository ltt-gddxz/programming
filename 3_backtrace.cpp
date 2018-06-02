#include <bits/stdc++.h>
using namespace std;

/** nowcoder. �ַ��������� */

class Solution {
public:
	/** ���ݲ���������
	  * patameters:
	  *		strs: �������п��еĽ������������ʽ����
	  *		elem: �ɹ�ʹ�õĻ���Ԫ��
	  *		flag: ���ʱ�־������Ԫ���Ƿ񱻷��ʹ�
	  *		str: ��ǰ���м����н��
	  */
	void get_per(vector<string> &strs, string elem, vector<bool> flag, string str) {
		// ���ݵı߽�����
		if (str.size() == flag.size()) {
			strs.push_back(str);
			return;
		}
		
		for (int i = 0; i<flag.size(); i++) {
			if (!flag[i]) {
				str.push_back(elem[i]);	// ����̽����һ�����в���
				flag[i] = true;		// ʹ��flag�����־�Ƿ񱻷��ʹ�
				get_per(strs, elem, flag, str);
				str.pop_back();		// ������һ��״̬������̽����������
				flag[i] = false;	// ���������ķ��ʱ�־
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

		// ȥ��
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