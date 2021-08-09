#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int T, h, w;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int cnt = 0, a = 100001;
		cin >> h >> w;
		vector<vector<char>> prison(h + 2, vector<char>(w + 2, '.'));
		vector<vector<vector<int>>> visited(h + 2, vector<vector<int>>(w + 2, vector<int>(3, -1)));
		deque<pair<pair<int, int>, int>> dq;
		dq.push_back(make_pair(make_pair(0, 0), cnt++));
		visited[0][0][0] = 0;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				cin >> prison[i][j];
				if (prison[i][j] == '$')
				{
					visited[i][j][cnt] = 0;
					dq.push_back(make_pair(make_pair(i, j), cnt++));
				}
			}
		prison;
		while (!dq.empty())
		{
			int y = dq.front().first.first;
			int x = dq.front().first.second;
			int n = dq.front().second;
			dq.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int ny = dy[i] + y;
				int nx = dx[i] + x;
				if (ny < 0 || nx < 0 || ny > h + 1 || nx > w + 1
					|| prison[ny][nx] == '*' || visited[ny][nx][n] != -1) continue;
				if (prison[ny][nx] == '#')
				{
					visited[ny][nx][n] = visited[y][x][n] + 1;
					dq.push_back(make_pair(make_pair(ny, nx), n));
				}
				else
				{
					visited[ny][nx][n] = visited[y][x][n];
					dq.push_front(make_pair(make_pair(ny, nx), n));
				}
			}
		}
		for (int i = 0; i < h + 2; i++)
			for (int j = 0; j < w + 2; j++)
			{
				if (visited[i][j][0] == -1) continue;
				int k = visited[i][j][0] + visited[i][j][1] + visited[i][j][2];
				if (prison[i][j] == '#') k -= 2;
				a = min(a, k);
			}
		ans.push_back(a);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/9376