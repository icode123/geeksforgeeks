#include <stack>
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inOrderIterative(TreeNode* root)
{
  if (!root)
	{
		return;
	}
	TreeNode* cur=root;
	stack<TreeNode*> s;
	bool done=false;
	while (!done)
	{
		if (cur)
		{
			s.push(cur);
			cur=cur->left;
		}
		else
		{
			if (!s.empty())
			{
				cur=s.top();
				cout<<cur->val<<" ";
				s.pop();
				cur=cur->right;
			}
			else done=true;
		}
	}
}
