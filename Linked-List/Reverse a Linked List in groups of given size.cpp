//http://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
/*
Example:
Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
Output:  3->2->1->6->5->4->8->7->NULL. 

Inputs:   1->2->3->4->5->6->7->80->NULL and k = 5
Output:  5->4->3->2->1->8->7->6->NULL. 
*/
//时间复杂度：O(n) 
struct Node
{
  int data;
	Node *next;
};

Node *reverse (Node *head, int k)
{
	Node *cur=head;
	Node *pre=NULL;
	Node *next;
    int count=0;
	while (cur && count<k)
	{
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
		count++;
	}
	if (next)
	{
		head->next=reverse(next,k);
	}
	return pre;
}
