//http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/

//方法一：使用父指针
struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
};

TreeNode * minValue(TreeNode* node)
{
	if (!node)
	{
		return NULL;
	}
	TreeNode* cur=node;
	while (cur->left)
	{
		cur=cur->left;
	}
	return cur;
}

TreeNode * inOrderSuccessor(TreeNode *root, TreeNode *node)
{
	if (node->right)
	{
		return minValue(node->right);
	}
	TreeNode *cur=node->parent;
	while (cur && cur->left!=node)
	{
		node=cur;
		cur=cur->parent;
	}
	return cur;
}

//方法二：从根处搜索
