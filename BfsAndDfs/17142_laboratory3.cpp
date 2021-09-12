#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

const int INF = 2501;
vector<vector<int>> lab;
int N, M, ans = INF, cnt = 1, emp = 0;
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < N);
}
int bfs(vector<bool>& active)
{
	int fill = 0, ret = 0;
	vector<vector<int>> v(N, vector<int>(N, -1));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (lab[i][j] <= 0 || !active[lab[i][j]]) continue;
			v[i][j] = 0;
			q.push({ i, j });
		}
	while (!q.empty())
	{
		if (emp == fill) return ret;
		v;
		int t = 0;
		int sz = q.size();
		for (; t < sz; t++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (!inRange(ny, nx) || v[ny][nx] != -1 || lab[ny][nx] == -1) continue;
				v[ny][nx] = v[y][x] + 1;
				if (lab[ny][nx] == 0) fill++;
				q.push({ ny, nx });
			}
		}
		ret++;
	}
	return INF;
}
void solve(vector<bool>& active, int d, int s)
{
	if (d == M)
	{
		ans = min(ans, bfs(active));
		return;
	}
	for (int i = s; i < active.size(); i++)
	{
		active[i] = true;
		solve(active, d + 1, i + 1);
		active[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	lab.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 0) emp++;
			if (lab[i][j] == 1) lab[i][j] = -1;
			if (lab[i][j] == 2)
			{
				lab[i][j] = cnt;
				cnt++;
			}
		}
	vector<bool> active(cnt, false);
	solve(active, 0, 1);
	if (ans >= 2501) ans = -1;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/17142