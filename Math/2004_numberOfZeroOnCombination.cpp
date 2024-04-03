#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll N, M;
ll getCount(ll x, ll d)
{
	ll ret = 0;
	for (ll i = d; i <= x; i *= d) ret += (x / i);
	return ret;
}
ll solve(ll d)
{
	return getCount(N, d) - (getCount(M, d) + getCount(N - M, d));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cout << min(solve(2), solve(5)) << '\n';
}

// https://www.acmicpc.net/problem/2004