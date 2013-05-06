//http://www.geeksforgeeks.org/quicksort-for-linked-list/

//链表快速排序，最坏情况：O(n^2)，平均情况：O(nLogn)
//双向链表
struct Node 
{
  int data;
	Node *prev;
	Node *next;
};
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
Node *lastNode(Node *head)
{
	Node *node=head;
	while (node && node->next)
	{
		node=node->next;
	}
	return node;
}
Node* partition(Node *l, Node *h)
{
	int data=h->data;
	Node *i=l->prev;
	for (Node *j=l;j!=h;j=j->next)
	{
		if (j->data<=data)
		{
			i = i==NULL ? l:i->next;
			if (i!=j)
			{
				swap(&(i->data),&(j->data));
			}
		}
	}
	i = i==NULL ? l:i->next;
	if (i!=h)
	{
		swap(&(i->data),&(h->data));
	}
	return i;
}
void _quickSort(Node* l, Node *h)
{
	if (h && l && l!=h && l!=h->next && h!=l->prev)
	{
		Node* p=partition(l,h);
		_quickSort(l,p->prev);
		_quickSort(p->next,h);
	}
}
void quickSort(Node *head)
{
	Node *h=lastNode(head);
	_quickSort(head,h);
}
//单链表
struct Node 
{
	int data;
	Node *next;
};
