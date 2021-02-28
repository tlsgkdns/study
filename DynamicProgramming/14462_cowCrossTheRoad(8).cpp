#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> dp(2001, vector<int>(2001, -1));
vector<int> pasture1, pasture2;
bool isFriend(int a, int b) { return abs(pasture1[a] - pasture2[b]) <= 4; }
int n;
int cross(int s, int e)
{
	if (s == n || e == n) return 0;
	if (dp[s][e] != -1) return dp[s][e];
	if (isFriend(s, e)) return dp[s][e] = cross(s + 1, e + 1) + 1;
	return dp[s][e] = max(cross(s + 1, e), cross(s, e + 1));
}
int main()
{
	cin >> n;
	pasture1 = vector<int>(n + 1); pasture2 = vector<int>(n + 1);
	for (int i = 0; i < n * 2; i++)
	{
		if (i < n) cin >> pasture1[i];
		else cin >> pasture2[i - n];
	}
	cout << cross(0, 0) << '\n';
}

// https://www.acmicpc.net/problem/14462

/*
At first I thought it as bipartite match
But it was dynamic
I tried recursive by subtracting one pair.
Next, Indexing one. And finally I solved it by indexing two.
*/