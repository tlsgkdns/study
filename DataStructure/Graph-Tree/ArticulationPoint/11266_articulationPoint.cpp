#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 10001;
vector<int> adj[MAX];
int discovered[MAX], cnt = 0, V, E, A, B;
bool arr[MAX];
vector<int> ans;
int dfs(int here, int root)
{
	discovered[here] = cnt++;
	int ret = discovered[here], childCount = 0;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (discovered[there] >= 0)
		{
			ret = min(ret, discovered[there]);
			continue;
		}
		childCount++;
		int nxt = dfs(there, false);
		if (!root && nxt >= discovered[here])
			arr[here] = true;
		ret = min(ret, nxt);
	}
	if (root) arr[here] = (childCount > 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(discovered, -1, sizeof(discovered));
	cin >> V >> E;
	while (E--)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for (int i = 1; i <= V; i++)
		if (discovered[i] < 0)
			dfs(i, true);
	for (int i = 1; i <= V; i++) if (arr[i]) ans.push_back(i);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/11266