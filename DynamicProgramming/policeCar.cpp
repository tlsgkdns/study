#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> dp;
vector<pair<int, int>> works;
vector<int> ord;
int n, w, ans;
bool f = false;
int getDist(int sx, int sy, int ex, int ey)
{
	return abs(sx - ex) + abs(sy - ey);
}
int police(int p1, int p2)
{
	if (p1 == w + 1 || p2 == w + 1) return dp[p1][p2] = 0;
	int& ret = dp[p1][p2];
	if (ret != -1) return ret;
	int nxt = max(p1, p2) + 1;
	auto c1 = works[p1]; auto nc = works[nxt];
	auto c2 = works[p2];

	int s1 = police(nxt, p2) + getDist(c1.first, c1.second, nc.first, nc.second);
	int s2 = police(p1, nxt) + getDist(c2.first, c2.second, nc.first, nc.second);
	ret = min(s1, s2);
	return ret;
}
void reconstruct2()
{
	int a = 0, b = 1;
	int nxt = 2;
	while (nxt < w + 1)
	{
		nxt = max(a, b) + 1;
		if (dp[nxt][b] + getDist(works[a].first, works[a].second, works[nxt].first, works[nxt].second)
			>= dp[a][nxt] + getDist(works[b].first, works[b].second, works[nxt].first, works[nxt].second))
		{
			b = nxt;
			cout << 2 << '\n';
		}
		else
		{
			a = nxt;
			cout << 1 << '\n';
		}
	}
}
int main()
{
	cin >> n >> w;
	dp.resize(w + 2, vector<int>(w + 2, -1));
	works.resize(w + 2);
	works[0] = make_pair(1, 1);
	works[1] = make_pair(n, n);
	for (int i = 2; i < w + 2; i++)
		cin >> works[i].first >> works[i].second;

	ans = police(0, 1);
	cout << ans << '\n';
	reconstruct2();
}

// https://www.acmicpc.net/problem/2618

/*
My first dynamic + reconstruct problem
Dynamic idea was hard to think, So I get help by question page. 
At first, I made reconstruct function of backtracking.
But, "Times out" was the only I met.
So I made it of dp and it was successful.
*/