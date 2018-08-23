/* nowcoder 二叉树与双向链表：将二叉树转换成双向链表
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void in_order(TreeNode* root, TreeNode* &pre) {
		// 线索化左子树
		if (root->left)
			in_order(root->left, pre);
        
		// 链接左子树与根节点
		if (pre)
			pre->right = root;
		root->left = pre;
		pre = root;
        
		// 线索化右子树
		if (root->right)
			in_order(root->right, pre);
        
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* root = pRootOfTree;
        if (!root) return NULL;
        
        TreeNode* pre=NULL;
        in_order(root, pre);
        
		// 直接在双向链表中寻找中序遍历的第一个节点，即为双向链表的头结点
        TreeNode *p=root;
        while (p->left) p = p->left;
        root = p;
		
        return root;
    }
};
