#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;

vector<vector<char>> arr;
vector<vector<int>> group, ans;
vector<vector<bool>> v;
vector<int> areas;
queue<pair<int, int>> st;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool inRange(int y, int x)
{
	return y >= 0 && x >= 0 && y < N && x < M;
}
int dfs(int y, int x)
{
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || v[ny][nx] || arr[ny][nx] == '1') continue;
		st.push({ ny, nx });
		v[ny][nx] = true;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	arr.resize(N, vector<char>(M)); group.resize(N, vector<int>(M, -1));
	ans.resize(N, vector<int>(M, 0));  v.resize(N, vector<bool>(M, false));
	areas.resize(N * M, -1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	int gNum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '1' || v[i][j]) continue;
			v[i][j] = true;
			st.push({ i, j });
			int area = dfs(i, j);
			areas[gNum] = area;
			while (!st.empty())
			{
				group[st.front().first][st.front().second] = gNum;
				st.pop();
			}
			gNum++;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '0') continue;
			vector<int> used;
			for (int d = 0; d < 4; d++)
			{
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (!inRange(ny, nx) || find(used.begin(), used.end(), group[ny][nx]) != used.end()
					|| group[ny][nx] < 0) continue;
				used.push_back(group[ny][nx]);
				ans[i][j] += areas[group[ny][nx]];
			}
			ans[i][j]++;
			ans[i][j] %= 10;
		}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << ans[i][j];
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/16946