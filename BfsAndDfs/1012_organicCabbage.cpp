#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool inRange(int y, int x, int N, int M)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, M, N, K, X, Y;
	vector<int> anss;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> K;
		vector<vector<bool>> farm(N, vector<bool>(M, false)), v(N, vector<bool>(M, false));
		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			farm[Y][X] = true;
		}
		int ans = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				if (!farm[i][j] || v[i][j]) continue;
				ans++;
				queue<pair<int, int>> q;
				v[i][j] = true;
				q.push({ i, j });
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int d = 0; d < 4; d++)
					{
						int ny = y + dy[d];
						int nx = x + dx[d];
						if (!inRange(ny, nx, N, M) || !farm[ny][nx] || v[ny][nx]) continue;
						v[ny][nx] = true;
						q.push({ ny, nx });
					}
				}
			}
		anss.push_back(ans);
	}
	for (int ans : anss) cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1012