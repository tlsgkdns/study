#include <iostream>
#include <vector>
using namespace std;

long long n, b;
vector<vector<int>> simpleMul(const vector<vector<int>> v1, const vector<vector<int>> v2)
{
	int s = v1.size();
	vector<vector<int>> ret(s, vector<int>(s, 0));
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			for (int k = 0; k < s; k++)
			{
				ret[i][j] += v1[i][k] * v2[k][j];
				ret[i][j] %= 1000;
			}

	return ret;
}
vector<vector<int>> mul(const vector<vector<int>> v, long long m)
{
	if (m == 1) return v;
	if (m == 2) return simpleMul(v, v);
	if (m % 2 == 0)
		return mul(simpleMul(v, v), m / 2);
	else
		return simpleMul(mul(simpleMul(v, v), m / 2), v);
}
int main()
{
	cin >> n >> b;
	vector<vector<int>> mat(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat[i][j];
	vector<vector<int>> ans = mul(mat, b);
	for (vector<int> v : ans)
	{
		mat;
		for (int e : v)
			cout << e % 1000 << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/10830