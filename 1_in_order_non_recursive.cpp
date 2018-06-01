/*

�����ܣ�ʵ�ֶ�����������ǵݹ�����㷨
�㷨������
	1���������ݽṹ����������
	2������������ݹ��������
	3������ǵݹ����
		���ڵ��ջ����ջ�ǿ�ʱ��ָ��p�ǿ�ʱ��
			ȡջ��Ԫ��
			��������ӣ������ӽ�ջ
			���û�����ӣ��������ջ����ջ����������Һ��ӣ����Һ��ӽ�ջ
		0��������ڵ�Ϊ�գ����������
		1����ָ��p=root->lchild,�����ڵ���ջ
		2����ջ�ǿջ�p�ǿ�ʱ����������ѭ��
		3�����p�ǿգ���p��ջ��p=p->lchild��
		   ����pȡջ������ջ����ջ��pָ��p���Һ���;
*/


#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

// ���ڵ�
struct Node
{
	int data;
	Node *lchild;
	Node *rchild;
	// ���캯��
	Node(int data)
	{
		this->data = data;
		lchild = rchild = NULL;
	}
};

// ��α�������
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

// ����ǵݹ��㷨
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

// main ����
int in_order_non_recursive_main()
{
	Node *root = build_tree();
	in_order_non_recursive(root);
	cout << endl;
	system("pause");
	return 0;
}