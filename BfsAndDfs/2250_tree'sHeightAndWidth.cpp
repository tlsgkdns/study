#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[10001];
int l[10001], r[10001], N, L, R, C, lm = 0, num = 1, h = 0, root = 1;
int dp[10001];

void dfs(int here, int lv)
{
	if (here == -1) return;
	lm = max(lm, lv);
	dfs(adj[here][0], lv + 1);
	if (l[lv] == -1 || l[lv] > num) l[lv] = num;
	if (r[lv] == -1 || r[lv] < num) r[lv] = num;
	num++;
	dfs(adj[here][1], lv + 1);
}
int dfs2(int here)
{
	if (here == -1) return 0;
	int& ret = dp[here];
	if (ret >= 0) return ret;
	ret = dfs2(adj[here][0]) + dfs2(adj[here][1]) + 1;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(l, -1, sizeof(l)); memset(r, -1, sizeof(r));
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C >> L >> R;
		adj[C].push_back(L);
		adj[C].push_back(R);
	}
	for (int i = 1; i <= N; i++)
	{
		int a = dfs2(i);
		if (a > h)
		{
			h = a;
			root = i;
		}
	}
	dfs(root, 1);
	int ans = 0, aIdx = 1;
	for (int i = 1; i <= lm; i++)
		if (ans < r[i] - l[i] + 1)
		{
			ans = r[i] - l[i] + 1;
			aIdx = i;
		}
	cout << aIdx << " " << ans << '\n';
}

// https://www.acmicpc.net/problem/2250