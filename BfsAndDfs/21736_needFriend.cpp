#include <iostream>
#include <queue>

using namespace std;
int N, M;
bool v[601][601];
char ch;
int C[601][601], sy, sx, ans = 0;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> ch;
			if (ch == 'X') C[i][j] = -1;
			if (ch == 'O') C[i][j] = 0;
			if (ch == 'P') C[i][j] = 1;
			if (ch == 'I')
			{
				sy = i;
				sx = j;
				C[i][j] = 0;
			}
		}
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	v[sy][sx] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = dy[d] + y;
			int nx = dx[d] + x;
			if (ny < 0 || nx < 0 || y >= N || x >= M || v[ny][nx] || C[ny][nx] < 0) continue;
			v[ny][nx] = true;
			ans += C[ny][nx];
			q.push({ ny, nx });
		}
	}
	if (ans == 0) cout << "TT\n";
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/21736