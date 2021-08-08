#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using medal = pair<int, pair<int, int>>;
using country = pair<int, medal>;
int N, K, idx, g, s, b;
vector<country> oly;
map <medal, int> um;
bool cmp(country c1, country c2)
{
	if (c1.second.first != c2.second.first)
		return c1.second.first > c2.second.first;
	if (c1.second.second.first != c2.second.second.first)
		return c1.second.second.first > c2.second.second.first;
	return c1.second.second.second > c2.second.second.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> idx >> g >> s >> b;
		oly.push_back(make_pair(idx, make_pair(g, make_pair(s, b))));
	}
	sort(oly.begin(), oly.end(), cmp);
	int ans = 1;
	for (int i = 0; i < oly.size(); i++)
	{
		if (oly[i].first == K)
		{
			ans = i + 1;
			ans -= um[oly[i].second];
			break;
		}
		um[oly[i].second]++;
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/8979