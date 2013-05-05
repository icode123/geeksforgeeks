//http://www.geeksforgeeks.org/given-linked-list-representation-of-complete-tree-convert-it-to-linked-representation/

#include <queue>
struct TreeNode 
{
  int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v):val(v),left(NULL),right(NULL){ }
};
struct ListNode 
{
	int data;
	ListNode *next;
};
/*
At every step, we take the parent node from queue, make next two nodes of linked list as children of the parent node, 
and enqueue the next two nodes to queue.
1. Create an empty queue.
2. Make the first node of the list as root, and enqueue it to the queue.
3. Until we reach the end of the list, do the following.
………a. Dequeue one node from the queue. This is the current parent.
………b. Traverse two nodes in the list, add them as children of the current parent.
………c. Enqueue the two nodes into the queue.
*/
//完全二叉树，层次遍历，同时运用队列和链表遍历，时间复杂度：O(n) ；
void convertList2Binary(ListNode *head, TreeNode* &root)
{
	queue<TreeNode*> q;
	if (!head)
	{
		root=NULL;
		return;
	}
	root=new TreeNode(head->data);
	q.push(root);
	head=head->next;
	while (head)
	{
		TreeNode *parent=q.front();
		q.pop();
		TreeNode *leftChild=NULL,*rightChild=NULL;
		leftChild=new TreeNode(head->data);
		q.push(leftChild);
		head=head->next;
		if (head)
		{
			rightChild=new TreeNode(head->data);
			q.push(rightChild);
			head=head->next;
		}
		parent->left=leftChild;
		parent->right=rightChild;
	}
}


