#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;
using p = pair<int, int>;
const int INF = 1000000000;
int n, m;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int connect(p fs, p fd, p ss, p sd)
{
	vector<vector<bool>> v(n + 1, vector<bool>(m + 1, false));
	queue<vector<p>> q1;
	queue<pair<p, int>> q2; int l = -1;
	vector<p> init1 = { fs };
	q1.push(init1); q2.push(make_pair(ss, 0));
	v[fs.first][fs.second] = v[ss.first][ss.second] = v[sd.first][sd.second] = true;
	while (!q1.empty())
	{
		vector<p> f = q1.front();
		p b = f.back(); q1.pop();
		if (b.first == fd.first && b.second == fd.second)
		{
			l = f.size() - 1;
			v = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
			for (p e : f) v[e.first][e.second] = true;
			break;
		}
		list<p> dir;
		for (int i = 0; i < 4; i++)
		{
			int nx = b.first + dx[i];
			int ny = b.second + dy[i];
			if (nx < 0 || ny < 0 || nx > n || ny > m || v[nx][ny]) continue;
			if (nx == ss.first || ny == ss.second || nx == sd.first || ny == sd.second)
				dir.push_back(make_pair(nx, ny));
			else
				dir.push_front(make_pair(nx, ny));
		}
		for (p d : dir)
		{
			v[d.first][d.second] = true;
			f.push_back(make_pair(d.first, d.second));
			q1.push(f);
			f.pop_back();
		}
	}
	if (l == -1) return INF;
	v[ss.first][ss.second] = true;
	while (!q2.empty())
	{
		pair<p, int> f = q2.front();
		q2.pop();
		if (f.first.first == sd.first && f.first.second == sd.second)
			return l + f.second;
		for (int i = 0; i < 4; i++)
		{
			int nx = f.first.first + dx[i];
			int ny = f.first.second + dy[i];
			if (nx < 0 || ny < 0 || nx > n || ny > m || v[nx][ny]) continue;
			v[nx][ny] = true;
			q2.push(make_pair(make_pair(nx, ny), f.second + 1));
		}
	}
	return INF;
}
int main()
{
	p a1, a2, b1, b2;
	cin >> n >> m;
	cin >> a1.first >> a1.second;
	cin >> a2.first >> a2.second;
	cin >> b1.first >> b1.second;
	cin >> b2.first >> b2.second;
	int c1 = connect(a1, a2, b1, b2), c2 = connect(b1, b2, a1, a2);
	int ans = min(c1, c2);
	if (ans == INF) cout << "IMPOSSIBLE" << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5022

/*
little hard bfs problem.
I have trouble solving this problem because of the order.
*/