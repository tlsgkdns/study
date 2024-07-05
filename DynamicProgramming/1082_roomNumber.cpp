#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, P[10], dp[51][2];
string ans = "";
int solve(int money, bool f)
{
	int& ret = dp[money][f];
	if (ret >= 0) return ret;
	ret = 0;
	for (int i = f; i < N; i++)
		if (money >= P[i])
			ret = max(ret, solve(money - P[i], false) + 1);
	return ret;
}

void reconstruct(int money, bool f)
{
	for (int i = N - 1; i >= f; i--)
		if (money >= P[i] && dp[money][f] == dp[money - P[i]][0] + 1)
		{
			ans.push_back(i + '0');
			reconstruct(money - P[i], false);
			break;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];
	cin >> M;
	solve(M, true);
	reconstruct(M, true);
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	if (ans.empty()) ans = "0";
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1082