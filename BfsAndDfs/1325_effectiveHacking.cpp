#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 10001;
vector<int> adj[MAX], ans;
bool v[MAX];
int N, M, A, B, mx = 0;
int dfs(int here)
{
	int ret = 1;
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		ret += dfs(there);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[B].push_back(A);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(v, false, sizeof(v));
		v[i] = true;
		int r = dfs(i);
		if (r > mx)
		{
			ans = vector<int>();
			ans.push_back(i);
			mx = r;
		}
		else if (r == mx)
			ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}

// https://www.acmicpc.net/problem/1325