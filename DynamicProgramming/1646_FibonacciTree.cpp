#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
ll N, S, D, lv;
bool swapped = false;
ll dp[51], lca = 1;
string ans = "";
ll getRightNumber(ll l, ll num)
{
	return dp[l - 2] + 1 + num;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> S >> D; lv = N;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2] + 1;
	if (S > D)
	{
		swapped = true;
		swap(S, D);
	}
	while (lv >= 2 && lca != S)
	{
		ll R = getRightNumber(lv, lca);
		if (R <= S)
		{
			--lv;
			lca = R;
		}
		else if (R > D)
		{
			lv = lv - 2;
			lca = lca + 1;
		}
		else
			break;
	}
	ll here = lca, L = lv;
	if (swapped) swap(S, D);
	while (here != S)
	{
		ll r = getRightNumber(L, here);
		ans.push_back('U');
		if (r > S)
		{
			L = L - 2;
			here = here + 1;
		}
		else
		{
			--L;
			here = r;
		}
	}
	here = lca; L = lv;
	while (here != D)
	{
		ll r = getRightNumber(L, here);
		if (r > D)
		{
			ans.push_back('L');
			L = L - 2;
			here = here + 1;
		}
		else
		{
			ans.push_back('R');
			--L;
			here = r;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1646