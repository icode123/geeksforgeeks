/*To convert an inherently recursive procedures to iterative, we need an explicit stack. 
Following is a simple stack based iterative process to print Preorder traversal.*/

#include <stack>
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void  iterativePreorder(TreeNode *root)
{
  if (!root)
	{
		return;
	}
	stack<TreeNode *> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		TreeNode *node=nodeStack.top();
		cout<<node->val<<" ";
		nodeStack.pop();
		if (node->right)
		{
			nodeStack.push(node->right);
		}
		if (node->left)
		{
			nodeStack.push(node->left);
		}
	}
}
