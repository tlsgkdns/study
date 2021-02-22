#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max();
ll n, m, k, u, v, c, iv, a1 = -1, a2 = -1;
vector<list<pair<ll, ll>>> con;
vector<ll> d;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
int main()
{
	cin >> n >> m >> k;
	d = vector<ll>(n + 1, INF);
	con = vector<list<pair<ll, ll>>>(n + 1);
	for (ll i = 0; i < m; i++)
	{
		cin >> u >> v >> c;
		con[v].push_back(make_pair(u, c));

	}
	for (ll i = 0; i < k; i++)
	{
		cin >> iv;
		con[0].push_back(make_pair(iv, 0));
	}

	d[0] = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty())
	{
		ll c = pq.top().first;
		ll h = pq.top().second;
		pq.pop();
		if (d[h] < c) continue;

		for (auto t : con[h])
		{
			if (d[t.first] > t.second + c)
			{
				d[t.first] = t.second + c;
				pq.push(make_pair(d[t.first], t.first));
			}
		}
	}
	for (ll i = 1; i < d.size(); i++)
	{
		if (d[i] == INF) continue;
		if (a1 < d[i])
		{
			a1 = d[i];
			a2 = i;
		}
	}
	cout << a2 << '\n' << a1 << '\n';
}

// https://www.acmicpc.net/problem/17835

/*
Generate one node that connected all end point with no cost.
=> read in the book
Reverse the path.
=>I thought myself.
and dijkstra.
*/