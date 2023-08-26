#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int INF = 1000000007;
int N, M, P[31][31], D[31][31], ans = -1, cnt = 0;
int dy[8] = { -1, -1, 1, 1, 2, 2, -2, -2 };
int dx[8] = { -2, 2, -2, 2, -1, 1, -1, 1 };
pii spos, epos;
ll C[31][31];
vector<pii> adj[31][31];
bool v[31][31];
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}

void dfs(int y, int x, int cy, int cx)
{
	if (P[cy][cx] != 1 && !(y == cy && x == cx))
	{
		adj[y][x].push_back({ cy, cx });
		return;
	}
	for (int d = 0; d < 8; d++)
	{
		int ny = cy + dy[d];
		int nx = cx + dx[d];
		if (!inRange(ny, nx) || v[ny][nx] || P[ny][nx] == 2) continue;
		v[ny][nx] = true;
		dfs(y, x, ny, nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> P[i][j];
			D[i][j] = INF;
			if (P[i][j] == 3) spos = { i, j };
			if (P[i][j] == 4) epos = { i, j };
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (P[i][j] == 2) continue;
			memset(v, false, sizeof(v));
			v[i][j] = true;
			dfs(i, j, i, j);
		}
	priority_queue<pair<int, pii>> pq;
	pq.push({ 0, spos });
	D[spos.first][spos.second] = 0;
	C[spos.first][spos.second] = 1;
	while (!pq.empty())
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int c = -pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[y][x].size(); i++)
		{
			int ny = adj[y][x][i].first;
			int nx = adj[y][x][i].second;
			if (D[ny][nx] < c + 1) continue;
			if (D[ny][nx] == c + 1)
				C[ny][nx] += C[y][x];
			else
			{
				D[ny][nx] = c + 1;
				C[ny][nx] = C[y][x];
				pq.push({ -(c + 1), {ny ,nx} });
			}
		}
	}
	if (D[epos.first][epos.second] == INF) cout << -1 << '\n';
	else cout << D[epos.first][epos.second] - 1 << '\n' << C[epos.first][epos.second] << '\n';
}

// https://www.acmicpc.net/problem/1857