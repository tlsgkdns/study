#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;

const int INF = 1000000000;
int N, M, city, ans = INF;
vector<pair<int, int>> chicken, house;
bool dp[1 << 13];
int getDist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

int getStreet(vector<pair<int, int>>& c, bitset<13>& b)
{
	int ret = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int d = INF;
		for (int j = 0; j < c.size(); j++)
		{
			if (b.test(j)) continue;
			d = min(d, getDist(house[i].second, house[i].first, c[j].second, c[j].first));
		}
		ret += d;
	}

	return ret;
}

void solve(vector<pair<int, int>>& c, bitset<13>& b, int cnt)
{
	if (dp[b.to_ullong()]) return;
	dp[b.to_ullong()] = true;
	if (c.size() - cnt == M)
	{
		ans = min(ans, getStreet(c, b));
		return;
	}
	auto cp = c;
	for (int i = 0; i < c.size(); i++)
	{
		if (b.test(i)) continue;
		b.set(i);
		solve(c, b, cnt + 1);
		b.reset(i);
	}
}

int main()
{
	cin >> N >> M;
	int s = 0;
	bitset<13> b;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> city;
			if (city == 1)
				house.push_back(make_pair(i, j));
			if (city == 2)
				chicken.push_back(make_pair(i, j));
		}
	solve(chicken, b, 0);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/15686