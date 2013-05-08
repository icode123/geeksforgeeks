#include <vector>
vector<vector<char>> rotate(vector<vector<char>> &source)
{
  if (!source.size() || !source[0].size())
	{
		return;
	}
	vector<vector<char>> des(source.size(),vector<char>(source[0].size()));
	int m=source.size();
	int n=source[0].size();
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
		{
			des[j][m-1-i]=source[i][j];
		}
	return des;
}
