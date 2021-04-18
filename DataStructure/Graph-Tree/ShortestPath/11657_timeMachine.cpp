#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int INF = 1000000000;
vector<vector<pair<ll, ll>>> city;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	city.resize(n);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		city[a - 1].push_back({ b - 1, c });
	}
	vector<ll> upper(n, INF);
	upper[0] = 0;
	bool updated, cycle = false;
	for (int i = 0; i < n; i++)
	{
		updated = false;
		for (int here = 0; here < n; here++)
			for (int there = 0; there < city[here].size(); there++)
			{
				ll nxt = city[here][there].first;
				ll cost = city[here][there].second;
				if (upper[here] != INF && upper[nxt] > upper[here] + cost)
				{
					upper[nxt] = upper[here] + cost;
					updated = true;
					if (i == n - 1) cycle = true;
				}
			}
		if (!updated) break;
	}
	if (cycle) cout << "-1" << '\n';
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (upper[i] == INF) cout << "-1" << '\n';
			else cout << upper[i] << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/11657