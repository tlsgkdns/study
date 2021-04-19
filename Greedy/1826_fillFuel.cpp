#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> station;
priority_queue<long long> pq;
long long n, l, p, idx = 0, ans = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		station.push_back({ a, b });
	}

	cin >> l >> p;
	sort(station.begin(), station.end());
	while (p < l && idx != n)
	{
		for (; idx < n; idx++)
			if (p < station[idx].first) break;
			else pq.push(station[idx].second);
		if (pq.empty()) break;
		long long g = pq.top();
		pq.pop();
		p += g;
		ans++;
	}
	if (p < l) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1826