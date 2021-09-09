#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000001;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

bool inRange(int N, int M, int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < M);
}
int dfs(vector<vector<bool>>& v, vector<vector<bool>>& b, int y, int x, int dir, int depth, int s)
{
	if (depth == s) return 1;
	int ret = INF;
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (inRange(v.size(), v[0].size(), ny, nx) && !v[ny][nx] && b[ny][nx])
	{
		v[ny][nx] = true;
		ret = dfs(v, b, ny, nx, dir, depth + 1, s);
		v[ny][nx] = false;
		return ret;
	}

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i]; nx = x + dx[i];
		if (!inRange(v.size(), v[0].size(), ny, nx) || v[ny][nx] || !b[ny][nx]) continue;
		v[ny][nx] = true;
		ret = min(dfs(v, b, ny, nx, i, depth + 1, s) + 1, ret);
		v[ny][nx] = false;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	int N, M;
	while (cin >> N >> M)
	{
		int cnt = 0;
		char c;
		vector<vector<bool>> b(N, vector<bool>(M)),
			v(N, vector<bool>(M, false));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				cin >> c;
				if (c == '*') b[i][j] = false;
				else
				{
					b[i][j] = true;
					cnt++;
				}
			}
		int a = INF;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (!b[i][j]) continue;
				for (int d = 0; d < 4; d++)
				{
					v[i][j] = true;
					a = min(a, dfs(v, b, i, j, d, 1, cnt));
					v[i][j] = false;
				}
			}

		if (a >= INF) a = -1;
		if (cnt == 1) a = 0;
		ans.push_back(a);
	}
	for (int n = 1; n <= ans.size(); n++)
		cout << "Case " << n << ": " << ans[n - 1] << '\n';
}
// https://www.acmicpc.net/problem/9944