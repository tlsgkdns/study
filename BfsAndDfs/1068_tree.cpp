#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[52];
int P[52], N, E, ans = 0;
int dfs(int here)
{
	if (adj[here].size() == 0 || (adj[here].size() == 1 && adj[here][0] == E)) return 1;
	int ret = 0;
	for (int i = 0; i < adj[here].size(); i++)
		if (adj[here][i] != E)
			ret += dfs(adj[here][i]);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
		if (P[i] >= 0) adj[P[i]].push_back(i);
	}
	cin >> E;
	for (int i = 0; i < N; i++)
		if (P[i] < 0 && i != E)
			ans += dfs(i);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1068