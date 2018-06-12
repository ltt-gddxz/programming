#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

/**
* ��������ǵݹ�
*
* 1. �Ӹ��ڵ���������������ߣ����߱߷��ʲ���ջ
* 2. �������սڵ�ʱ��˵���丸�ڵ������Ϊ�գ��򵯳���ǰջ���ĸ��ڵ㣬�ҵ����Һ���
* 3. ���ֺ����ظ���������ֱ��ջ�͵�ǰ�ڵ��Ϊ��
*/
vector<TreeNode *> pre_order(TreeNode *T) {
	stack<TreeNode *> sk;
	vector<TreeNode *> res;

	TreeNode *p = T;
	while (p || !sk.empty()) {
		if (p) {
			res.push_back(p);
			sk.push(p);
			p = p->left;
		}
		else {
			TreeNode *temp = sk.top();
			sk.pop();
			p = temp->right;
		}
	}
	return res;
}

/**
 * ��������ǵݹ飨ǰ�����ֻ��Ҫ�Ѹ�Ϊ����ջ��ʱ����ʽڵ㣬���಻�䣩
 * 
 * 1. �Ӹ��ڵ���������������ߣ����߽߱�ջ���Ȳ����ʣ�
 * 2. �������սڵ�ʱ��˵���丸�ڵ������Ϊ�գ��򵯳���ǰջ���ĸ��ڵ㣬����֮���ҵ����Һ���
 * 3. ���Һ����ظ���������ֱ��ջ�͵�ǰ�ڵ��Ϊ��
 */
vector<TreeNode *> in_order(TreeNode *T) {
	stack<TreeNode *> sk;
	vector<TreeNode *> res;
	
	TreeNode *p = T;
	while (p || !sk.empty()) {
		if (p) {
			sk.push(p);
			p = p->left;
		}
		else {
			TreeNode *temp = sk.top();
			sk.pop();
			res.push_back(temp);
			p = temp->right;
		}
	}
	return res;
}

/**
 * ��������ǵݹ�
 * 
 * 1. �Ⱦ����������ߣ����߽߱�ջ��ֱ������Ϊ�գ�ȡջ��
 * 2. �����Һ��ӣ���ǰһ�����ʽڵ㲻���Һ��ӣ�˵���Һ�����߻�û���ʹ��������Һ�������߼���ִ����������
 * 3. �����Һ��ӣ������Һ���Ϊ��һ�����ʵĽڵ㣬˵���Һ�����߲��÷����ˣ�����ʵ�ǰ�ڵ㣬����ջ���ĵ�ǰ�ڵ㵯����
 *    ����Ҫ������ջ��Ԫ�أ�����Ҫ����1�������ߵĹ��̣����Ҫ����ǰָ���ÿ�
 * 4. �ظ���������ֱ��ջ�͵�ǰָ���Ϊ��
 *
 */
vector<TreeNode *> post_order(TreeNode *T) {
	stack<TreeNode *> sk;
	vector<TreeNode *> res;

	TreeNode *pre = T;
	TreeNode *cur = T;
	while (cur || !sk.empty()) {
		while (cur) {
			sk.push(cur);
			cur = cur->left;
		}

		cur = sk.top();
		
		if (!cur->right || cur->right == pre) {
			res.push_back(cur);
			sk.pop();
			pre = cur;
			cur = NULL;	
		}
		else cur = cur->right;
	}
	return res;
}

/**
 * ����������ȱ����ǵݹ飨ע��ʹ��ջ��ά�������Ƕ��У�
 * �൱���������
 */
vector<TreeNode *> dfs(TreeNode *T) {
	stack<TreeNode *> sk;
	vector<TreeNode *> res;

	sk.push(T);
	while (!sk.empty()) {
		TreeNode *p = sk.top();
		sk.pop();

		res.push_back(p);
		if (p->right) sk.push(p->right);
		if (p->left) sk.push(p->left);
	}
	return res;
}

int tree_traverse_main() {

	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);
	
	root->left = node2;
	node2->left = node3;
	node2->right = node4;
	node4->left = node5;
	root->right = node6;
	node6->right = node7;
	node7->left = node8;
	node7->right = node9;

	vector<TreeNode *> res = pre_order(root);
	//vector<TreeNode *> res = in_order(root);
	//vector<TreeNode *> res = post_order(root);
	//vector<TreeNode *> res = dfs(root);
	for (int i = 0; i < res.size(); i++)
		cout << res[i]->val << " ";
	cout << endl;


	system("pause");
	return 0;
}