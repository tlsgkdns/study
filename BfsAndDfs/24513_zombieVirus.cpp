#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, pair<int, int>>> q;
int N, M, T[1001][1001], v[1001][1001], ans[3];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> T[i][j];
			if (T[i][j] > 0)
			{
				v[i][j] = 0;
				q.push({ T[i][j], {i, j} });
			}
		}
	while (!q.empty())
	{
		int virus = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (T[y][x] == 3) continue;
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || T[ny][nx] < 0) continue;
			if (v[ny][nx] >= 0)
			{
				if (T[ny][nx] != virus && v[y][x] + 1 == v[ny][nx])
					T[ny][nx] = 3;
			}
			else
			{
				T[ny][nx] = virus;
				v[ny][nx] = v[y][x] + 1;
				q.push({ virus,{ ny, nx } });
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (T[i][j] > 0)
				++ans[T[i][j] - 1];
	for (int i = 0; i < 3; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/24513