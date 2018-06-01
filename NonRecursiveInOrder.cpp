
#include "NonRecursiveInOrder.h"

int NonRecursiveInOrderMain()
{
	Node *root = buildTree();
	nonRecursiveInOrder(root);
	cout << endl;
	system("pause");
	return 0;
}