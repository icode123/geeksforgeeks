//http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/
//注意按引用传递与按值传递的区别

#include <vector>

struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Recursive helper function -- given a node, and an array containing
the path from the root node up to but not including this node,
print out all the root-leaf paths. */
void printPathsRecur(TreeNode* node,vector<vector<int>> &ret,vector<int> ans) 
{
	if (!node) return;

	ans.push_back(node->data);

	/* it's a leaf, so print the path that led to here */
	if (!node->left && !node->right) 
	{
		ret.push_back(ans);
	}
	else 
	{
		/* otherwise try both subtrees */
		printPathsRecur(node->left,ret,ans);
		printPathsRecur(node->right,ret,ans);
	}
}

/* Given a binary tree, print out all of its root-to-leaf
paths, one per line. Uses a recursive helper to do the work.*/   
void printPaths(TreeNode* node) 
{
	vector<vector<int>> ret;
	vector<int> ans;
	printPathsRecur(node,ret,ans);
}





