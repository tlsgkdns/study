#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> adj[10001];
int N, M, K, far = 0, farNode = 0;
bool v[10001];
void dfs(int here, int cost)
{
	if (far < cost)
	{
		farNode = here;
		far = cost;
	}
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		int nxtCost = adj[here][i].second + cost;
		if (v[there]) continue;
		v[there] = true;
		dfs(there, nxtCost);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> M >> K;
		if (cin.eof()) break;
		adj[N].push_back({ M, K });
		adj[M].push_back({ N, K });
	}
	v[1] = true;
	dfs(1, 0);
	memset(v, false, sizeof(v));
	far = 0;
	dfs(farNode, 0);
	cout << far << '\n';
}

// https://www.acmicpc.net/problem/1595