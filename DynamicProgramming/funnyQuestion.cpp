#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll a, b, s;
vector<vector<ll>> dp(16, vector<ll>(136, 0));
vector<ll> A, B;

void t(ll n, vector<ll>& v)
{
	while (n != 0)
	{
		v.push_back(n % 10);
		n /= 10;
	}
}

ll order(vector<ll> v)
{
	ll r = s;
	ll ret = 0, orgnl = v.size();
	int lt = v.size();
	while (v.size() > 1)
	{
		ll b = v.back(), l = v.size();
		for (int i = 0; i < min(r, b); i++)
			for (int j = 0; j <= l - 2; j++)
				ret += dp[l - 2 - j][r - i];
		r -= b;
		if (r <= 0) break;
		v.pop_back();

	}

	if (!v.empty())
		ret += (v.back() >= r);

	return ret;
}

int main()
{
	for (int i = 1; i < 10; i++)
		dp[0][i] = 1;
	for (int i = 1; i < 15; i++)
		for (int j = 0; j < 135; j++)
			for (int k = 0; k <= ((j > 9) ? 9 : j); k++)
				dp[i][j] += dp[i - 1][j - k];

	cin >> a >> b >> s;
	a--;
	t(a, A); t(b, B);
	ll sa = order(A), sb = order(B);
	ll high = b, low = a, nxt = sa + 1;
	cout << sb - sa << '\n';
	for (int it = 0; it < 100; it++)
	{
		vector<ll> d;
		ll mid = (high + low) / 2;
		t(mid, d);
		ll sm = order(d);
		if (sm < nxt)
			low = mid;
		else
			high = mid;
	}
	cout << high << endl;
}

// https://www.acmicpc.net/problem/3001
/*
Very hard.
I first knew the way of dynamic programming like this.
I googled it and got the dynamic idea, implemented it myself.
In this sequence it takes 4 days.
It was a very impressive problem.
*/