//http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};

//递归，时间复杂度：最坏情况下 O(n^2)（退化树）；
void printGivenLevel(TreeNode* root, int level, bool ltr)
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
		if (ltr)
		{
			printGivenLevel(root->left,level-1,ltr);
			printGivenLevel(root->right,level-1,ltr);
		}
		else
		{
			printGivenLevel(root->right,level-1,ltr);
			printGivenLevel(root->left,level-1,ltr);
		}
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
	bool ltr=false;
	for (int i=1;i<=h;i++)
	{
		printGivenLevel(root,i,ltr);
		ltr=~ltr;
	}
}
