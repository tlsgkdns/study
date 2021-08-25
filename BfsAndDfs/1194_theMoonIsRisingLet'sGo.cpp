#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int N, M;
bool inRange(int i, int j)
{
	return (i >= 0 && j >= 0 && i < N && j < M);
}
int addKey(int base, char c)
{
	base |= ((1u) << (c - 'a'));
	return base;
}
bool hasKey(char door, int key)
{
	return ((key & ((1u) << (door - 'A'))) != 0);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	vector<vector<char>> mz(N, vector<char>(M));
	vector<vector<vector<int>>> v(N, vector<vector<int>>(M, (vector<int>(128, -1))));
	pair<int, int> st;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> mz[i][j];
			if (mz[i][j] == '0') st = make_pair(i, j);
		}
	queue<pair<pair<int, int>, int>> q;
	q.push({ st, {0} });
	v[st.first][st.second][0] = 0;
	int ans = -1;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int k = q.front().second;
		q.pop();
		if (mz[y][x] == '1')
		{
			ans = v[y][x][k];
			break;
		}
		for (int d = 0; d < 4; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			int nk = k;
			if (!inRange(ny, nx) || mz[ny][nx] == '#') continue;
			if (mz[ny][nx] >= 'a' && mz[ny][nx] <= 'f')
				nk = addKey(k, mz[ny][nx]);
			if (mz[ny][nx] >= 'A' && mz[ny][nx] <= 'F' && !hasKey(mz[ny][nx], nk))
				continue;
			if (v[ny][nx][nk] != -1) continue;
			v[ny][nx][nk] = v[y][x][k] + 1;
			q.push({ {ny, nx}, nk });
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1194