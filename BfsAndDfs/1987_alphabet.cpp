#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string tmp;
int r, c;
vector<string> board;
vector<bool> v(26, false);
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(int y, int x, int depth)
{
	int ret = depth;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx == c || nx < 0 || ny == r || v[board[ny][nx] - 'A']) continue;
		v[board[ny][nx] - 'A'] = true;
		ret = max(ret, dfs(ny, nx, depth + 1));
		v[board[ny][nx] - 'A'] = false;
	}
	return ret;
}
int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> tmp;
		board.push_back(tmp);
	}
	v[board[0][0] - 'A'] = true;
	cout << dfs(0, 0, 1) << '\n';
}


//https://www.acmicpc.net/problem/1987

/*
dfs + backtracking problem.
*/