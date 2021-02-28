
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;
vector<ll> dp(4000000, numeric_limits<ll>::max());
vector<bool> v(4000000, false);
stack<ll> st1, st2;
ll m1, m2, a, b, k, ans = 0, bg;
ll s(ll n)
{
	ll r = 0;
	while (n != 0)
	{
		ll d = n % 10;
		r += pow(d, k);
		n /= 10;
	}
	return r;
}
ll rec(ll n)
{
	if (v[n])
	{
		bg = n;
		st2.push(n);
		if (dp[n] == numeric_limits<ll>::max()) return dp[n] = m1;
		else return dp[n];
	}
	v[n] = true;
	ll nxt = s(n);
	m1 = min(m1, n);
	ll x = rec(nxt);
	st2.push(n);
	m2 = min(m2, n);
	if (bg == n)
	{
		while (!st2.empty())
		{
			dp[st2.top()] = m2;
			st2.pop();
		}

		dp[n] = m2;
		return dp[n];
	}
	return dp[n] = min(x, m2);
}
int main()
{
	cin >> a >> b >> k;
	for (ll num = a; num <= b; num++)
	{
		m1 = numeric_limits<ll>::max();
		m2 = numeric_limits<ll>::max();
		bg = -1;
		st2 = st1;
		ans += rec(num);
	}

	cout << ans << endl;
	dp;
}

// https://www.acmicpc.net/problem/1131

/*
this is my first time that I solved myself more than gold 1(difficulty)
with no googling and no questioning page
*/