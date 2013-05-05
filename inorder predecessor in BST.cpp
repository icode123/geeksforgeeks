//与求解后继相似
//方法一：使用父指针，时间复杂度：O(h)；
struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *parent;
};

TreeNode * maxValue(TreeNode* node)
{
	if (!node)
	{
		return NULL;
	}
	TreeNode* cur=node;
	while (cur->right)
	{
		cur=cur->right;
	}
	return cur;
}

TreeNode * inOrderPredecessor(TreeNode *root, TreeNode *node)
{
	if (!root)
	{
		return NULL;
	}
	if (node->left)
	{
		return minValue(node->left);
	}
	TreeNode *cur=node->parent;
	while (cur && cur->right!=node)
	{
		node=cur;
		cur=cur->parent;
	}
	return cur;
}

//方法二：从根处搜索，不需要父指针，时间复杂度：O(h)；
TreeNode * inOrderPredecessor1(TreeNode *root, TreeNode *node)
{
	if (!root)
	{
		return NULL;
	}
	if (node->left)
	{
		return maxValue(node->left);
	}
	TreeNode *succ=NULL;
	while (root)
	{
		if (node->val>root->val)
		{
			succ=root;
			root=root->right;
		}
		else if (node->val<root->val)
		{
			root=root->left;
		}
		else break;
	}
	return succ;
}
