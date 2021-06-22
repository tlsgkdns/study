#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<char>> commu;
pair<int, int> start;
int H, W, ans = 10001;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int getDist(pair<int, int> d1, pair<int, int> d2)
{
	return abs(d1.first - d2.first) + abs(d1.second - d2.second);
}
struct cmp
{
	bool operator()(pair<pair<int, int>, pair<int, int>> p1, pair<pair<int, int>, pair<int, int>> p2)
	{
		if (p1.first.first != p2.first.first)
			return p1.first.first > p2.first.first;
		return getDist(p1.second, start) > getDist(p2.second, start);
	}
};
bool is180Degree(int id1, int id2)
{
	if (id1 > id2) return is180Degree(id2, id1);
	return (id1 + 2 == id2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> W >> H;

	commu.resize(H, vector<char>(W));
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
		{
			cin >> commu[i][j];
			if (commu[i][j] == 'C') start = make_pair(i, j);
		}

	priority_queue<pair<pair<int, int>, pair<int, int>>,
		vector<pair<pair<int, int>, pair<int, int>>>, cmp> q;
	vector<vector<vector<bool>>> v(H, vector<vector<bool>>(W, vector<bool>(10001, false)));
	for (int i = 0; i < 4; i++)
	{
		int ny = start.first + dy[i];
		int nx = start.second + dx[i];
		if (ny < 0 || nx < 0 || ny == H || nx == W || commu[ny][nx] == '*') continue;
		q.push(make_pair(make_pair(0, i), make_pair(ny, nx)));
	}
	while (!q.empty())
	{
		int mirror = q.top().first.first;
		int dir = q.top().first.second;
		int y = q.top().second.first;
		int x = q.top().second.second;
		q.pop();
		if (v[y][x][mirror]) continue;
		v[y][x][mirror] = true;
		if (make_pair(y, x) != start && commu[y][x] == 'C')
		{
			ans = mirror;
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (is180Degree(dir, d) || ny < 0 || nx < 0 || ny == H || nx == W ||
				commu[ny][nx] == '*') continue;
			if (dir == d)
			{
				q.push(make_pair(make_pair(mirror, d), make_pair(ny, nx)));
			}
			else
			{
				q.push(make_pair(make_pair(mirror + 1, d), make_pair(ny, nx)));
			}
		}
	}
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/6087