#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> ans;
int N, Q, p, q, r, ki, vi;
bool v[5001];

int query(int k, int vd)
{
	memset(v, false, sizeof(v));
	queue<int> q;
	q.push(vd);
	v[vd] = true;
	int ret = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++)
		{
			int nxt = adj[now][i].first;
			int usa = adj[now][i].second;
			if (v[nxt] || usa < k) continue;
			ret++;
			v[nxt] = true;
			q.push(nxt);
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	adj.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		cin >> p >> q >> r;
		adj[p].push_back({ q, r });
		adj[q].push_back({ p, r });
	}
	for (int i = 0; i < Q; i++)
	{
		cin >> ki >> vi;
		ans.push_back(query(ki, vi));
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/15591