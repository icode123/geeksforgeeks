//http://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space/

//迭代中序遍历，时间复杂度O(m+n)，空间复杂度O(h1+h2)；
#include <stack>
struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
};

void inorder(TreeNode *root)
{
	if (root)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

void merge(TreeNode *root1,TreeNode *root2)
{
	if (!root1)
	{
		inorder(root2);
		return;
	}
	if (!root2)
	{
		inorder(root1);
		return;
	}
	stack<TreeNode *> s1,s2;
	TreeNode *cur1=root1,*cur2=root2;
	while (cur1||cur2||!s1.empty()||!s2.empty())
	{
		if (cur1||cur2)
		{
			if (cur1)
			{
				s1.push(cur1);
				cur1=cur1->left;
			}
			if (cur2)
			{
				s2.push(cur2);
				cur2=cur2->left;
			}
		}
		else
		{
			if (s1.empty())
			{
				while (!s2.empty())
				{
					cur2=s2.top();
					s2.pop();
					cur2->left=NULL;
					inorder(cur2);
				}
				return;
			}
			if (s2.empty())
			{
				while (!s1.empty())
				{
					cur1=s1.top();
					s1.pop();
					cur1->left=NULL;
					inorder(cur1);
				}
				return;
			}
			cur1=s1.top();cur2=s2.top();
			s1.pop();s2.pop();
			if (cur1->val<cur2->val)
			{
				cout<<cur1->val<<" ";
				cur1=cur1->right;
				s2.push(cur2);
				cur2=NULL;
			}
			else
			{
				cout<<cur2->val<<" ";
				cur2=cur2->right;
				s1.push(cur1);
				cur1=NULL;
			}
		}
	}
}
