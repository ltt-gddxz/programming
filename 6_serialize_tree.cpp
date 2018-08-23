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
        if (root->left)
            in_order(root->left, pre);
        
        if (pre)
            pre->right = root;
        root->left = pre;
        pre = root;
        
        if (root->right)
            in_order(root->right, pre);
        
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* root = pRootOfTree;
        if (!root) return NULL;
        
        TreeNode* pre=NULL;
        in_order(root, pre);
        
        TreeNode *p=root;
        while (p->left) p = p->left;
        root = p;
        return root;
    }
};
