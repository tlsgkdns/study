#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool ans = false;
int N;
char corr[7][7];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> teacher;
bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < N;
}
bool observe()
{
	for (int i = 0; i < teacher.size(); i++)
	{
		int sy = teacher[i].first;
		int sx = teacher[i].second;
		queue<pair<pair<int, int>, int>> q;
		for (int d = 0; d < 4; d++)
			q.push({ {sy, sx}, d });
		while (!q.empty())
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int dir = q.front().second;
			q.pop();
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (!inRange(ny, nx) || corr[ny][nx] == 'O') continue;
			if (corr[ny][nx] == 'S') return false;
			q.push({ {ny, nx}, dir });
		}
	}
	return true;
}

void solve(int d)
{
	if (ans) return;
	if (d == 3)
	{
		if (observe()) ans = true;
		return;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (corr[i][j] != 'X') continue;
			corr[i][j] = 'O';
			solve(d + 1);
			corr[i][j] = 'X';
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> corr[i][j];
			if (corr[i][j] == 'T')
				teacher.push_back({ i, j });
		}
	solve(0);
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/18428