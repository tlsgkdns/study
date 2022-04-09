#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

string str;
int dp[21][101][2], N;
string bridge[2];

int solve(int idx, int step, int k)
{
	if (idx == (int)str.size())
		return 1;
	if (step == N) return 0;
	int& ret = dp[idx][step][k];
	if (ret != -1) return ret;
	if (str[idx] == bridge[k][step])
		return ret = solve(idx + 1, step + 1, !k) + solve(idx, step + 1, k);
	return ret = solve(idx, step + 1, k);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> str;
	cin >> bridge[0];
	cin >> bridge[1];
	N = bridge[0].size();
	int ans = 0;
	ans = solve(0, 0, 0) + solve(0, 0, 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2602