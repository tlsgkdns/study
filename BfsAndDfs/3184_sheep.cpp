#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int R, C;
vector<vector<char>> garden;
vector<vector<bool>> v;
pair<int, int> bfs(int a, int b)
{
	int sheep = 0, wolf = 0;
	if (garden[a][b] == 'v') wolf++;
	if (garden[a][b] == 'o') sheep++;
	v[a][b] = true;
	queue<pair<int, int>> q;
	q.push({ a, b });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C
				|| v[ny][nx] || garden[ny][nx] == '#')
				continue;
			v[ny][nx] = true;
			if (garden[ny][nx] == 'v') wolf++;
			if (garden[ny][nx] == 'o') sheep++;
			q.push({ ny, nx });
		}
	}
	return make_pair(sheep, wolf);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	garden.resize(R, vector<char>(C));
	v.resize(R, vector<bool>(C, false));
	int s = 0, w = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> garden[i][j];
			if (garden[i][j] == 'v') w++;
			if (garden[i][j] == 'o') s++;
		}
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
		{
			if (garden[r][c] == '#' || v[r][c]) continue;
			auto p = bfs(r, c);
			if (p.first > p.second) w -= p.second;
			else s -= p.first;
		}
	cout << s << " " << w << '\n';
}
// https://www.acmicpc.net/problem/3184