#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
using pii = pair<int, int>;
const int INF = 1000000007;
int N, P, L, G, M, x;
string cmd;
set<pii> problemList[101];
unordered_map<int, pii> D;
pii getDifficult(int idx)
{
	return (*(--problemList[idx].end()));
}
pii getEasy(int idx)
{
	return (*problemList[idx].begin());
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> L >> G;
		problemList[G].insert({ L, P });
		D[P] = { G, L };
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			cin >> P >> L >> G;
			problemList[G].insert({ L, P });
			D[P] = { G, L };
		}
		else if (cmd == "recommend")
		{
			cin >> G >> x;
			if (x == 1) cout << getDifficult(G).second << '\n';
			else cout << getEasy(G).second << '\n';
		}
		else if (cmd == "recommend2")
		{
			cin >> x;
			if (x == 1)
			{
				int lv = -1, ans = INF;
				for (int i = 0; i <= 100; i++)
				{
					if (problemList[i].empty()) continue;
					pii p = getDifficult(i);
					if (lv < p.first || (lv == p.first && ans < p.second))
					{
						lv = p.first;
						ans = p.second;
					}
				}
				cout << ans << '\n';
			}
			else
			{
				int lv = INF, ans = -1;
				for (int i = 0; i <= 100; i++)
				{
					if (problemList[i].empty()) continue;
					pii p = getEasy(i);
					if (lv > p.first || (lv == p.first && ans > p.second))
					{
						lv = p.first;
						ans = p.second;
					}
				}
				cout << ans << '\n';
			}
		}
		else if (cmd == "recommend3")
		{
			cin >> x >> L;
			if (x == 1)
			{
				int lv = INF, ans = INF;
				for (int i = 0; i <= 100; i++)
				{
					if (problemList[i].empty()) continue;
					auto iter = problemList[i].lower_bound({ L, 0 });
					if (iter == problemList[i].end()) continue;
					pii p = (*iter);
					if (lv > p.first || (p.first == lv && ans > p.second))
					{
						lv = p.first;
						ans = p.second;
					}
				}
				if (ans == INF) ans = -1;
				cout << ans << '\n';
			}
			else
			{
				int lv = -1, ans = -1;
				for (int i = 0; i <= 100; i++)
				{
					if (problemList[i].empty()) continue;
					auto iter = problemList[i].lower_bound({ L, 0 });
					if (iter == problemList[i].begin()) continue;
					--iter;
					pii p = (*iter);
					if (p.first > lv || (p.first == lv && ans < p.second))
					{
						lv = p.first;
						ans = p.second;
					}
				}
				cout << ans << '\n';
			}
		}
		else if (cmd == "solved")
		{
			cin >> P;
			problemList[D[P].first].erase({ D[P].second, P });
		}
	}
}

// https://www.acmicpc.net/problem/21944