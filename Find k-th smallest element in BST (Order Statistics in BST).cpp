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
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//产生重复计算，需要优化
int getNum(TreeNode* node)
{
	if (!node)
	{
		return 0;
	}
	else return getNum(node->left)+getNum(node->right)+1;
}
//优化版
/*
map<TreeNode*,int> hash;
int getNum(TreeNode* node)
{
	if (!node)
	{
		return 0;
	}
	else if (!node->left && !node->right)
	{
		return 1;
	}
	else 	
	{
		if (hash.find(node)==hash.end())
		{
			if (hash.find(node->left)==hash.end())
			{
				hash[node->left]=getNum(node->left);
			}
			if (hash.find(node->right)==hash.end())
			{
				hash[node->right]=getNum(node->right);
			}
			hash[node]=hash[node->left]+hash[node->right]+1;
		}
		return hash[node];
	}
}
*/
TreeNode *k_smallest_element_inorder2(TreeNode* root,int k)
{
	if (!root || k<=0)
	{
		return NULL;
	}
	int num=getNum(root->left)+1;
	if (k==num)
	{
		return root;
	}
	else if (k<num)
	{
		return k_smallest_element_inorder2(root->left,k);
	}
	else if (k>num)
	{
		return k_smallest_element_inorder2(root->right,k-num);
	}
}

//方法三：递归实现，按照左根右的顺序来实现；
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *k_smallest_element_inorder3(TreeNode* root,int &k)
{
	if (!root || k<=0)
	{
		return NULL;
	}
	TreeNode* left=k_smallest_element_inorder3(root->left,k);
	if (left)
	{
		return left;
	}
	--k;
	if (!k)
	{
		return root;
	}
	TreeNode* right=k_smallest_element_inorder3(root->right,k);
	return right;
}



