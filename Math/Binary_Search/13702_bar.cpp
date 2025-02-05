#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
ll N, K, L[10001], l = 0, r = 1e18;
bool solve(ll now)
{
	ll ret = 0;
	for (int i = 0; i < N; i++)
		ret += (L[i] / now);
	return ret >= K;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> L[i];
	while (l + 1 < r)
	{
		ll m = (l + r) / 2;
		if (solve(m)) l = m;
		else r = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/13702