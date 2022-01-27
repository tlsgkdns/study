#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
vector<pii> chkpoint;
vector<int> dist;
int N, X, Y, s = 0;
int getDist(pii p1, pii p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		chkpoint.push_back({ X, Y });
	}
	for (int i = 0; i < N - 1; i++)
	{
		int d = getDist(chkpoint[i], chkpoint[i + 1]);
		dist.push_back(d);
		s += d;
	}
	int ans = s;
	for (int i = 1; i < N - 1; i++)
	{
		int prev = dist[i - 1] + dist[i];
		ans = min(getDist(chkpoint[i - 1], chkpoint[i + 1]) - prev + s, ans);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10655