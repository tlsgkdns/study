#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N, v[1501][1501][3], ans = 0;
string M;
char k[3] = { 'B', 'L', 'D' };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> M;
	memset(v, -1, sizeof(v));
	queue<pair<pair<int, int>, int>> q;
	N *= 3;
	q.push({ {0, N - 1}, 0 });
	v[0][N - 1][0] = 0;
	while (!q.empty())
	{
		int l = q.front().first.first;
		int r = q.front().first.second;
		int now = q.front().second;
		q.pop();
		ans = max(ans, v[l][r][now]);
		if (l > r) break;
		int nxt = (now + 1) % 3;
		if (k[now] == M[l] && v[l + 1][r][nxt] < 0)
		{
			v[l + 1][r][nxt] = v[l][r][now] + 1;
			q.push({ {l + 1, r}, nxt });
		}
		if (k[now] == M[r] && v[l][r - 1][nxt] < 0)
		{
			v[l][r - 1][nxt] = v[l][r][now] + 1;
			q.push({ {l, r - 1}, nxt });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14677