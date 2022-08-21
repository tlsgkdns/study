#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;
int tofu[15][15], dp[197][(1 << 14)];
const int price[5][5] = { {10, 8, 7, 5, 1} ,
						  {8, 6, 4, 3, 1},
						  {7, 4, 3, 2, 1},
						  {5, 3, 2, 2, 1},
						  {1, 1, 1, 1, 0} };
int N, M, P;
char C;

int solve(int idx, int fr)
{
	if (idx >= (N * M)) return 0;
	int& ret = dp[idx][fr];
	if (ret >= 0) return ret;
	ret = solve(idx + 1, (fr << 1) & ((1 << M) - 1));
	int y = idx / M, x = idx % M;
	if (!(fr & (1 << (M - 1))))
	{
		if (x < M - 1 && !(fr & (1 << (M - 2))))
			ret = max(ret, solve(idx + 2, (fr << 2) & ((1 << M) - 1)) + price[tofu[y][x]][tofu[y][x + 1]]);
		if (y < N - 1)
			ret = max(ret, solve(idx + 1, ((fr << 1) & ((1 << M)) - 1) + 1) + price[tofu[y][x]][tofu[y + 1][x]]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> C;
			switch (C)
			{
			case 'A':
				P = 0;
				break;
			case 'B':
				P = 1;
				break;
			case 'C':
				P = 2;
				break;
			case 'D':
				P = 3;
				break;
			default:
				P = 4;
			}
			tofu[i][j] = P;
		}
	cout << solve(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/1657