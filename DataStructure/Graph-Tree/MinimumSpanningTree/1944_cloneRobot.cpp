#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, ans = 0, num = 0, cnt = 0;
char M[51][51];
int v[51][51], P[251], adj[251][251], key[251][251];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<pair<int, pair<int, int>>> edges;
int find(int u)
{
	if (u == P[u]) return u;
	return P[u] = find(P[u]);
}

void merge(int a, int b)
{
	if (a > b) swap(a, b);
	a = find(a); b = find(b);
	P[a] = b;
}
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N&& x < N;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(adj, -1, sizeof(adj));
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == '1' || M[i][j] == '0') continue;
			key[i][j] = num++;
		}
	for (int i = 0; i <= K; i++) P[i] = i;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (M[i][j] == '1' || M[i][j] == '0') continue;
			memset(v, -1, sizeof(v));
			v[i][j] = 0;
			queue<pair<int, int>> q;
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
					if (!inRange(ny, nx) || M[ny][nx] == '1' || v[ny][nx] >= 0) continue;
					v[ny][nx] = v[y][x] + 1;
					if (M[ny][nx] == 'K')
					{
						if (adj[key[i][j]][key[ny][nx]] >= 0) continue;
						edges.push_back({ v[ny][nx], {key[i][j], key[ny][nx]} });
						adj[key[i][j]][key[ny][nx]] = v[ny][nx];
						adj[key[ny][nx]][key[i][j]] = v[ny][nx];
					}
					q.push({ ny, nx });
				}
			}
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (find(a) != find(b))
		{
			ans += cost;
			merge(a, b);
			cnt++;
		}
	}
	if (cnt < K) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1944