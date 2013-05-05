struct Node 
{
  int data;
	Node *prev;
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
//将前驱指针当做左孩子指针，将后驱指针当做右孩子指针,二级指针的使用；
Node* sortedListToBSTRecur(Node **head_ref, int n)
{
	if (n<=0)
	{
		return NULL;
	}
	Node *left=sortedListToBSTRecur(head_ref,n/2);
	Node *root=*head_ref;
	root->prev=left;
	*head_ref=(*head_ref)->next;
	root->next=sortedListToBSTRecur(head_ref,n-n/2-1);
	return root;
}

Node* sortedListToBST(Node *head)
{
	int n=countNodes(head);
	return sortedListToBSTRecur(&head,n);
}
