// http://www.geeksforgeeks.org/find-if-there-is-a-triplet-in-bst-that-adds-to-0/
//方法一：暴力求解法：时间复杂度O(n^3)；
//方法二：辅助数组+有序数组3sum：时间复杂度O(n^2)，空间复杂度O(n)；
//方法三：BST转化为DLL：时间复杂度O(n^2)，空间复杂度O(Logn)；
//方法四：两个中序遍历+一个逆序中序遍历，时间复杂度O(n^2)，空间复杂度O(Logn)；

//方法三
#include <stack>
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// A function to convert given BST to Doubly Linked List. 
void convertBSTtoDLL(TreeNode* root, TreeNode** head, TreeNode** tail)
{
  if (!root)
	{
		return;
	}
	if (root->left)
	{
		convertBSTtoDLL(root->left,head,tail);
	}
	root->left=*tail;
	if (*tail)
	{
		*tail->right=root;
	}
	else
	{
		*head=root;
	}
	*tail=root;
	if (root->right)
	{
		convertBSTtoDLL(root->right,head,tail);
	}
}

// This function returns true if there is pair in DLL with sum equal to given sum.
bool isPresentInDLL(TreeNode* head, TreeNode* tail, int sum)
{
	while (head!=tail)
	{
		int cur=head->val+tail->val;
		if (cur==sum)
		{
			return true;
		}
		else if (cur<sum)
		{
			head=head->right;
		}
		else if (cur>sum)
		{
			tail=tail->left;
		}
	}
	return false;
}

// The main function that returns true if there is a 0 sum triplet in BST otherwise returns false.
bool isTripletPresent(TreeNode *root)
{
	if (!root)
	{
		return false;
	}
	if (!root->left && !root->right)
	{
		return false;
	}
	TreeNode *head=NULL;
	TreeNode *tail=NULL;
	convertBSTtoDLL(root,&head,&tail);

	//我觉得网页上有错误，isPresentInDLL使用的应该是拷贝的指针而不是原指针，否则会影响后面的判断；
	while (head->right!=tail)
	{
		TreeNode *headcur=head;
		TreeNode *tailcur=tail;
		if (isPresentInDLL(headcur->right,tailcur,-1*head->val))
		{
			return true;
		}
		else head=head->right;
	}
	return false;
}

//可能会有DLL到BST的恢复

