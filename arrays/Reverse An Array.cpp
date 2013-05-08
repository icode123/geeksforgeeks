//迭代，时间复杂度：O(n)
void reverseArray(int arr[], int start, int end)
{
  int tmp;
	while (start<end)
	{
		tmp=arr[start];
		arr[start]=arr[end];
		arr[end]=tmp;
		start++;
		end--;
	}
}

//递归,时间复杂度：O(n)，空间复杂度：O(n)（递归栈所用空间）
void reverseArray1(int arr[], int start, int end)
{
	if (start>=end)
	{
		return;
	}
	int tmp;
	tmp=arr[start];
	arr[start]=arr[end];
	arr[end]=tmp;
	reverseArray1(arr,start+1,end-1);
}
