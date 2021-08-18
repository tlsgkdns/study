#include <iostream>
#include <vector>
using namespace std;

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
int N, M, k, n, d, cnt;
struct Shark
{
	int num;
	int dir;
	Shark()
	{
		num = 0;
		dir = 0;
	}
	Shark(int nm, int dr)
	{
		num = nm;
		dir = dr;
	}
};
vector<vector<Shark>> grid;
vector<vector<vector<int>>> prior;
vector<vector<pair<int, int>>> smell;

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < N);
}
int getNextDir(int y, int x)
{
	int number = grid[y][x].num;
	int direction = grid[y][x].dir;
	for (int i = 0; i <= 3; i++)
	{
		int nextDir = prior[number][direction][i];
		int ny = y + dy[nextDir];
		int nx = x + dx[nextDir];
		if (!inRange(ny, nx) || smell[ny][nx].first != 0) continue;
		return nextDir;
	}
	for (int i = 0; i <= 3; i++)
	{
		int nextDir = prior[number][direction][i];
		int ny = y + dy[nextDir];
		int nx = x + dx[nextDir];
		if (!inRange(ny, nx) || smell[ny][nx].first != number) continue;
		return nextDir;
	}
	return 0;
}
void reduceSmell(vector<vector<Shark>>& t)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (smell[i][j].first <= 0 || t[i][j].num != 0) continue;
			--smell[i][j].second;
			if (smell[i][j].second == 0)  smell[i][j].first = 0;
		}
}
void moveShark()
{
	vector<vector<Shark>> tmp(N, vector<Shark>(N, Shark(0, 0)));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j].num == 0) continue;
			int next = getNextDir(i, j);
			int ny = i + dy[next];
			int nx = j + dx[next];
			if (tmp[ny][nx].num == 0 || tmp[ny][nx].num > grid[i][j].num)
			{
				if (tmp[ny][nx].num != 0) cnt--;
				tmp[ny][nx].num = grid[i][j].num;
				tmp[ny][nx].dir = next;
			}
			else
				cnt--;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (tmp[i][j].num == 0) continue;
			smell[i][j].first = tmp[i][j].num;
			smell[i][j].second = k;
		}
	reduceSmell(tmp);
	grid = tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> k; cnt = M;
	grid.resize(N, vector<Shark>(N));
	prior.resize(M + 1, vector<vector<int>>(5, vector<int>(4)));
	smell.resize(N, vector<pair<int, int>>(N, make_pair(0, 0)));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> n;
			Shark sh(n, 0);
			grid[i][j] = sh;
			if (n != 0) smell[i][j] = make_pair(n, k);
		}
	for (int i = 1; i <= M; i++)
	{
		cin >> d;
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
				if (grid[r][c].num == i)
				{
					grid[r][c].dir = d;
					break;
				}
	}
	for (int a = 1; a <= M; a++)
		for (int b = 1; b <= 4; b++)
			for (int c = 0; c < 4; c++)
				cin >> prior[a][b][c];
	int ans = 0;
	while (cnt != 1 && ans <= 1000)
	{
		ans++;
		grid; smell; cnt;
		moveShark();
	}
	ans = (ans > 1000) ? -1 : ans;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/19237