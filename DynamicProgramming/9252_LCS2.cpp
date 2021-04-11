#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int sz1, sz2, p = 0, n;
string s1, s2, ans;

int solve(int p1, int p2)
{
	if (p1 == s1.size() || p2 == s2.size()) return 0;
	int& ret = dp[p1][p2];
	if (ret != -1) return ret;
	if (s1[p1] == s2[p2])
		return ret = solve(p1 + 1, p2 + 1) + 1;
	else
		return ret = max(solve(p1 + 1, p2), solve(p1, p2 + 1));
}
void reconstruct(int a, int b)
{
	if (a == s1.size() || b == s2.size()) return;
	if (s1[a] == s2[b])
	{
		ans += s1[a];
		reconstruct(a + 1, b + 1);
	}
	else if (dp[a + 1][b] >= dp[a][b + 1])
		reconstruct(a + 1, b);
	else
		reconstruct(a, b + 1);
}
int main()
{
	cin >> s1;	cin >> s2;
	sz1 = s1.size(); sz2 = s2.size();
	dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
	n = solve(0, 0);
	reconstruct(0, 0);
	cout << n << '\n';
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/9252

/*
DP reconstruct problem.
I struggled with this problem more than I expected.
I had to learn more about reconstruct.
*/