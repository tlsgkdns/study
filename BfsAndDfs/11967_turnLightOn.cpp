#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> barn[101][101];
bool light[101][101], v[101][101];

int N, M, X, Y, A, B;
bool inRange(int x, int y)
{
	return x > 0 && y > 0 && x <= N && y <= N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, false, sizeof(v));
	memset(light, false, sizeof(light));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> A >> B;
		barn[X][Y].push_back({ A, B });
	}
	int ans = 1;
	light[1][1] = true;
	for (pair<int, int>& p : barn[1][1])
	{
		if (light[p.first][p.second]) continue;
		light[p.first][p.second] = true;
		ans++;
	}
	queue<pair<int, int>> q;
	v[1][1] = true;
	q.push({ 1, 1 });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(nx, ny) || v[nx][ny] || !light[nx][ny]) continue;
			v[nx][ny] = true;
			for (pair<int, int>& p : barn[nx][ny])
			{
				if (light[p.first][p.second]) continue;
				memset(v, false, sizeof(v));
				ans++;
				light[p.first][p.second] = true;
			}
			q.push({ nx, ny });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11967