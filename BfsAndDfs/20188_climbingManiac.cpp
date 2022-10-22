#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 300001;
bool v[MAX];
vector<int> adj[MAX];
ll ans = 0, N, A, B, allCase = 0;
ll dfs(int here)
{
	ll ret = 1;
	for (int i = 0; i < (int)adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		ret += dfs(there);
	}
	ans += allCase - ((N - ret) * ((N - ret) - 1) / 2);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; allCase = N * (N - 1) / 2;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	v[1] = true;
	dfs(1);
	cout << ans - allCase << '\n';
}

// https://www.acmicpc.net/problem/20188