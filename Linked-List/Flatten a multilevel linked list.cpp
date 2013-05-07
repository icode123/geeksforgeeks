//http://www.geeksforgeeks.org/flatten-a-linked-list-with-next-and-child-pointers/

//具体题意查看网页，时间复杂度O(n)；
/*
1) Take "cur" pointer, which will point to head of the fist level of the list
2) Take "tail" pointer, which will point to end of the first level of the list
3) Repeat the below procedure while "curr" is not NULL.
I) if current node has a child then
a) append this new child list to the "tail"
tail->next = cur->child
b) find the last node of new child list and update "tail"
tmp = cur->child;
while (tmp->next != NULL)
tmp = tmp->next;
tail = tmp;
II) move to the next node. i.e. cur = cur->next 
*/

struct Node
{
  int data;
	Node *next;
	Node *child;
};

void flattenList(Node *head)
{
	if (!head)
	{
		return;
	}
	Node *cur=head;
	Node *tail=head;
	Node *tmp;
	while (tail->next)
	{
		tail=tail->next;
	}
	while (cur!=tail)
	{
		if (cur->child)
		{
			tail->next=cur->child;
			tmp=cur->child;
			while (tmp->next)
			{
				tmp=tmp->next;
			}
			tail=tmp;
		}
		cur=cur->next;
	}
}
void printList(Node *head)
{
	while (head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
