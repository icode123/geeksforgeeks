
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void  morrisTraversalPreorder(TreeNode *root)
{
  while (root)
	{
		if (!root->left)
		{
			cout<< root->val<<" ";
			root=root->right;
		}
		else
		{
			 TreeNode *tmp=root->left;
			 while (tmp->right && tmp->right!=root)
			 {
				 tmp=tmp->right;
			 }
			 if (!tmp->right)
			 {
				 cout<<	root->val<<" ";
				 tmp->right=root;
				 root=root->left;
			 }
			 else
			 {
				 tmp->right=NULL;
				 root=root->right;
			 }
		}
	}
}
