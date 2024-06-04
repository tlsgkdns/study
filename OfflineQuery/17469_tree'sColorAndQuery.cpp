#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> ans;
vector<pair<int, int>> query;
set<int> S[100001];
int P[100001], N, Q, C[100001], G[100001], X, A;

int find(int a)
{
	if (a == G[a]) return a;
	return G[a] = find(G[a]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 2; i <= N; i++) cin >> P[i];
	for (int i = 1; i <= N; i++)
	{
		cin >> C[i];
		G[i] = i;
		S[i].insert(C[i]);
	}
	for (int i = 0; i < N + Q - 1; i++)
	{
		cin >> X >> A;
		query.push_back({ X, A });
	}
	for (int i = query.size() - 1; i >= 0; i--)
	{
		int cmd = query[i].first;
		int num = query[i].second;
		if (cmd == 1)
		{
			int p = find(P[num]);
			num = find(num);
			if (S[num].size() > S[p].size()) swap(p, num);
			G[num] = p;
			for (auto it = S[num].begin(); it != S[num].end(); it++)
				S[p].insert(*it);
			S[num].clear();
		}
		else
			ans.push_back(S[find(num)].size());
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/17469