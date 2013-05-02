#include <list>
#include <vector>
// Definition for binary tree
struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*后序遍历比较复杂，它的思路是利用中序遍历，所以首先产生了一个假的根结点，其左子树为原来的二叉树，从假的根结点开始中序遍历
它和中序遍历有所不同，在发现当前结点左子树为空时，不访问此结点(后序遍历需要保证访问完右子树后才能访问根结点)，直接访问右子树。
第二次遍历到某个结点时，将该结点左子树的最右路径反序输出即可，对应函数为bsort_morris_reverse*/

vector<int> ret;

void bst_morris_reverse(TreeNode *node,TreeNode *last,TreeNode *end)
{
  list<int> cur;
	for (TreeNode *i=node;i!=end;i=i->right)
	{
		list.push_front(i->val);
	}
	ret.insert(ret.end(),list.begin(),list.end());
}

vector<int>  morrisTraversalPostorder(TreeNode *root)
{
	TreeNode dummy(-1);
	dummy.left=root;
	TreeNode *p=&dummy;
	while (p)
	{
		if (!p->left)
		{
			p=p->right;
		}
		else
		{
			 TreeNode *tmp=p->left;
			 while (tmp->right && tmp->right!=p)
			 {
				 tmp=tmp->right;
			 }
			 if (!tmp->right)
			 {
				 tmp->right=p;
				 p=p->left;
			 }
			 else
			 {
				 bst_morris_reverse(p->left,tmp,p);  
				 tmp->right=NULL;
				 p=p->right;
			 }
		}
	}
	return ret;
}
