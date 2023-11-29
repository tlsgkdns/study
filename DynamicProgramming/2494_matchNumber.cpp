#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> ans;
int N, dp[10002][11];
string s1, s2;

int solve(int idx, int r)
{
	int& ret = dp[idx][r];
	if (idx == N) return ret = 0;
	if (ret >= 0) return ret;
	int dst = s2[idx] - '0';
	ret = 1000000007;
	for (int i = 0; i < 10; i++)
	{
		int now = ((s1[idx] - '0' + r + i) % 10), plus = (now < dst) ? (10 - dst + now + i) : now - dst + i;
		ret = min(ret, solve(idx + 1, (r + i) % 10) + plus);
	}
	return ret;
}
void reconstruct(int idx, int r)
{
	if (idx == N) return;
	int dst = s2[idx] - '0';
	for (int i = 0; i < 10; i++)
	{
		int now = ((s1[idx] - '0' + r + i) % 10), plus = (now < dst) ? (10 - dst + now + i) : now - dst + i;
		if (dp[idx + 1][(r + i) % 10] + plus == dp[idx][r])
		{
			if (i > 0) ans.push_back({ idx + 1, i });
			if (now != dst) ans.push_back({ idx + 1, -((now < dst) ? (10 - dst + now) : now - dst) });
			reconstruct(idx + 1, (r + i) % 10);
			break;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cin >> s1;
	cin >> s2;
	cout << solve(0, 0) << '\n';
	reconstruct(0, 0);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << '\n';
}

// https://www.acmicpc.net/problem/2494