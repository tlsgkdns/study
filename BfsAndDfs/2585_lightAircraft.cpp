#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
using pii = pair<int, int>;

int v[1002];
int adj[1002][1002];
vector<pii> route;
int N, K, X, Y;

int getOil(pii src, pii dst)
{
	double f = src.first - dst.first;
	double s = src.second - dst.second;
	f *= f; s *= s; f += s;
	double d = sqrt(f); d /= 10;
	int ret = ceil(d);
	return ret;
}
bool bfs(int oil)
{
	memset(v, -1, sizeof(v));
	queue<int> q;
	q.push(0); v[0] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == N + 1) return true;
		if (v[here] > K) continue;
		for (int there = 0; there <= N + 1; there++)
		{
			if (v[there] != -1 || adj[here][there] >= oil) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	route.push_back({ 0, 0 });
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		route.push_back({ X, Y });
	}
	route.push_back({ 10000, 10000 });
	for (int i = 0; i <= N + 1; i++)
		for (int j = i + 1; j <= N + 1; j++)
		{
			adj[i][j] = getOil(route[i], route[j]);
			adj[j][i] = adj[i][j];
		}
	int l = 0, r = 15000;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (bfs(m)) r = m;
		else l = m;
	}
	cout << l << '\n';
}

// https://www.acmicpc.net/problem/2585