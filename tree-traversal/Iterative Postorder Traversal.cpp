//http://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
/*
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child 
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/

#include <stack>
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Iterative Postorder Traversal (Using One Stack)
void postOrderIterative(TreeNode* root)
{
  if (!root)
	{
		return;
	}
	stack<TreeNode*> s;
	do 
	{
		while (root)
		{
			if (root->right)
			{
				s.push(root->right);
			}
			s.push(root);
			root=root->left;
		}
		root=s.top();
		s.pop();
		if (root->right && root->right==s.top())
		{
			 s.pop();
			 s.push(root);
			 root=root->right;
		}
		else
		{
			cout<<root->val<<" ";
			root=NULL;
		}
	} while (!s.empty());
}
