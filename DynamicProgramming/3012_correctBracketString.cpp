#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
using ll = long long;
const int MOD = 100000;
int N;
ll dp[202][202];
bool f[202][202];
string str;
vector<int> b1, b2, b3, b4;
ll solve(int l, int r)
{
	if (l >= r) return 1;
	if (str[l] == ')' || str[l] == ']' || str[l] == '}') return 0;
	ll& ret = dp[l][r];
	if (ret >= 0) return ret;
	ret = 0;
	if (str[l] == '(' || str[l] == '?')
	{
		for (int idx = upper_bound(b1.begin(), b1.end(), l) - b1.begin(); idx < b1.size() && b1[idx] < r; idx++)
			ret += solve(l + 1, b1[idx]) * solve(b1[idx] + 1, r);
		if (ret >= MOD) f[l][r] = true;
		ret %= MOD;
	}
	if (str[l] == '[' || str[l] == '?')
	{
		for (int idx = upper_bound(b2.begin(), b2.end(), l) - b2.begin(); idx < b2.size() && b2[idx] < r; idx++)
			ret += solve(l + 1, b2[idx]) * solve(b2[idx] + 1, r);
		if (ret >= MOD) f[l][r] = true;
		ret %= MOD;
	}
	if (str[l] == '{' || str[l] == '?')
	{
		for (int idx = upper_bound(b3.begin(), b3.end(), l) - b3.begin(); idx < b3.size() && b3[idx] < r; idx++)
			ret += solve(l + 1, b3[idx]) * solve(b3[idx] + 1, r);
		if (ret >= MOD) f[l][r] = true;
		ret %= MOD;
	}
	for (int idx = upper_bound(b4.begin(), b4.end(), l) - b4.begin(); idx < b4.size() && b4[idx] < r; idx++)
		ret += ((str[l] == '?') ? 3 : 1) * solve(l + 1, b4[idx]) * solve(b4[idx] + 1, r);
	if (ret >= MOD) f[l][r] = true;
	ret %= MOD;
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		switch (str[i])
		{
		case ')':
			b1.push_back(i);
			break;
		case ']':
			b2.push_back(i);
			break;
		case '}':
			b3.push_back(i);
			break;
		case '?':
			b4.push_back(i);
			break;
		}
	}
	if (N % 2) cout << 0 << '\n';
	else
	{
		ll ans = solve(0, N);
		if (f[0][N]) printf("%05lld\n", ans);
		else printf("%lld\n", ans);
	}
}

// https://www.acmicpc.net/problem/3012