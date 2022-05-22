#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
using ll = long long;
ll A, B;
ll dp[101];
ll getCnt(ll num)
{
	if (num < 1) return 0;
	if (num == 1) return 1;
	ll up = 0;
	while ((ll)pow(2, up) < num) up++;
	if ((ll)pow(2, up) == num)
	{
		if (dp[up] >= 0) return dp[up];
		return dp[up] = getCnt(num - 1) + 1;
	}
	ll sub = num - (ll)pow(2, up - 1);
	return getCnt(sub) + sub + getCnt(num - sub);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> A >> B;
	ll ans = getCnt(B) - getCnt(A - 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/9527