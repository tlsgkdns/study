#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> field;
vector<vector<int>> cache;

int pst(int y, int x, const int m, const int n)
{
	if (y >= m || x >= n) return 0;
	int& r = cache[y][x];
	if (r != -1) return r;
	if (field[y][x] != 0) return r = 0;

	r = 1;
	int s1 = pst(y + 1, x, m, n);
	int s2 = pst(y, x + 1, m, n);
	int s3 = pst(y + 1, x + 1, m, n);
	if (s1 != 0 && s2 != 0 && s3 != 0) r = min(s1, min(s2, s3)) + 1;

	return r;
}
int main()
{
	int m, n;
	cin >> m >> n;
	field.resize(m, vector<int>(n));
	cache.resize(m, vector<int>(n, -1));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> field[i][j];

	int ans = -1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, pst(i, j, m, n));
		}
	}

	cout << ans << '\n';
	return 0;
}

// https://www.acmicpc.net/problem/14925