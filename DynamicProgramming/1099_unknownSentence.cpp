#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<string> str, ordered;
string S, W;
int N, cost[51][51], dp[51], ans = -1;

int solve(int idx)
{
	if (idx >= S.size()) return 0;
	int& ret = dp[idx];
	if (ret >= 0) return ret;
	ret = 1000000007;
	for (int i = 0; i < N; i++)
	{
		if (cost[i][idx] < 0) continue;
		ret = min(ret, solve(idx + str[i].size()) + cost[i][idx]);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(cost, -1, sizeof(cost));
	memset(dp, -1, sizeof(dp));
	cin >> S;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> W;
		str.push_back(W);
		sort(W.begin(), W.end());
		ordered.push_back(W);
	}
	for (int i = 0; i < N; i++)
	{
		for (int idx = 0; idx <= (int)S.size() - (int)str[i].size(); idx++)
		{
			string word(S.begin() + idx, S.begin() + str[i].size() + idx);
			string sortWord = word;
			sort(sortWord.begin(), sortWord.end());
			if (sortWord != ordered[i]) continue;
			int cnt = 0;
			for (int j = 0; j < str[i].size(); j++)
				cnt += (word[j] != str[i][j]);
			cost[i][idx] = cnt;
		}
	}
	ans = solve(0);
	if (ans == 1000000007) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1099