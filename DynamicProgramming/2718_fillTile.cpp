#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ans;
int T, N;
int dp[501][16];

int fillTile(int idx, int prev)
{
	if (idx < 0) return 0;
	if (idx == 0) return ((prev == 0) ? 1 : 0);
	int& ret = dp[idx][prev];
	if (ret != -1) return ret;
	switch (prev)
	{
	case 0:
		ret = fillTile(idx - 1, 3) + fillTile(idx - 1, 9) + fillTile(idx - 1, 12)
			+ fillTile(idx - 1, 0) + fillTile(idx - 2, 0);
		break;
	case 3:
		ret = fillTile(idx - 1, 12) + fillTile(idx - 1, 0);
		break;
	case 6:
		ret = fillTile(idx - 1, 9);
		break;
	case 9:
		ret = fillTile(idx - 1, 0) + fillTile(idx - 1, 6);
		break;
	case 12:
		ret = fillTile(idx - 1, 0) + fillTile(idx - 1, 3);
		break;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		ans.push_back(fillTile(N, 0));
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/2718