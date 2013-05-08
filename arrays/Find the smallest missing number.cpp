/*
Given a sorted array of n integers where each integer is in the range from 0 to m-1 and m > n. 
Find the smallest number that is missing from the array. 
*/

//方法一：二分查找，时间复杂度：O(m log n) 

//For i = 0 to m-1,二分查找i，如果不存在就返回其值。

//方法二：线性查找，时间复杂度：O(n)

/*
If arr[0] is not 0, return 0. Otherwise traverse the input array starting from index 1, 
and for each pair of elements a[i] and a[i+1], find the difference between them. 
if the difference is greater than 1 then a[i]+1 is the missing number. 
*/

//方法三：修改的二分查找，时间复杂度：O(Logn)
//前提：没有重复数字
int findFirstMissing(int array[], int start, int end)
{
  if (start>end)
	{
		return end+1;
	}
	if (start!=array[start])
	{
		return start;
	}
	int mid=(start+end)/2;
	if (array[mid]>mid)
	{
		return findFirstMissing(array,start,mid-1);
	}
	else return findFirstMissing(array,mid+1,end);
}




