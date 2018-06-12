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
* 先序遍历非递归
*
* 1. 从根节点出发，不断向左走，边走边访问并进栈
* 2. 当遇到空节点时，说明其父节点的左孩子为空，则弹出当前栈顶的父节点，找到其右孩子
* 3. 对又孩子重复上述过程直至栈和当前节点均为空
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
 * 中序遍历非递归（前序遍历只需要把改为在入栈的时候访问节点，其余不变）
 * 
 * 1. 从根节点出发，不断向左走，边走边进栈（先不访问）
 * 2. 当遇到空节点时，说明其父节点的左孩子为空，则弹出当前栈顶的父节点，访问之，找到其右孩子
 * 3. 对右孩子重复上述过程直至栈和当前节点均为空
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
 * 后序遍历非递归
 * 
 * 1. 先尽可能向左走，边走边进栈，直至左孩子为空，取栈顶
 * 2. 若有右孩子，且前一个访问节点不是右孩子，说明右孩子这边还没访问过，则往右孩子这边走继续执行上述过程
 * 3. 若无右孩子，或者右孩子为上一个访问的节点，说明右孩子这边不用访问了，则访问当前节点，并将栈顶的当前节点弹出。
 *    下面要访问新栈顶元素，所以要跳过1的向左走的过程，因此要将当前指针置空
 * 4. 重复上述过程直至栈和当前指针均为空
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
 * 树的深度优先遍历非递归（注意使用栈来维护而不是队列）
 * 相当于先序遍历
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