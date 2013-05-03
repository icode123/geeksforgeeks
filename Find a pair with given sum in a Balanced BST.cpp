// http://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/
//方法一：暴力求解法：O(n^2)；
//方法二：辅助数组，中序遍历，转化为有序数组求2sum问题，时间复杂度O(n)，空间复杂度O(n)；
//方法三：BST转化为DLL，时间复杂度O(n)，空间复杂度O(Logn)，需改变BST；
//方法四：中序遍历和反中序遍历求出最大最小值，类似于有序数组求2sum问题，时间复杂度O(n)，空间复杂度O(Logn)；

#include <stack>
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isPairPresent(TreeNode *root, int target)
{
  if (!root)
	{
		return false;
	}
	if (!root->left && !root->right)
	{
		return false;
	}
	stack<TreeNode *> s1;
	stack<TreeNode *> s2;
	bool done1=false,done2=false;
	TreeNode *cur1=root,*cur2=root;
	int val1,val2;
	while (1)
	{
		while (!done1)
		{
			if (cur1)
			{
				s1.push(cur1);
				cur1=cur1->left;
			}
			else
			{
				if (s1.empty())
				{
					done1=true;
				}
				else
				{
					cur1=s1.top();
					val1=cur1->val;
					s1.pop();
					cur1=cur1->right;
					done1=true;
				}
			}
		}
		while (!done2)
		{
			if (cur2)
			{
				s2.push(cur2);
				cur2=cur2->right;
			}
			else
			{
				if (s2.empty())
				{
					done2=true;
				}
				else
				{
					cur2=s2.top();
					val2=cur2->val;
					s2.pop();
					cur2=cur2->left;
					done2=true;
				}
			}
		}
		if (val1+val2==target)
		{
			return true;
		}
		else if (val1+val2<target)
		{
			done1=false;
		}
		else if (val1+val2>target)
		{
			done2=false;
		}
		//有重复计算的，考虑在树节点中加入访问标志，防止被遍历两次；
		if ((!cur1 && s1.empty()) || (!cur2 && s2.empty()))
		{
			return false;
		}
	}
}



