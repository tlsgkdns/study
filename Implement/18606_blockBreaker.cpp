#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ans;
int N, M, Q, T, x, y;
bool blocks[2001][2001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool inRange(int y, int x)
{
	return y >= 1 && x >= 1 && y <= N && x <= M;
}
bool isUnStable(int y, int x)
{
	bool sideEmpty = false, upDownEmpty = false;
	if (y != 1) if (!blocks[y - 1][x]) upDownEmpty = true;
	if (y != N) if (!blocks[y + 1][x]) upDownEmpty = true;
	if (x != 1) if (!blocks[y][x - 1]) sideEmpty = true;
	if (x != M) if (!blocks[y][x + 1]) sideEmpty = true;
	return sideEmpty && upDownEmpty;
}

int knock(int y, int x)
{
	if (blocks[y][x] == false) return 0;
	int ret = 1;
	blocks[y][x] = false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!inRange(ny, nx) || !isUnStable(ny, nx) || blocks[ny][nx] == false) continue;
		ret += knock(ny, nx);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M >> Q;
		memset(blocks, true, sizeof(blocks));
		for (int q = 0; q < Q; q++)
		{
			cin >> y >> x;
			ans.push_back(knock(y, x));
		}
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/18606