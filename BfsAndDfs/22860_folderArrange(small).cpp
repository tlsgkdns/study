#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

vector<pair<int, bool>> adj[2003];
unordered_map<string, int> dic;
unordered_map<int, int> ans;
int N, M, Q, cnt = 0;
string P, F, D;
bool C;
void dfs(int here)
{
	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i].first;
		bool f = adj[here][i].second;
		if (!f)
			++(ans[there]);
		else
			dfs(there);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		cin >> P >> F >> C;
		if (dic.count(P) == 0) dic.insert({ P, cnt++ });
		if (dic.count(F) == 0) dic.insert({ F, cnt++ });
		adj[dic[P]].push_back({ dic[F], C });
	}
	cin >> Q;
	while (Q--)
	{
		cin >> D;
		stringstream ss(D);
		string tmp;
		while (getline(ss, tmp, '/'));
		ans.clear();
		dfs(dic[tmp]);
		int s = 0, c = 0;
		for (pair<int, int> a : ans)
		{
			++c;
			s += a.second;
		}
		cout << c << " " << s << '\n';
	}
}

// https://www.acmicpc.net/problem/22860