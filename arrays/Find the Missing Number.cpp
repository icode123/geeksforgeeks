//方法一：和公式，时间复杂度：O(n)
//total可能会溢出
int getMissingNo (int a[], int n)
{
  int i,total;
	total=(n+1)*(n+2)/2;
	for (i=0;i<n;i++)
	{
		total-=a[i];
	}
	return total;
}
//方法二：Use XOR
/*
1) XOR all the array elements, let the result of XOR be X1.
2) XOR all numbers from 1 to n, let XOR be X2.
3) XOR of X1 and X2 gives the missing number.
*/

int getMissingNo(int a[], int n)
{
	int i;
	int x1=a[0];
	int x2=1;
	for (i=1;i<n;i++)
	{
		x1=x1^a[i];
	}
	for (i=2;i<=n+1;i++)
	{
		x2=x2^i;
	}
	return x1^x2;
}
