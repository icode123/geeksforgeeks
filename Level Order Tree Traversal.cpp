//http://www.geeksforgeeks.org/level-order-tree-traversal/

struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};

//方法一：递归，时间复杂度：最坏情况下 O(n^2)（退化树）；
void printGivenLevel(TreeNode* root, int level)
{
	if (!root)
	{
		return;
	}
	if (level==1)
	{
		cout<<root->val<<" ";
	}
	else if (level>1)
	{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}
int height(TreeNode* node)
{
	if (!node)
	{
		return 0;
	}
	else return	 1+max(height(node->left),height(node->right));
}
void reverseLevelOrder(TreeNode* root)
{
	int h=height(root);
	for (int i=1;i<=h;i++)
	{
		printGivenLevel(root,i);
	}
}

//方法二：BFS，使用队列，时间复杂度：O(n)；
#include <stack>
#include <queue>
void reverseLevelOrder(TreeNode* root)
{
	if (!root)
	{
		return;
	}
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		root=q.front();
		cout<<root->val<<" ";
		q.pop();
		if (root->left)
		{
			q.push(root->left);
		}
		if (root->right)
		{
			q.push(root->right);
		}
	}
}

