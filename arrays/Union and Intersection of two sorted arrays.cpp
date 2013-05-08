//时间复杂度：O(m+n)
//Algorithm Union(arr1[], arr2[]):
void printUnion(int arr1[], int arr2[], int m, int n)
{
  int i=0,j=0;
	while (i<m && j<n)
	{
		if (arr1[i]<arr2[j])
		{
			cout<<arr1[i]<<" ";
			i++;
		}
		else if (arr1[i]>arr2[j])
		{
			cout<<arr2[j]<<" ";
			j++;
		}
		else
		{
			cout<<arr2[j++]<<" ";
			i++;
		}
	}
	while (i<m)
	{
		cout<<arr1[i++]<<" ";
	}
	while (j<n)
	{
		cout<<arr2[j++]<<" ";
	}
}

//Algorithm Intersection(arr1[], arr2[]):
int printIntersection(int arr1[], int arr2[], int m, int n)
{
	int i=0,j=0;
	while (i<m && j<n)
	{
		if (arr1[i]<arr2[j])
		{
			i++;
		}
		else if (arr1[i]>arr2[j])
		{
			j++;
		}
		else
		{
			cout<<arr2[j++]<<" ";
			i++;
		}
	}
}
