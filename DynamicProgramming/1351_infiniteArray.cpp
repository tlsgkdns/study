#include <iostream>
#include <map>
using namespace std;
using ll = long long;
map<ll, ll> m;
ll N, P, Q;
ll solve(ll now)
{
	if (now == 0) return 1;
	if (m.count(now) > 0) return m[now];
	m[now] = solve(now / P) + solve(now / Q);
	return m[now];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P >> Q;
	cout << solve(N) << '\n';
}

// https://www.acmicpc.net/problem/1351