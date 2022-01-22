#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> wood;
vector<vector<bool>> v;
int boom[4][2][2] = {  {{1, 0}, {2, 1}},
					  {{2, 1}, {1, 0}},
					  {{0, 1}, {1, 2}},
					  {{1, 2}, {0, 1}} };
bool canCut(int y, int x, int idx)
{
	for (int r = 0; r < 2; r++)
		for (int c = 0; c < 2; c++)
			if (v[y + r][x + c] && boom[idx][r][c] != 0)
				return false;
	return true;
}
int solve(int y, int x)
{
	if (y == N - 1) return 0;
	if (x == M - 1) return solve(y + 1, 0);
	int ret = 0;
	for (int idx = 0; idx < 4; idx++)
	{
		if (!canCut(y, x, idx)) continue;
		int cost = 0;
		for (int r = 0; r < 2; r++)
			for (int c = 0; c < 2; c++)
			{
				if (boom[idx][r][c] == 0) continue;
				v[y + r][x + c] = true;
				cost += wood[y + r][x + c] * boom[idx][r][c];
			}
		ret = max(solve(y, x + 1) + cost, ret);
		for (int r = 0; r < 2; r++)
			for (int c = 0; c < 2; c++)
			{
				if (boom[idx][r][c] == 0) continue;
				v[y + r][x + c] = false;
			}
	}
	ret = max(solve(y, x + 1), ret);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	wood.resize(N, vector<int>(M));
	v.resize(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> wood[i][j];
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/18430