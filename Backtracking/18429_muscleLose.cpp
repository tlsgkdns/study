#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<bool> used;
vector<int> kit;
int solve(int muscle, int d)
{
	if (d == n) return 1;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		int next = muscle + kit[i] - k;
		if (used[i] || next < 500) continue;
		used[i] = true;
		ret += solve(next, d + 1);
		used[i] = false;
	}
	return ret;
}
int main()
{
	cin >> n >> k;
	used.resize(n, false);
	kit.resize(n);
	for (int i = 0; i < n; i++)
		cin >> kit[i];
	cout << solve(500, 0) << '\n';
}

// https://www.acmicpc.net/problem/18429

/*
backtracking problem.
*/