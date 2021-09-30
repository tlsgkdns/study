#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
ll N, K, Q, x, y;
ll LCA(ll a, ll b)
{
	ll ret = 0;
	while (a != b)
	{
		if (a < b) swap(a, b);
		a = (a + (K - 2)) / K;
		ret++;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<ll> ans;
	cin >> N >> K >> Q;
	for (int q = 1; q <= Q; q++)
	{
		cin >> x >> y;
		if (x < y) swap(x, y);
		if (K == 1) ans.push_back(x - y);
		else ans.push_back(LCA(x, y));
	}
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/11812