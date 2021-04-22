#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main()
{
	ll a, b, ans = -1;
	cin >> a >> b;
	queue<pair<ll, ll>> q;
	q.push(make_pair(a, 1));
	while (!q.empty())
	{
		ll f = q.front().first;
		ll s = q.front().second;
		q.pop();
		if (f > b) continue;
		if (f == b) { ans = s; break; }
		q.push(make_pair(f * 10 + 1, s + 1));
		q.push(make_pair(f * 2, s + 1));
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16953