//http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/

//寻找BST中第K小元素
//方法一：中序遍历，时间复杂度O(n)；
#include <stack>

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
TreeNode *k_smallest_element_inorder(TreeNode* root,int k) 
{
	if (!root || k<=0)
	{
		return NULL;
	}
	stack<TreeNode*> s;
	while (root)
	{
		s.push(root);
		root=root->left;
	}
	TreeNode *node=NULL;
	while (!s.empty())
	{
		node=s.top();
		s.pop();
		if (!(--k))
		{
			break;
		}
		if (node->right)
		{
			node=node->right;
			while (node)
			{
				s.push(node);
				node=node->left;
			}
		}
	}
	if (k)
	{
		return NULL;
	}
	return node;
}

//方法二：扩张树节点数据结构，每个节点维护一个所在子树节点总个数的域；





