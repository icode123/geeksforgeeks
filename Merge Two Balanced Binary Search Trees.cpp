//http://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/
//平衡BST与BST的树高的区别；
#include <stack>
struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};

//方法一：将小的BST节点插入大的BST中，时间复杂度：Log(n) + Log(n+1) … Log(m+n-1)，介于mLogn~mLog(m+n-1)；
//方法二：中序遍历+合并，时间复杂度：O(m+n)，空间复杂度：O(m+n)；

//合并有序数组；
int *merge(int arr1[], int arr2[], int m, int n)
{
	int *mergedArr=new int[m+n];
	int i=0,j=0,k=0;
	while (i<m && j<n)
	{
		if (arr1[i]<arr2[j])
		{
			mergedArr[k++]=arr1[i++];
		}
		else mergedArr[k++]=arr2[j++];
	}
	while (i<m)
	{
	   mergedArr[k++]=arr1[i++];
	}
	while (j<n)
	{
		mergedArr[k++]=arr2[j++];
	}
	return mergedArr;
}
//BST中序遍历数组存储；
void storeInorder(TreeNode* node, int inorder[], int *index_ptr)
{
	if (!node)
	{
		return;
	}
	storeInorder(node->left,inorder,index_ptr);
	inorder[*index_ptr]=node->val;
	++(*index_ptr);
	storeInorder(node->right,inorder,index_ptr);
}
//有序数组构建BST；
TreeNode* sortedArrayToBST(int arr[], int start, int end)
{
	if (start>end)
	{
		return NULL;
	}
	int mid=(start+end)/2;
	TreeNode *root=new TreeNode(arr[mid]);
	root->left=sortedArrayToBST(arr,start,mid-1);
	root->right=sortedArrayToBST(arr,mid+1,end);
	return root;
}
TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2, int m, int n)
{
	int arr1=new arr1[m];
	int i=0;
	storeInorder(root1,arr1,&i);
	int arr2=new arr1[n];
	int j=0;
	storeInorder(root2,arr2,&j);
	int *mergedArr=merge(arr1,arr2,m,n);
	return sortedArrayToBST(mergedArr,0,m+n-1);
}
//方法三：就地BST--DLL，时间复杂度：O(m+n)；
