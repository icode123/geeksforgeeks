//http://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/

struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};

//利用左右结点指针作为前驱后继结点指针；
TreeNode * bintree2listUtil(TreeNode * root)
{
	if (!root)
	{
		return NULL;
	}
	if (root->left)
	{
		TreeNode *left=bintree2listUtil(root->left);
		for (;left->right;left=left->right);
		left->right=root;
		root->left=left;
	}
	if (root->right)
	{
		TreeNode *right=bintree2listUtil(root->right);
		for (;right->left;right=right->left);
		right->left=root;
		root->right=root;
	}
	return root;
}
TreeNode * bintree2list(TreeNode  *root)
{
	if (!root)
	{
		return NULL;
	}
	root=bintree2listUtil(root);
	while (root->left)
	{
		root=root->left;
	}
	return root;
}
