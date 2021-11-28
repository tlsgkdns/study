#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> card, dp;

int N;

int solve(int cnt)
{
	int& ret = dp[cnt];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 1; i <= cnt; i++)
		ret = max(ret, solve(cnt - i) + card[i]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	card.resize(N + 1); dp.resize(N + 1, -1);
	for (int i = 1; i <= N; i++)
		cin >> card[i];
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/11052