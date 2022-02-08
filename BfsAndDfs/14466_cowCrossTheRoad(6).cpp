#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
const int MAX = 101;
vector<pii> adj[MAX][MAX];
vector<pii> pos;
bool cow[MAX][MAX], v[MAX][MAX];
int N, K, R, R1, C1, R2, C2, ans;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool inRange(int y, int x)
{
	return (y > 0 && x > 0 && y <= N && x <= N);
}

void bfs(int sy, int sx)
{
	memset(v, false, sizeof(v));
	queue<pii> q;
	q.push({ sy, sx });
	v[sy][sx] = true;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < (int)adj[y][x].size(); i++)
		{
			int ny = adj[y][x][i].first;
			int nx = adj[y][x][i].second;
			if (v[ny][nx]) continue;
			v[ny][nx] = true;
			if (cow[ny][nx]) ans--;
			q.push({ ny, nx });
		}
	}
	cow[sy][sx] = false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> R;
	ans = (K * (K - 1)) / 2;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (!inRange(ny, nx)) continue;
				adj[i][j].push_back({ ny, nx });
			}
		}
	for (int i = 0; i < R; i++)
	{
		cin >> R1 >> C1 >> R2 >> C2;
		adj[R1][C1].erase(find(adj[R1][C1].begin(), adj[R1][C1].end(), make_pair(R2, C2)));
		adj[R2][C2].erase(find(adj[R2][C2].begin(), adj[R2][C2].end(), make_pair(R1, C1)));
	}
	for (int i = 0; i < K; i++)
	{
		cin >> R1 >> C1;
		cow[R1][C1] = true;
		pos.push_back({ R1, C1 });
	}
	for (int i = 0; i < K; i++)
		bfs(pos[i].first, pos[i].second);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14466