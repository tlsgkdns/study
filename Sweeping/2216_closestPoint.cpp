#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
using P = pair<int, int>;
const int INF = 800000000;
vector<P> p;
int dist(P p1, P p2)
{
	return pow(p1.first - p2.first, 2) + pow(p2.second - p1.second, 2);
}
bool cmp(P p1, P p2)
{
	return p1.first < p2.first;
}

struct cmpY
{
	bool operator() (const P l, const P r) const
	{
		if (l.second == r.second)
			return l.first < r.first;
		else
			return l.second < r.second;
	}
};
int main()
{
	int n;
	cin >> n; p.resize(n);
	for (int i = 0; i < n; i++)
	{
		int f, s;
		cin >> f >> s;
		p[i].first = f; p[i].second = s;
	}
	sort(p.begin(), p.end(), cmp);
	int ans = dist(p[0], p[1]);
	int start = 0;
	set<P, cmpY> arr = { p[0], p[1] };
	for (int i = 2; i < n; i++)
	{
		P now = p[i];
		while (start < i)
		{
			int x = now.first - p[start].first;
			if (x * x > ans)
			{
				arr.erase(p[start]);
				start += 1;
			}
			else
				break;
		}
		int d = (int)sqrt((double)ans) + 1;
		P lp = { -100000, now.second - d }; P up = { 100000, now.second + d };
		auto low = arr.lower_bound(lp);
		auto high = arr.upper_bound(up);
		for (auto it = low; it != high; it++)
		{
			int d = dist(now, *it);
			if (d < ans) ans = d;
		}
		arr.insert(now);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2261