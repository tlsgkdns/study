#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, G[500][500], mid = 0;
bool v[500][500];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> G[i][j];
	mid = ((N * N) / 2) + (N % 2);
	int l = 0, r = 1000001;
	while (l + 1 < r)
	{
		memset(v, false, sizeof(v));
		int m = (l + r) / 2;
		bool f = false;
		for (int i = 0; i < N && !f; i++)
			for (int j = 0; j < N && !f; j++)
				if (!v[i][j])
				{
					int cnt = 1;
					queue<pair<int, int>> q;
					q.push({ i, j });
					v[i][j] = true;
					while (!q.empty())
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();
						for (int d = 0; d < 4; d++)
						{
							int ny = y + dy[d];
							int nx = x + dx[d];
							if (ny < 0 || nx < 0 || ny >= N || nx >= N || v[ny][nx] || abs(G[y][x] - G[ny][nx]) >= m) continue;
							v[ny][nx] = true;
							++cnt;
							q.push({ ny, nx });
						}
					}
					if (cnt >= mid)
					{
						f = true;
						break;
					}
				}
		if (f) r = m;
		else l = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/5846