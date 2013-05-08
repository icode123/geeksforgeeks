//暴力求解法，时间复杂度：O(n^2)
void minAbsSumPair(int arr[], int arr_size)
{
  if (arr_size<2)
	{
		cout<<"invalid input!"<<endl;
		return;
	}
	int l,r,min_sum,sum,min_l,min_r;
	min_l=0;
	min_r=1;
	min_sum=arr[0]+arr[1];
	for (l=0;l<arr_size-1;l++)
	{
		for (r=l+1;r<arr_size;r++)
		{
			sum=arr[l]+arr[r];
			if (abs(min_sum)>abs(sum))
			{
				min_sum=sum;
				min_l=l;
				min_r=r;
			}
		}
	}
	cout<<arr[min_l]<<" "<<arr[min_r]<<endl;
}
//排序，时间复杂度：O(nlogn)
void quickSort(int *, int, int);
void minAbsSumPair(int arr[], int n)
{
	if (arr_size<2)
	{
		cout<<"invalid input!"<<endl;
		return;
	}
	int sum,min_sum=INT_MAX;
	int l=0,r=n-1;
	int min_l=0,min_r=n-1;
	quickSort(arr,l,r);
	while (l<r)
	{
		sum=arr[l]+arr[r];
		if (abs(min_sum)>abs(sum))
		{
			min_sum=sum;
			min_l=l;
			min_r=r;
		}
		if (sum<0)
		{
			l++;
		}
		else r--;
	}
	cout<<arr[min_l]<<" "<<arr[min_r]<<endl;
}
