#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[10001], D[10001];
int N, K, A, B, cnt[10001], d = 1, P[10001], ch[10001];
bool v[10001], E[10001];
int dfs(int here, int depth)
{
	d = max(d, depth);
	int& ret = cnt[here];
	ret = 1;
	D[depth].push_back(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (cnt[there] >= 0) continue;
		P[there] = here;
		ret += dfs(there, depth + 1);
	}
	ch[here] = ret;
	return ret;
}
bool cmp(int a, int b)
{
	return ch[a] < ch[b];
}
int dfs2(int here)
{
	int ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (E[there]) continue;
		E[there] = true;
		ret += dfs2(there) + 1;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(cnt, -1, sizeof(cnt));
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	dfs(1, 0);
	for (int i = d; i >= 1; i--)
	{
		if (D[i].size() <= K) continue;
		sort(D[i].begin(), D[i].end(), cmp);
		for (int idx = 0; idx < D[i].size() - K; idx++)
		{
			E[D[i][idx]] = true;
			ch[P[D[i][idx]]] -= cnt[D[i][idx]];
		}
	}
	E[1] = true;
	cout << dfs2(1) + 1 << '\n';
}

// https://www.acmicpc.net/problem/23844