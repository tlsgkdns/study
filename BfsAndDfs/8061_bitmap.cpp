#include <iostream>
#include <queue>
using namespace std;

const int INF = 1000000000;
char bm[183][183];
int ans[183][183];
int N, M;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
void bfs(int r, int c)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ {r, c}, 0 });
	ans[r][c] = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || ans[ny][nx] <= cnt + 1) continue;
			if (bm[ny][nx] == '1')
			{
				ans[ny][nx] = 0;
				q.push({ {ny, nx}, 0 });
			}
			else
			{
				ans[ny][nx] = cnt + 1;
				q.push({ {ny, nx}, cnt + 1 });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> bm[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans[i][j] = INF;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (bm[i][j] == '0') continue;
			bfs(i, j);
			break;
		}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}

}

// https://www.acmicpc.net/problem/8061