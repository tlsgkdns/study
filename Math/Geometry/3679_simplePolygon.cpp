#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using plli = pair<pll, int>;
int C;
int ccw(pll a, pll b, pll c)
{
	ll op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0) return 1;
	if (op < 0) return -1;
	return 0;
}
ll dist(pll a, pll b)
{
	return ((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C;
	while (C--)
	{
		int N; cin >> N;
		vector<plli> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i].first.first >> v[i].first.second;
			v[i].second = i;
		}
		swap(v[0], *min_element(v.begin(), v.end()));
		sort(v.begin() + 1, v.end(), [&](plli a, plli b) {
			if (ccw(v[0].first, a.first, b.first)) return ccw(v[0].first, a.first, b.first) > 0;
			return dist(v[0].first, a.first) < dist(v[0].first, b.first);
			});
		int idx = N - 1;
		while (!ccw(v[0].first, v[idx - 1].first, v[idx].first)) idx--;
		reverse(v.begin() + idx, v.end());
		for (int i = 0; i < N; i++) cout << v[i].second << ' ';
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/3679