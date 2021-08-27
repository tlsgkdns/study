#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int h, int w, int i, int j)
{
	return (i >= 0 && j >= 0 && i <= h + 1 && j <= w + 1);
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
	vector<int> ans;
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string key;
		int h, w, k = 0, a = 0;
		cin >> h >> w;
		vector<vector<char>> building(h + 2, vector<char>(w + 2, '.'));
		vector<vector<int>> v(h + 2, vector<int>(w + 2, -1));
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> building[i][j];
		cin >> key; if (key == "0") key = "";
		for (char c : key)	k = addKey(k, c);
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		v[0][0] = k;
		while (!q.empty())
		{
			int y = q.front().first;
			int x = q.front().second;
			int key = v[y][x];
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int ny = y + dy[d];
				int nx = x + dx[d];
				int nKey = key;
				if (!inRange(h, w, ny, nx) || building[ny][nx] == '*') continue;
				if (building[ny][nx] >= 'a' && building[ny][nx] <= 'z')
					nKey = addKey(nKey, building[ny][nx]);
				if (building[ny][nx] == '$')
				{
					building[ny][nx] = '.';
					a++;
				}
				if (building[ny][nx] >= 'A' && building[ny][nx] <= 'Z' &&
					(!hasKey(building[ny][nx], nKey)))
					continue;
				if ((v[ny][nx] >= 0) && ((nKey | v[ny][nx]) == v[ny][nx])) continue;
				if (v[ny][nx] < 0) v[ny][nx] = 0;
				v[ny][nx] |= nKey;
				q.push(make_pair(ny, nx));
			}
		}
		ans.push_back(a);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/9328