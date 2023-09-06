#include <iostream>
#include <algorithm>
using namespace std;

string S1, S2;
int dp[4003][4003], ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S1; cin >> S2;
	S1 = "a" + S1; S2 = "a" + S2;
	for (int i = 1; i < S1.size(); i++)
		for (int j = 1; j < S2.size(); j++)
		{
			if (S1[i] == S2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			ans = max(ans, dp[i][j]);
		}
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/5582