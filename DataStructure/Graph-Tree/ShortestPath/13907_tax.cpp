#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
using P = pair<ll, int>;
using PP = pair<P, int>;
const int INF = 2000000000;
vector<vector<P>> tax;
vector<vector<int>> dist(1001, vector<int>(1001, INF));
vector<int> ans;
int n, m, k, s, d, sum = 0, inc;

void dikjstra()
{
	priority_queue<PP, vector<PP>, greater<PP>> pq;
	dist[s][0] = 0;
	pq.push(make_pair(make_pair(0, 0), s));
	while (!pq.empty())
	{
		PP t = pq.top();
		pq.pop();
		ll cost = t.first.first;
		int cnt = t.first.second;
		int here = t.second;
		if (cnt >= n) continue;
		if (dist[here][cnt] < cost) continue;
		for (int i = 0; i < tax[here].size(); i++)
		{
			int there = tax[here][i].first;
			ll nxt = tax[here][i].second + cost;

			if (dist[there][cnt + 1] > nxt)
			{
				dist[there][cnt + 1] = nxt;
				pq.push(make_pair(make_pair(nxt, cnt + 1), there));
			}
		}
	}
}
void calc()
{
	int ret = INF;
	for (int i = 0; i < n; i++)
	{
		int dc = dist[d][i] + i * sum;
		ret = min(dc, ret);
	}
	ans.push_back(ret);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> k;
	cin >> s >> d;
	tax.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tax[a].push_back(make_pair(b, c));
		tax[b].push_back(make_pair(a, c));
	}
	dikjstra();
	calc();
	for (int i = 0; i < k; i++)
	{
		cin >> inc;
		sum += inc;
		calc();
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/13907