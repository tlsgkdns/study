#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 123458;
vector<int> adj[MAX];
ll N, A, P, ans;
ll animal[MAX];
bool v[MAX];
char T;
ll dfs(int here)
{
	ll ret = 0, tmp;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		tmp = dfs(there) + animal[there];
		if (tmp < 0) continue;
		ret += tmp;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		cin >> T >> A >> P;
		adj[i].push_back(P);
		adj[P].push_back(i);
		if (T == 'W') A = -A;
		animal[i] = A;
	}
	v[1] = true;
	ans = dfs(1);
	if (ans < 0) ans = 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16437