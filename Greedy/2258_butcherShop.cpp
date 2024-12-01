#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ui = unsigned int;
using pii = pair<ui, ui>;
const ui MAX = 2147483648;
ui N, M, W, P, ans = MAX;
vector<pii> meats;
bool cmp(pii p1, pii p2)
{
	if (p1.first == p2.first) return p1.second > p2.second;
	return p1.first < p2.first;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> W >> P;
		meats.push_back({ P, W });
	}
	sort(meats.begin(), meats.end(), cmp);
	ui s1 = 0, s2 = 0, sidx = 0;
	for (int i = 0; i < meats.size(); i++)
	{
		ui cost = meats[i].first;
		ui weight = meats[i].second;
		if (i > 0 && meats[i - 1].first != cost)
		{
			s1 += s2;
			s2 = 0;
			sidx = i;
		}
		s2 += weight;
		if (s1 + s2 >= M)
			ans = min(ans, (i - sidx + 1) * cost);
		if (s1 + weight >= M)
			ans = min(ans, cost);
	}
	if (ans == MAX) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2258