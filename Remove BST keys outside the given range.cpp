//http://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/

struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};
/*
There are two possible cases for every node.
1) Node’s key is outside the given range. This case has two sub-cases.
…….a) Node’s key is smaller than the min value.
…….b) Node’s key is greater that the max value.
2) Node’s key is in range.

The idea is to fix the tree in Postorder fashion. 
When we visit a node, we make sure that its left and right sub-trees are already fixed. 
In case 1.a), we simply remove root and return right sub-tree as new root. 
In case 1.b), we remove root and return left sub-tree as new root.

*/
//修复树：后序方式，时间复杂度：O(n) ；
TreeNode* removeOutsideRange(TreeNode *root, int min, int max)
{
	if (!root)
	{
		return NULL;
	}
	root->left=removeOutsideRange(root->left,min,max);
	root->right=removeOutsideRange(root->right,min,max);
	if (root->val<min)
	{
		TreeNode *rchild=root->right;
		delete root;
		return rchild;
	}
	if (root->val>max)
	{
		TreeNode *lchild=root->left;
		delete root;
		return lchild;
	}
	return root;
}

