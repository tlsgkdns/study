#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> tree;
vector<bool> visit;
int V, far, ans;
void dfs(int x, int cost)
{
	if (ans < cost)
	{
		ans = cost;
		far = x;
	}
	for (int i = 0; i < tree[x].size(); i++)
	{
		int next = tree[x][i].first;
		int leng = tree[x][i].second;
		if (visit[next]) continue;
		visit[next] = true;
		dfs(next, leng + cost);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V;
	tree.resize(V + 1); visit.resize(V + 1, false);
	for (int v = 0; v < V; v++)
	{
		int num;
		cin >> num;
		int n, l;
		while (true)
		{
			cin >> n;
			if (n < 0) break;
			cin >> l;
			tree[num].push_back({ n, l });
		}
	}
	visit[1] = true;
	dfs(1, 0);
	visit = vector<bool>(V + 1, false);
	visit[far] = true;
	dfs(far, 0);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1167
