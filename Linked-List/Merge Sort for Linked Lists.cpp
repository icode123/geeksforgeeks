//http://www.geeksforgeeks.org/merge-sort-for-linked-list/

//链表的归并排序相对于其他排序算法有较大优势，时间复杂度：O(nLogn)；

/*
MergeSort(headRef)
1) If head is NULL or there is only one element in the Linked List 
then return.
2) Else divide the linked list into two halves.  
FrontBackSplit(head, &a, &b); //a and b are two halves 
3) Sort the two halves a and b.
MergeSort(a);
MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
and update the head pointer using headRef.
*headRef = SortedMerge(a, b);
*/

struct Node 
{
  int data;
	Node *next;
};

Node* SortedMerge(Node* a, Node* b)
{
	Node *result=NULL;
	if (!a)
	{
		return b;
	}
	if (!b)
	{
		return a;
	}
	if (a->data<b->data)
	{
		result=a;
		result->next=SortedMerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=SortedMerge(a,b->next);
	}
	return result;
}
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
	Node *slow,*fast;
	if (!source || !head->next)
	{
		*frontRef=source;
		*backRef=NULL;
	}
	else
	{
		slow=source;
		fast=source->next;
		while (fast)
		{
			fast=fast->next;
			if (fast)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		*frontRef=source;
		*backRef=slow->next;
		slow->next=NULL;
	}
}

//头指针的引用；
void MergeSort(Node** headRef)
{
	Node *head=*headRef;
	Node *a,*b;
	if (!head || !head->next)
	{
		return;
	}
	FrontBackSplit(head,&a,&b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef=SortedMerge(a,b);
}
