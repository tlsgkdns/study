#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Room
{
	char type;
	int money;
};
vector<vector<int>> adj;
char types[1001];
int costs[1001];
bool v[1001][501];
vector<bool> ans;
int N, mn, to;
char tp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		adj = vector<vector<int>>(N + 1);
		for (int n = 1; n <= N; n++)
		{
			cin >> tp >> mn;
			types[n] = tp;
			costs[n] = mn;
			while (true)
			{
				cin >> to;
				if (to == 0) break;
				adj[n].push_back(to);
			}
		}
		queue<pair<int, int>> q;
		memset(v, false, sizeof(v));
		if (types[1] != 'T')
		{
			q.push({ 1, costs[1] });
			v[1][costs[1]] = true;
		}
		bool a = false;
		while (!q.empty())
		{
			int num = q.front().first;
			int money = q.front().second;
			q.pop();
			if (num == N)
			{
				a = true;
				break;
			}
			for (int i = 0; i < adj[num].size(); i++)
			{
				int nxt = adj[num][i];
				int nMoney = money;
				if (types[nxt] == 'L') nMoney = max(nMoney, costs[nxt]);
				if (types[nxt] == 'T')
				{
					if (nMoney < costs[nxt]) continue;
					nMoney -= costs[nxt];
				}
				if (v[nxt][nMoney]) continue;
				if (nxt == N)
				{
					a = true;
					break;
				}
				v[nxt][nMoney] = true;
				q.push({ nxt, nMoney });
			}
			if (a) break;
		}
		ans.push_back(a);
	}
	for (bool as : ans)
		if (as) cout << "Yes\n";
		else cout << "No\n";
}

// https://www.acmicpc.net/problem/2310