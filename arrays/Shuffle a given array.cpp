//Fisher–Yates shuffle Algorithm，时间复杂度：O(n)
//从后往前，从前往后也行

void randomize ( int arr[], int n )
{
  for (int i=n-1;i>0;--i)
	{
		int j=rand()%(i+1);
		swap(&arr[i],&arr[j]);
	}
}
