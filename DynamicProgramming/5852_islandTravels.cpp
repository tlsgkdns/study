#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<int>> adj;
const int INF = 1000000000;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int group[51][51], dp[33000][15];
char land[51][51];
vector<pair<int, int>> sPoint;
bool v[51][51];
int R, C, N = 0;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < R && x < C;
}
void dfs(int y, int x, int g)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || land[ny][nx] != 'X' || group[ny][nx] != -1) continue;
		group[ny][nx] = g;
		dfs(ny, nx, g);
	}
}

void bfs(int s)
{
	memset(v, false, sizeof(v));
	deque<pair<int, pair<int, int>>> dq;
	v[sPoint[s].first][sPoint[s].second] = true;
	dq.push_back(make_pair(0, sPoint[s]));
	while (!dq.empty())
	{
		int cnt = dq.front().first;
		int y = dq.front().second.first;
		int x = dq.front().second.second;
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (!inRange(ny, nx) || land[ny][nx] == '.' || v[ny][nx]) continue;
			v[ny][nx] = true;
			if (land[ny][nx] == 'S')
				dq.push_back(make_pair(cnt + 1, make_pair(ny, nx)));
			else
			{
				if (group[ny][nx] == group[y][x])
					dq.push_front(make_pair(cnt, make_pair(ny, nx)));
				else
				{
					adj[s][group[ny][nx]] = min(adj[s][group[ny][nx]], cnt);
					dq.push_front(make_pair(cnt, make_pair(ny, nx)));
				}
			}
		}
	}
}

int dynamic(int route, int here)
{
	int& ret = dp[route][here];
	if (route == pow(2, N) - 1) return 0;
	if (ret != INF) return ret;
	for (int there = 0; there < N; there++)
	{
		if (route & (1 << there)) continue;
		int nr = route | (1 << there);
		ret = min(ret, dynamic(nr, there) + adj[here][there]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(group, -1, sizeof(group));
	for (int i = 0; i < 33000; i++)
		for (int j = 0; j < 15; j++)
			dp[i][j] = INF;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> land[i][j];
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (group[i][j] == -1 && land[i][j] == 'X')
			{
				group[i][j] = N;
				sPoint.push_back({ i, j });
				dfs(i, j, N++);
			}
	adj.resize(N, vector<int>(N, INF));
	int ans = INF;
	for (int i = 0; i < N; i++) bfs(i);
	for (int i = 0; i < N; i++) ans = min(ans, dynamic((1 << i), i));
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5852