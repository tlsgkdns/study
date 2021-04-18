#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s; int n;
vector<int> dp;
vector<vector<int>> pal;
int isPal(int l, int r)
{
	if (l >= r) return 1;
	int& ret = pal[l][r];
	if (ret != -1) return ret;
	if (isPal(l + 1, r - 1) == 1 && s[l] == s[r])
		return ret = 1;
	else
		return ret = 0;
}
int palindrome(int start)
{
	if (start == n) return 0;
	if (dp[start] != -1) return dp[start];
	int ret = 2501;
	for (int mid = start; mid < n; mid++)
		if (isPal(start, mid) == 1) ret = min(1 + palindrome(mid + 1), ret);
	return dp[start] = ret;
}
int main()
{
	cin >> s;
	n = s.size();
	dp = vector<int>(n, -1);
	pal = vector<vector<int>>(n, vector<int>(n, -1));
	cout << palindrome(0) << '\n';
}

// https://www.acmicpc.net/problem/1509