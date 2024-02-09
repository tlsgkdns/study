#include <iostream>
#include <vector>
using namespace std;

string S;

int N, l, r;
int dp[26][200001];
char ch;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	cin >> N;
	for (int a = 0; a < 26; a++)
		dp[a][0] = (a == (S[0] - 'a'));
	for (int i = 1; i < S.size(); i++)
		for (int a = 0; a < 26; a++)
			dp[a][i] = dp[a][i - 1] + (a == S[i] - 'a');
	for (int i = 0; i < N; i++)
	{
		cin >> ch >> l >> r;
		int t = ch - 'a';
		if (l == 0) cout << dp[t][r] << '\n';
		else cout << dp[t][r] - dp[t][l - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/16139