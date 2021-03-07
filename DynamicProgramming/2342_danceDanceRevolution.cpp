#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<vector<int>>> dp;
vector<int> dance;
int d;
int getEnergy(int cur, int next)
{
	if (cur == 0) return 2;
	if (abs(next - cur) == 2) return 4;
	if (next == cur) return 1;
	return 3;
}
int step(int turn, int l, int r)
{
	if (turn == d - 1) return dp[turn][l][r] = 0;
	int& ret = dp[turn][l][r];
	if (ret != -1) return ret;
	ret = min(step(turn + 1, dance[turn + 1], r) + getEnergy(l, dance[turn + 1]),
		step(turn + 1, l, dance[turn + 1]) + getEnergy(r, dance[turn + 1]));
	return ret;
}

int main()
{
	int n = 0;
	dance.push_back(0);
	do
	{
		cin >> n;
		dance.push_back(n);
	} while (n != 0);
	dance.pop_back(); d = dance.size();
	dp.resize(d, vector<vector<int>>(5, vector<int>(5, -1)));
	cout << step(0, 0, 0) << '\n';
}

// https://www.acmicpc.net/problem/2342

/*
Little hard dynamic programming problem.
Little hard to came up with using three dimension.
*/