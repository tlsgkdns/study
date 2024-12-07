#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
int T;
ll A, B, N;
ll brute(set<ll>& f, int idx, ll cnt, ll m, ll l, ll a)
{
	if (l == cnt)
	{
		return a / m;
	}
	if (idx == f.size()) return 0;
	ll ret = 0;
	ret += brute(f, idx + 1, cnt, m, l, a);
	auto iter = f.begin(); advance(iter, idx);
	ret += brute(f, idx + 1, cnt + 1, m * (*iter), l, a);
	return ret;
}
ll solve(ll l, ll n)
{
	set<ll> s;
	for (ll i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			n /= i;
			s.insert(i);
		}
	}
	ll ret = 0;
	if (n > 1) s.insert(n);
	for (int i = 1; i <= s.size(); i++)
		ret += ((i % 2 > 0) ? 1 : -1) * brute(s, 0, 0, 1, i, l);
	return l - ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> A >> B >> N;
		ll ans = solve(B, N) - solve(A - 1, N);
		cout << "Case #" << t << ": " << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9359