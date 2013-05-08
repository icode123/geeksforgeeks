//计数排序适用：RANGE与排序个数相差不大（可以离散化映射）；非比较排序；通常作为其他排序算法的子程序；
//修改：范围变为M到N；负数输入；
//离散化映射可以减小计数数组的大小；

//字符数组按字母顺序排序，时间复杂度：O(n+k)，空间复杂度：O(n+k)
const int RANGE=256;//字符集个数
void countSort(char *str)
{
  char output[strlen(str)];
	int count[RANGE+1],i;
	memset(count,0,sizeof(count));
	for (i=0;str[i];i++)
	{
		++count[str[i]];
	}
	for (i=1;i<=RANGE;i++)
	{
		count[i]+=count[i-1];
	}
	for (i=0;str[i];i++)
	{
		while (count[str[i]]>0)
		{
			output[count[str[i]]-1]=str[i];
			count[str[i]]--;
		}
	}
	for (i=0;str[i];i++)
	{
		str[i]=output[i];
	}
}
