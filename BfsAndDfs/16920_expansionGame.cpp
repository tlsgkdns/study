#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int S[10], C[1001][1001], ans[10] = { 0, };
int N, M, P, idx = 10, num, F = 0;
char ch;
queue<pii> q[10];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> S[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == '.')
			{
				C[i][j] = -1;
			}
			else if (ch == '#')
			{
				C[i][j] = 0;
				F++;
			}
			else
			{
				num = (ch - '0');
				C[i][j] = num;
				q[num].push({ i, j });
				idx = min(idx, num);
				F++;
			}
		}
	int L = N * M;
	while (F < L)
	{
		for (int t = 0; t < S[idx] && F < L && !q[idx].empty(); t++)
		{
			int s = q[idx].size();
			while (s--)
			{
				int y = q[idx].front().first;
				int x = q[idx].front().second;
				q[idx].pop();
				for (int d = 0; d < 4; d++)
				{
					int ny = y + dy[d];
					int nx = x + dx[d];
					if (!inRange(ny, nx) || C[ny][nx] >= 0) continue;
					C[ny][nx] = C[y][x];
					F++;
					q[idx].push({ ny, nx });
				}
				if (F >= L) break;
			}
		}
		int cnt = 0;
		for (cnt = 0; cnt < P; cnt++)
		{
			idx = (idx % P) + 1;
			if (!q[idx].empty())
				break;
		}
		if (cnt == P) break;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans[C[i][j]]++;
	for (int i = 1; i <= P; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/16920