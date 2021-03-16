#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s1, s2;
int n1, n2;
vector<vector<int>> dp;
int lcs(int p1, int p2)
{
	if (p1 == n1 || p2 == n2) return 0;
	if (dp[p1][p2] != -1) return dp[p1][p2];
	if (s1[p1] == s2[p2])
		return dp[p1][p2] = lcs(p1 + 1, p2 + 1) + 1;
	else
		return dp[p1][p2] = max(lcs(p1 + 1, p2), lcs(p1, p2 + 1));
}
int main()
{
	cin >> s1; cin >> s2;
	n1 = s1.size(); n2 = s2.size();
	dp.resize(n1, vector<int>(n2, -1));
	cout << lcs(0, 0) << '\n';
}
// https://www.acmicpc.net/problem/9251
/*
Little hard DynamicProgramming problem
*/