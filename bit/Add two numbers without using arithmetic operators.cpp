//XOR(^) AND(&)

//迭代
int Add(int x, int y)
{
  while (y!=0)
	{
		int carry=x&y;
		x=x^y;
		y=carry<<1;
	}
	return x;
}
//递归
int Add(int x, int y)
{
	if (y==0)
	{
		return x;
	}
	else return Add(x^y,(x&y)<<1);
}
