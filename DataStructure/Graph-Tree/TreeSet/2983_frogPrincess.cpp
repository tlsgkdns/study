#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <set>
#include <tuple>
using namespace std;
const int MAX = 100001;
using pii = pair<int, int>;
using tp = tuple<int, int, int>;
vector<pii> arr1[MAX], arr2[MAX];
set<tp> set1, set2;
vector<pii> inputs;
int N, K, cnt1 = 0, cnt2 = 0, Y, X, sum, sub, subIdx, sumIdx, s1, s2;
vector<pii>::iterator id, id2;
string cmds; pii ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> cmds;
	for (int i = 0; i < N; i++)
	{
		cin >> Y >> X;
		if (i == 0) ans = { Y, X };
		set1.insert({ Y - X, Y, X });
		set2.insert({ Y + X, Y, X });
	}

	for (int i = 0; i < K; i++)
	{
		if (cmds[i] == 'A')
		{
			set<tp>::iterator it = set1.find({ ans.first - ans.second, ans.first, ans.second });
			if (it == prev(set1.end())) continue;
			tp nxt = *next(it);
			if (get<0>(nxt) != ans.first - ans.second) continue;
			set1.erase(it);
			set2.erase({ ans.first + ans.second , ans.first, ans.second });
			ans = make_pair(get<1>(nxt), get<2>(nxt));
		}
		else if (cmds[i] == 'B')
		{
			set<tp>::iterator it = set2.find({ ans.first + ans.second, ans.first, ans.second });
			if (it == prev(set2.end())) continue;
			tp nxt = *next(it);
			if (get<0>(nxt) != ans.first + ans.second) continue;
			set2.erase(it);
			set1.erase({ ans.first - ans.second , ans.first, ans.second });
			ans = make_pair(get<1>(nxt), get<2>(nxt));
		}
		else if (cmds[i] == 'C')
		{
			set<tp>::iterator it = set2.find({ ans.first + ans.second, ans.first, ans.second });
			if (it == set2.begin()) continue;
			tp nxt = *prev(it);
			if (get<0>(nxt) != ans.first + ans.second) continue;
			set2.erase(it);
			set1.erase({ ans.first - ans.second, ans.first, ans.second });
			ans = make_pair(get<1>(nxt), get<2>(nxt));
		}
		else
		{
			set<tp>::iterator it = set1.find({ ans.first - ans.second, ans.first, ans.second });
			if (it == set1.begin()) continue;
			tp nxt = *prev(it);
			if (get<0>(nxt) != ans.first - ans.second) continue;
			set1.erase(it);
			set2.erase({ ans.first + ans.second , ans.first, ans.second });
			ans = make_pair(get<1>(nxt), get<2>(nxt));
		}
	}
	cout << ans.first << " " << ans.second << '\n';
}

// https://www.acmicpc.net/problem/2983