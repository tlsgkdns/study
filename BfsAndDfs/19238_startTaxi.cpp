#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
vector<vector<bool>> m;
vector<vector<int>> src;
vector<pair<int, int>> dst;
int N, M, F, dm, srcY, srcX, dstY, dstX;
pair<int, int> start;

int bfs1(pair<int, int> st, pair<int, int>& ed)
{
	vector<vector<bool>> v(N, vector<bool>(N, false));
	priority_queue<pair<int, pair<int, int>>> q;
	int ret = -1;
	q.push(make_pair(0, make_pair(-st.first, -st.second)));
	v[st.first][st.second] = true;
	while (!q.empty())
	{
		int cnt = -q.top().first;
		int y = -q.top().second.first;
		int x = -q.top().second.second;
		q.pop();
		if (src[y][x] != 0)
		{
			ed.first = y; ed.second = x;
			ret = cnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || nx >= N || ny >= N
				|| v[ny][nx] || m[ny][nx]) continue;
			v[ny][nx] = true;
			q.push(make_pair(-(cnt + 1), make_pair(-ny, -nx)));
		}
	}
	return ret;
}
int bfs2(pair<int, int> st, pair<int, int>& ed, int n)
{
	vector<vector<int>> v(N, vector<int>(N, -1));
	queue<pair<int, int>> q;
	int ret = -1;
	q.push(st);
	v[st.first][st.second] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (dst[n] == make_pair(y, x))
		{
			ed.first = y; ed.second = x;
			ret = v[y][x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || nx >= N || ny >= N
				|| v[ny][nx] != -1 || m[ny][nx]) continue;
			v[ny][nx] = v[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> F;
	m.resize(N, vector<bool>(N));
	src.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> dm;
			m[i][j] = dm;
		}
	dst.push_back(make_pair(-1, -1));
	cin >> start.first >> start.second;
	start.first--; start.second--;
	for (int i = 1; i <= M; i++)
	{
		cin >> srcY >> srcX >> dstY >> dstX;
		src[srcY - 1][srcX - 1] = i;
		dst.push_back(make_pair(dstY - 1, dstX - 1));
	}
	int fuel = F;
	for (int i = 0; i < M; i++)
	{
		pair<int, int> e1 = { -1, -1 }, e2 = { -1, -1 };
		int c1 = bfs1(start, e1);
		if (c1 > fuel || c1 == -1)
		{
			fuel = -1;
			break;
		}
		fuel -= c1;
		int n = src[e1.first][e1.second];
		src[e1.first][e1.second] = 0;
		int c2 = bfs2(e1, e2, n);
		if (c2 > fuel || c2 == -1)
		{
			fuel = -1;
			break;
		}
		fuel += c2;
		start = e2;
	}
	cout << fuel << '\n';
}

// https://www.acmicpc.net/problem/19238