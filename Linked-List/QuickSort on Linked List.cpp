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
void swap ( int* a, int* b )
{   int t = *a;      *a = *b;       *b = t;   }
Node *lastNode(Node *root)
{
	while (root && root->next)
		root = root->next;
	return root;
}
//prev为l的前驱,tmp为分割点的前驱；
Node* partition(Node *l, Node *h,Node *prev,Node * &tmp)
{
	int x  = h->data;
	Node *i =prev;
	for (Node *j = l; j != h; j = j->next)
	{
		if (j->data <= x)
		{
			i = (i == NULL)? l : i->next;
			if (i!=j)
			{
				swap(&(i->data),&(j->data));
			}
		}
	}
	tmp=i;
	i = (i == NULL)? l : i->next; 
	if (i!=h)
	{
		swap(&(i->data),&(h->data));
	}
	return i;
}
void _quickSort(Node* l, Node *h, Node *prev)
{
	if (h && l && l!=h && l!=h->next && h!=prev)
	{
		Node *tmp=NULL;
		Node *p = partition(l,h,prev,tmp);
		_quickSort(l,tmp,prev);
		_quickSort(p->next,h,p);
	}
}
void quickSort(Node *head)
{
	Node *h = lastNode(head);
	_quickSort(head,h,NULL);
}
