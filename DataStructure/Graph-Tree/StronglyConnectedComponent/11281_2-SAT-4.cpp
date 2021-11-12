#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> id, v, arr;
vector<pair<int, int>> sccOrder;
int N, M, vCnt = 0, sCnt = 0;
stack<int> s;

int dfs(int here)
{
	int ret = v[here] = vCnt++;
	s.push(here);
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there] == -1)
			ret = min(ret, dfs(there));
		else if (id[there] == -1)
			ret = min(ret, v[there]);
	}
	if (ret == v[here])
	{
		while (true)
		{
			int t = s.top();
			s.pop();
			id[t] = sCnt;
			if (t == here) break;
		}
		++sCnt;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int l, r, revL, revR;
	arr.resize(N + 1, -1);	v.resize(2 * N + 1, -1);
	adj.resize(2 * N + 1); id.resize(2 * N + 1, -1);
	for (int i = 0; i < M; i++)
	{
		cin >> l >> r;
		if (l < 0)
		{
			l = N - l;
			revL = l - N;
		}
		else
			revL = l + N;
		if (r < 0)
		{
			r = N - r;
			revR = r - N;
		}
		else
			revR = r + N;
		adj[revL].push_back(r);
		adj[revR].push_back(l);
	}
	for (int i = 1; i <= 2 * N; i++)
		if (v[i] == -1)
			dfs(i);
	int ans = 1;
	for (int i = 1; i <= N; i++)
		if (id[i] == id[i + N])
			ans = 0;
	cout << ans << '\n';
	if (ans == 1)
	{
		for (int i = 1; i <= N * 2; i++)
			sccOrder.push_back({ -id[i], i });
		sort(sccOrder.begin(), sccOrder.end());
		for (int i = 0; i < sccOrder.size(); i++)
		{
			int cur = sccOrder[i].second, val = 0;
			if (cur > N)
			{
				cur -= N;
				val = 1;
			}
			if (arr[cur] != -1) continue;
			arr[cur] = val;
		}
		for (int i = 1; i <= N; i++)
			cout << arr[i] << " ";
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/11281