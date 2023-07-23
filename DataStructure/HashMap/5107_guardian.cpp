#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
using namespace std;

vector<int> adj[22];
int N, t = 0;
bool v[22];
void dfs(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (v[there]) continue;
		v[there] = true;
		dfs(there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		++t;
		for (int i = 0; i < N; i++) adj[i].clear();
		memset(v, false, sizeof(v));
		unordered_map<string, int> um;
		string s1, s2;
		int cnt = 0, ans = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> s1 >> s2;
			if (um.count(s1) == 0) um.insert({ s1, cnt++ });
			if (um.count(s2) == 0) um.insert({ s2, cnt++ });
			adj[um[s1]].push_back(um[s2]);
		}
		for (int i = 0; i < cnt; i++)
		{
			if (v[i]) continue;
			v[i] = true;
			dfs(i);
			++ans;
		}
		cout << t << " " << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/5107