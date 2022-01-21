#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool farm[4007][4007];
int group[4007][4007];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int N, ans = 0, dir = 0,
heightMax = -1, heightMin = 4010, widthMax = -1, widthMin = 4010;
string path;

bool inRange(int y, int x)
{
	return y >= heightMin - 1 && y <= heightMax + 1 && x >= widthMin - 1 && x <= widthMax + 1;
}
void dfs(int y, int x)
{
	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!inRange(ny, nx) || group[ny][nx] != -1
			|| farm[ny][nx]) continue;
		group[ny][nx] = ans;
		dfs(ny, nx);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(group, -1, sizeof(group));
	cin >> N;
	cin >> path;
	pair<int, int> st = { 2003, 2003 };
	farm[2003][2003] = true;
	for (int i = 0; i < N; i++)
	{
		switch (path[i])
		{
		case 'N':
			dir = 0;
			break;
		case 'E':
			dir = 1;
			break;
		case 'S':
			dir = 2;
			break;
		default:
			dir = 3;
		}
		farm[st.first + dy[dir]][st.second + dx[dir]] = true;
		st = { st.first + 2 * dy[dir], st.second + 2 * dx[dir] };
		farm[st.first][st.second] = true;
		heightMax = max(st.first, heightMax);
		heightMin = min(st.first, heightMin);
		widthMax = max(st.second, widthMax);
		widthMin = min(st.second, widthMin);
	}
	for (int h = heightMin - 1; h <= heightMax + 1; h++)
		for (int w = widthMin - 1; w <= widthMax + 1; w++)
		{
			if (group[h][w] != -1 || farm[h][w]) continue;
			group[h][w] = ans;
			dfs(h, w);
			ans++;
		}
	if (ans != 0) ans--;
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/11975