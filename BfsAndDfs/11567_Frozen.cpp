#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int N, M, r1, c1, r2, c2;
bool v[501][501];
char ch;
string ans = "NO\n";
bool inRange(int y, int x)
{
	return y > 0 && x > 0 && y <= N && x <= M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			cin >> ch;
			if (ch == 'X') v[i][j] = true;
			else v[i][j] = false;
		}
	cin >> r1 >> c1;
	cin >> r2 >> c2;
	q.push({ r1, c1 });
	v[r1][c1] = true;
	while (!q.empty() && ans != "YES\n")
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx)) continue;
			if (v[ny][nx] && ny == r2 && nx == c2)
			{
				ans = "YES\n";
				break;
			}
			if (v[ny][nx]) continue;
			v[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
	cout << ans;
}

// https://www.acmicpc.net/problem/11567