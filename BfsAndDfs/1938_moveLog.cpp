#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int aroundy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int aroundx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int N, ans = 0;
vector<vector<char>> f;
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < N);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	f.resize(N, vector<char>(N));
	vector<pair<int, int>> stv, edv;
	pair<int, int> st = { 0, 0 }, ed = { 0, 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> f[i][j];
			if (f[i][j] == 'B') stv.push_back({ i, j });
			if (f[i][j] == 'E') edv.push_back({ i, j });
		}
	bool isStartHor = (stv[0].first == stv[1].first);
	bool isEndHor = (edv[0].first == edv[1].first);
	for (int i = 0; i < 3; i++)
	{
		st.first += stv[i].first;
		st.second += stv[i].second;
		ed.first += edv[i].first;
		ed.second += edv[i].second;
	}
	st.first /= 3; ed.first /= 3; st.second /= 3; ed.second /= 3;
	queue<pair<pair<int, int>, bool>> q;
	vector<vector<vector<int>>> v(N, vector<vector<int>>(N, vector<int>(2, -1)));
	q.push(make_pair(st, isStartHor));
	v[st.first][st.second][isStartHor] = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		bool isHor = q.front().second;
		q.pop();
		if (make_pair(y, x) == ed && isHor == isEndHor)
		{
			ans = v[y][x][isHor];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int any1 = (isHor) ? ny : ny + 1;
			int anx1 = (isHor) ? nx + 1 : nx;
			int any2 = (isHor) ? ny : ny - 1;
			int anx2 = (isHor) ? nx - 1 : nx;
			if (!inRange(ny, nx) || !inRange(any1, anx1) || !inRange(any2, anx2)
				|| v[ny][nx][isHor] != -1 || f[ny][nx] == '1' || f[any1][anx1] == '1' || f[any2][anx2] == '1') continue;
			v[ny][nx][isHor] = v[y][x][isHor] + 1;
			q.push(make_pair(make_pair(ny, nx), isHor));
		}
		bool canTurn = true;
		for (int i = 0; i < 8; i++)
		{
			int ny = y + aroundy[i];
			int nx = x + aroundx[i];
			if (!inRange(ny, nx) || f[ny][nx] == '1')
			{
				canTurn = false;
				break;
			}
		}
		if (!canTurn || v[y][x][!isHor] != -1) continue;
		v[y][x][!isHor] = v[y][x][isHor] + 1;
		q.push(make_pair(make_pair(y, x), !isHor));
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1938