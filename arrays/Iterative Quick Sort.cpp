//递归，快速排序优化（重点）
int partition (int arr[], int l, int h)
{
  int x=arr[h];
	int i=l-1;
	for (int j=l;j<=h-1;j++)
	{
		if (arr[j]<=x)
		{
			i++;
			if (i!=j)
			{
				swap(&arr[i],&arr[j]);
			}
		}
	}
	i++;
	if (i!=j)
	{
		swap(&arr[i],&arr[h]);
	}
	return i;
}
void quickSort(int A[], int l, int h)
{
	if (l<h)
	{
		int p=partition(A,l,h);
		quickSort(A,l,p-1);
		quickSort(A,p+1,h);
	}
}
//迭代，辅助栈Stack，递归版优化也适用于迭代版
#include <stack>
void quickSort1(int A[], int l, int h)
{
	stack<int> s(h-l+1);
	s.push(l);
	s.push(h);
	while (!s.empty())
	{
		h=s.top();s.pop();
		l=s.top();s.pop();
		int p=partition(A,l,h);
		if (p+1<h)
		{
			s.push(p+1);
			s.push(h);
		}
		if (l<p-1)
		{
			s.push(l);
			s.push(p-1);
		}
	}
}
