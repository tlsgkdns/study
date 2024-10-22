#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, pair<int, int>>;

int N, M, D, S, E;

bool cmp(pii p1, pii p2)
{
	if (p1.first == p2.first) return p1.second.second < p2.second.second;
	return p1.first < p2.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int t = 1; t <= N; t++)
	{
		cin >> M;
		vector<pii> G;
		for (int i = 0; i < M; i++)
		{
			cin >> D >> S >> E;
			G.push_back({ D, {S, E} });
		}
		sort(G.begin(), G.end(), cmp);
		int now = -1, r = 0, ans = 0;
		for (int i = 0; i < G.size(); i++)
		{
			if (G[i].first != now)
			{
				r = G[i].second.second;
				now = G[i].first;
				++ans;
			}
			else
			{
				if (r > G[i].second.first) continue;
				r = G[i].second.second;
				++ans;
			}
		}
		cout << "Scenario #" << t << ":\n";
		cout << ans << "\n\n";
	}
}

// https://www.acmicpc.net/problem/7507