#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
string ans = "";
int n, k;

vector<vector<vector<vector<bool>>>> dp;
bool solve(int a, int b, int c, int s)
{
	if (dp[a][b][c][s]) return false;
	dp[a][b][c][s] = true;
	if (a + b + c == n)
	{
		if (s == k)
			return true;
		else
			return false;
	}
	if (s > k || a + b + c > n) return false;
	ans.push_back('A');
	if (solve(a + 1, b, c, s)) return true;
	ans.pop_back();
	ans.push_back('B');
	if (solve(a, b + 1, c, s + a)) return true;
	ans.pop_back();
	ans.push_back('C');
	if (solve(a, b, c + 1, s + a + b)) return true;
	ans.pop_back();

	return false;
}
int main()
{
	cin >> n >> k;
	dp.resize(n + 1, vector<vector<vector<bool>>>(n + 1, vector<vector<bool>>(n + 1, vector<bool>(k + 1, false))));
	if (solve(0, 0, 0, 0))
		cout << ans << '\n';
	else
		cout << -1 << '\n';
}

// https://www.acmicpc.net/problem/12969