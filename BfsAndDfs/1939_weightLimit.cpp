#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using pii = pair<int, int>;
const int MAX = 10001;
vector<pii> adj[MAX];
int N, M, src, dst, C, A, B, l = 0, r = 0;
bool canReach(int weight)
{
	queue<int> q;
	vector<bool> v(N + 1, false);
	v[src] = true;
	q.push(src);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == dst) return true;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			if (v[there] || cost < weight) continue;
			v[there] = true;
			q.push(there);
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
		r = max(C + 1, r);
	}
	cin >> src >> dst;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (canReach(m)) l = m;
		else r = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/1939