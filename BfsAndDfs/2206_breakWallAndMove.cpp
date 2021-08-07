#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
char c;
vector<vector<bool>> arr;
vector<vector<vector<int>>> v;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	arr.resize(N, vector<bool>(M));
	v.resize(N, vector<vector<int>>(M, vector<int>(2, -1)));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}

	queue<pair<pair<int, int>, bool>> q;
	q.push(make_pair(make_pair(0, 0), false));
	v[0][0][0] = 1;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		bool br = q.front().second;
		q.pop();
		if (y == N - 1 && x == M - 1) break;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx])
			{
				if (!br && v[ny][nx][true] == -1)
				{
					v[ny][nx][true] = v[y][x][br] + 1;
					q.push(make_pair(make_pair(ny, nx), true));
				}
				else continue;
			}
			else
			{
				if (v[ny][nx][br] != -1) continue;
				v[ny][nx][br] = v[y][x][br] + 1;
				q.push(make_pair(make_pair(ny, nx), br));
			}
		}
	}
	int ans = max(v[N - 1][M - 1][true], v[N - 1][M - 1][false]);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/2206