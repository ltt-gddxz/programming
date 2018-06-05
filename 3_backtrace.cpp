#include <bits/stdc++.h>
using namespace std;

/** nowcoder. �ַ��������� */

class Solution {
public:
	/** ���ݲ���������
	*   �˺�����n��cur��������ʡȥ����Ϊ��д�ɸ���һ���ģ����ʽ�����ڴ˼���
	* patameters:
	*		strs: �������п��еĽ������������ʽ���ڣ�ͨ�����ֵ���������н��
	*		elems: �ɹ�ʹ�õĻ���Ԫ��
	*		visited: ���ʱ�־������Ԫ���Ƿ񱻷��ʹ�
	*		n: �׶�����
	*		str: ��ǰ���м����н��
	*		cur: ��ǰ�׶�
	*/
	void get_perutation(vector<string> &strs, string elems, vector<bool> visited, int n, string str, int cur) {
		// ���ݵı߽�����
		if (cur == n) {
			strs.push_back(str);
			return;
		}

		for (int i = 0; i<visited.size(); i++) {
			if (!visited[i]) {
				str.push_back(elems[i]);	// ����̽����һ�����в���
				visited[i] = true;		// ʹ��flag�����־�Ƿ񱻷��ʹ�
				get_perutation(strs, elems, visited, n, str, cur+1);
				str.pop_back();		// ������һ��״̬������̽����������
				visited[i] = false;	// ���������ķ��ʱ�־
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

		// ȥ��
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