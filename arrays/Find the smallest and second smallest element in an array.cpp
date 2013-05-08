//时间复杂度：O(n)
void print2Smallest(int arr[], int arr_size)
{
  if (arr_size<2)
	{
		cout<<"invalid input!"<<endl;
	}
	int i,first,second;
	first=second=INT_MAX;
	for (i=0;i<arr_size;i++)
	{
		if (arr[i]<first)
		{
			second=first;
			first=arr[i];
		}
		else if (arr[i]<second)
		{
			second=arr[i];
		}
	}
	cout<<first<<" "<<second<<endl;
}
