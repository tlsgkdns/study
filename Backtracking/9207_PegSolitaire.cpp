#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < 5 && x < 9);
}
int solitair(vector<vector<char>>& b, int cnt)
{
	if (cnt == 1) return 1;
	int ret = cnt;
	for (int y = 0; y < b.size(); y++)
		for (int x = 0; x < b[0].size(); x++)
		{
			if (b[y][x] != 'o') continue;
			for (int d = 0; d < 4; d++)
			{
				int ny1 = y + dy[d]; int nx1 = x + dx[d];
				int ny2 = ny1 + dy[d]; int nx2 = nx1 + dx[d];
				if (!inRange(ny1, nx1) || b[ny1][nx1] != 'o') continue;
				if (!inRange(ny2, nx2) || b[ny2][nx2] != '.') continue;
				b[ny2][nx2] = 'o'; b[ny1][nx1] = '.';  b[y][x] = '.';
				ret = min(ret, solitair(b, cnt - 1));
				b[ny2][nx2] = '.'; b[ny1][nx1] = 'o';  b[y][x] = 'o';
			}
		}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<vector<char>> board(5, vector<char>(9));
	vector<pair<int, int>> ans;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int cnt = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 9; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 'o') cnt++;
			}
		int a = solitair(board, cnt);
		ans.push_back({ a, cnt - a });
	}
	for (auto p : ans)
		cout << p.first << " " << p.second << '\n';
}

// https://www.acmicpc.net/problem/9207