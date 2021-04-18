#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

enum class Shape { HOR, VER, DIAG };
int n, dp[3][16][16];
vector<vector<int>> house;
int pipes(Shape s, int y, int x)
{
	if (x >= n || y >= n || house[y][x] == 1) return 0;
	int& ret = dp[(int)s][y][x];
	if (ret != -1) return ret;
	if (x == n - 1 && y == n - 1) return ret = 1;
	switch (s)
	{
	case Shape::HOR:
		ret = pipes(s, y, x + 1);
		break;
	case Shape::VER:
		ret = pipes(s, y + 1, x);
		break;
	default:
		ret = pipes(Shape::HOR, y, x + 1) + pipes(Shape::VER, y + 1, x);
	}
	if (x + 1 < n && y + 1 < n &&
		house[y + 1][x] == 0 && house[y][x + 1] == 0 && house[y + 1][x + 1] == 0)
		ret += pipes(Shape::DIAG, y + 1, x + 1);
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n; house.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> house[i][j];
	cout << pipes(Shape::HOR, 0, 1) << '\n';
}

// https://www.acmicpc.net/problem/17070