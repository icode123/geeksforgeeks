
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void  morrisTraversalInorder(TreeNode *root)
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
				 tmp->right=root;
				 root=root->left;
			 }
			 else
			 {
				 cout<<	root->val<<" ";
				 tmp->right=NULL;
				 root=root->right;
			 }
		}
	}
}
