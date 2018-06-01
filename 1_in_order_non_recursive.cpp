/*

程序功能：实现二叉树的中序非递归遍历算法
算法描述：
	1、定义数据结构：二叉链表
	2、建树：先序递归遍历建树
	3、中序非递归遍历
		根节点进栈，当栈非空时且指针p非空时：
			取栈顶元素
			如果有左孩子，则左孩子进栈
			如果没有左孩子，输出并将栈顶出栈；如果存在右孩子，则将右孩子进栈
		0）如果根节点为空，则遍历结束
		1）将指针p=root->lchild,将根节点入栈
		2）在栈非空或p非空时，进行以下循环
		3）如果p非空，则将p进栈，p=p->lchild；
		   否则将p取栈顶并将栈顶出栈，p指向p的右孩子;
*/


#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

// 树节点
struct Node
{
	int data;
	Node *lchild;
	Node *rchild;
	// 构造函数
	Node(int data)
	{
		this->data = data;
		lchild = rchild = NULL;
	}
};

// 层次遍历建树
Node *build_tree()
{
	int data, ldata, rdata;
	cin >> data;
	if (data == -1) return NULL;
	Node *root = new Node(data);

	queue<Node *> q;
	q.push(root);
	Node *p = NULL;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		cout << "Parent is: " << p->data << endl;
		cin >> ldata >> rdata;
		if (ldata != -1)
		{
			p->lchild = new Node(ldata);
			q.push(p->lchild);
		}
		if (rdata != -1)
		{
			p->rchild = new Node(rdata);
			q.push(p->rchild);
		}
	}
	return root;
}

// 中序非递归算法
void in_order_non_recursive(Node *root)
{
	if (root == NULL)
		return;

	stack<Node *> stk;
	stk.push(root);
	Node *p = root->lchild;
	while (!stk.empty() || p!=NULL)
	{
		if (p)
		{
			stk.push(p);
			p = p->lchild;
		}
		else
		{
			p = stk.top();  cout << p->data << " ";
			stk.pop();
			p = p->rchild;
		}
	}
}

// main 函数
int in_order_non_recursive_main()
{
	Node *root = build_tree();
	in_order_non_recursive(root);
	cout << endl;
	system("pause");
	return 0;
}