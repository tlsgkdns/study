#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int M = 1000001;
int N;
vector<vector<char>> town;
vector<vector<int>> altitude;
vector<int> vals;
vector<vector<bool>> dst;
pair<int, int> start;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { 0, -1, 1, 1, -1, 0, -1, 1 };
int K = 0;
bool inRange(int y, int x)
{
	return (y >= 0 && x >= 0 && y < N && x < N);
}
bool bfs(int left, int right)
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	vector<vector<bool>> v(N, vector<bool>(N, false));
	if (altitude[start.first][start.second] < left || altitude[start.first][start.second] > right) return false;
	q.push(make_pair(start, make_pair(altitude[start.first][start.second], altitude[start.first][start.second])));
	v[start.first][start.second] = true;
	int cnt = 0;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int mx = q.front().second.first;
		int mn = q.front().second.second;
		q.pop();
		if (mx > right || mn < left) continue;
		if (dst[y][x]) cnt++;
		for (int d = 0; d < 8; d++)
		{
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (!inRange(ny, nx) || v[ny][nx]) continue;
			int nmx = max(mx, altitude[ny][nx]);
			int nmn = min(mn, altitude[ny][nx]);
			v[ny][nx] = true;
			q.push(make_pair(make_pair(ny, nx), make_pair(nmx, nmn)));
		}
	}
	return (K == cnt);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	town.resize(N, vector<char>(N));
	altitude.resize(N, vector<int>(N));
	dst.resize(N, vector<bool>(N, false));
	char t;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> t;
			if (t == 'P') start = make_pair(i, j);
			if (t == 'K')
			{
				dst[i][j] = true;
				K++;
			}
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> altitude[i][j];
			vals.push_back(altitude[i][j]);
		}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	int left = 0, right = 0, ans = 1000001;
	while (right < vals.size())
	{
		while (true)
		{
			if (left > right || !bfs(vals[left], vals[right])) break;
			ans = min(ans, (vals[right] - vals[left]));
			left++;
		}
		right++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2842