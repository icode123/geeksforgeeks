//http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
#include <stack>
struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
};

int size(TreeNode *root)
{
	if (!root)
	{
		return 0;
	}
	else return size(root->left)+1+size(root->right);
}
