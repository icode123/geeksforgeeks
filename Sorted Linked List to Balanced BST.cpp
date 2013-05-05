//http://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};

struct Node 
{
	int data;
	Node *next;
};

//方法一：自上而下，时间复杂度：O(nLogn)；
/*
1) Get the Middle of the linked list and make it root.
2) Recursively do same for left half and right half.
a) Get the middle of left half and make it left child of the root
created in step 1.
b) Get the middle of right half and make it right child of the
root created in step 1.
*/
//方法二：自下而上，时间复杂度：O(n)；
//自上而下类似于前序遍历，自下而上类似于中序/后序遍历；
int countNodes(Node *head)
{
	int count=0;
	Node *tmp=head;
	while (tmp)
	{
		count++;
		tmp=tmp->next;
	}
	return count;
}
//单链表，所以无法使用前驱后继指针就地转换；
TreeNode* sortedListToBSTRecur(Node **head_ref, int n)
{
	if (n<=0)
	{
		return NULL;
	}
	TreeNode *left=sortedListToBSTRecur(head_ref,n/2);
	TreeNode *root=new TreeNode((*head_ref)->data);
	root->left=left;
	*head_ref=(*head_ref)->next;
	root->right=sortedListToBSTRecur(head_ref,n-n/2-1);
	return root;
}

TreeNode* sortedListToBST(Node *head)
{
	int n=countNodes(head);
	return sortedListToBSTRecur(&head,n);
}
