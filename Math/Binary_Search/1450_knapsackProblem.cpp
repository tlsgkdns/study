#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
map<ll, ll > m;
vector<ll> thing;
ll n, c, limit, ans = 0;

void dfs(int pos, int limit, vector<ll>& v, ll s)
{
	if (pos > limit)
	{
		v.push_back(s);
	}
	else
	{
		dfs(pos + 1, limit, v, s);
		dfs(pos + 1, limit, v, s + thing[pos]);
	}
}

int main()
{
	vector<ll> g1, g2;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		ll t; cin >> t;
		thing.push_back(t);
	}
	limit = n / 2;
	dfs(0, limit, g1, 0);
	dfs(limit + 1, n - 1, g2, 0);
	sort(g1.begin(), g1.end()); sort(g2.begin(), g2.end());
	for (int i = 0; i < g1.size(); i++)
		ans += upper_bound(g2.begin(), g2.end(), c - g1[i]) - g2.begin();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1450

/*
Learned "Meet in the middle".
I used map at first But it failed.
So I googled and decided to use upper_bound(binary_search)
referred code : https://cocoon1787.tistory.com/358
*/