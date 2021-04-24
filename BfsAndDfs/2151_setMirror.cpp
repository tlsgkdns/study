#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
char room[51][51];
int n, ans = 0;
vector<p> pos;
bool visited[51][51][4];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
p operator+(p p1, p p2)
{
	return make_pair(p1.first + p2.first, p1.second + p2.second);
}
bool operator<(p pr, int num)
{
	return ((pr.first < num) || (pr.second < num));
}
bool operator>(p pr, int num)
{
	return ((pr.first > num) || (pr.second > num));
}
p getReflect(int idx)
{
	if (idx == 0 || idx == 1) return { 2, 3 };
	else return { 0, 1 };
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == '#') pos.push_back({ i, j });
			if (room[i][j] == '!') ans++;
		}
	priority_queue<pair<int, pair<p, int>>> q;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 4; i++)
	{
		p nxt = pos[0] + make_pair(dy[i], dx[i]);
		q.push(make_pair(0, make_pair(pos[0], i)));
	}
	while (!q.empty())
	{
		p here = q.top().second.first;
		int idx = q.top().second.second;
		p dir = make_pair(dy[idx], dx[idx]);
		int door = -q.top().first;
		q.pop();
		if (here < 0 || here > n - 1 || room[here.first][here.second] == '*'
			|| visited[here.first][here.second][idx]) continue;
		visited[here.first][here.second][idx] = true;
		if (here == pos[1])
		{
			ans = min(ans, door);
			continue;
		}
		if (room[here.first][here.second] == '!')
		{
			p refl = getReflect(idx);
			p pos1 = here + make_pair(dy[refl.first], dx[refl.first]);
			p pos2 = here + make_pair(dy[refl.second], dx[refl.second]);
			q.push(make_pair(-(door + 1), make_pair(pos1, refl.first)));
			q.push(make_pair(-(door + 1), make_pair(pos2, refl.second)));
		}
		p nxt = here + dir;
		q.push(make_pair(-door, make_pair(nxt, idx)));
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/2151