#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, Q, n, x;
vector<int> f;
vector<vector<int>> dp;
vector<int> ans;
int getDigit(int n)
{
	int ret = 1;
	while (n > 1)
	{
		n /= 2;
		ret++;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	dp.resize(19, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		cin >> dp[0][i];
	for (int i = 1; i < 19; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
	cin >> Q;
	for (int q = 0; q < Q; q++)
	{
		cin >> n >> x;
		while (n != 0)
		{
			int d = getDigit(n);
			x = dp[d - 1][x];
			n -= pow(2, d - 1);
		}
		ans.push_back(x);
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/17435