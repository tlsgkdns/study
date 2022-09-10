#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 100000000;
int N, dp[105][105][105];
string str;
int black[105], white[105];
vector<pair<int, int>> order;
int solve(int here, int e, int height)
{
	int& ret = dp[here][e][height];
	if (ret != -1) return ret;
	ret = INF;
	if (here > e) return ret = 0;
	for (int there = here + 1; there <= e; there++)
		if (str[here] != str[there] && black[there] - black[here - 1] == white[there] - white[here - 1])
			for (int h = 1; h < height; h++)
				ret = min(ret, solve(here + 1, there - 1, h) + solve(there + 1, e, height) + (there - here + (2 * h)));
	return ret;
}

void reconstruct(int here, int e, int height)
{
	if (here > e) return;
	bool br = false;
	for (int there = here + 1; there <= e; there++)
	{
		if (br) break;
		if (str[here] != str[there] && black[there] - black[here - 1] == white[there] - white[here - 1])
			for (int h = 1; h < height; h++)
			{
				if (dp[here + 1][there - 1][h] < 0 || dp[there + 1][e][height] < 0) continue;
				if (dp[here][e][height] == dp[here + 1][there - 1][h] + dp[there + 1][e][height] + (there - here + (2 * h)))
				{
					order.push_back({ here, there });
					reconstruct(here + 1, there - 1, h);
					reconstruct(there + 1, e, height);
					br = true;
					break;
				}
			}
	}
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> str;
	str = 'S' + str;
	black[0] = 0; white[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		black[i] = black[i - 1] + (str[i] == '1');
		white[i] = white[i - 1] + (str[i] == '0');
	}
	cout << solve(1, N, (N / 2) + 1) << '\n';
	reconstruct(1, N, (N / 2) + 1);
	sort(order.begin(), order.end());
	for (int i = 0; i < order.size(); i++)
		cout << order[i].first << " " << order[i].second << '\n';
}

// https://www.acmicpc.net/problem/2647