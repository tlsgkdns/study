#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;

int N, M, R[1001][1001], v[1001][1001], c = 0, ans = 0, S[1000001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool k[1000001];

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int dfs(int y, int x, int cnt)
{
	if (!inRange(y, x) || v[y][x] >= 0 || R[y][x] == 0) return 0;
	v[y][x] = cnt;
	int ret = 1;
	for (int d = 0; d < 4; d++)
		ret += dfs(y + dy[d], x + dx[d], cnt);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> R[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (R[i][j] == 1 && v[i][j] < 0)
			{
				S[c] = dfs(i, j, c);
				c++;
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (R[i][j] == 0)
			{
				int s = 0;
				for (int d = 0; d < 4; d++)
				{
					int y = dy[d] + i;
					int x = dx[d] + j;
					if (!inRange(y, x) || v[y][x] < 0 || k[v[y][x]]) continue;
					k[v[y][x]] = true;
					s += S[v[y][x]];
				}
				ans = max(ans, s + 1);
				for (int d = 0; d < 4; d++)
				{
					int y = dy[d] + i;
					int x = dx[d] + j;
					if (!inRange(y, x) || v[y][x] < 0) continue;
					k[v[y][x]] = false;
				}
			}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16932