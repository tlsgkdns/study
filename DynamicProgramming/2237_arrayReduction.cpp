#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101, P = 10000;
vector<int> ans;
int dp[MAX][2 * P + 1], N, T, A[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	for (int i = 0; i < N; i++) cin >> A[i];
	dp[1][A[0] - A[1] + P] = 1;
	for (int i = 2; i < N; i++)
		for (int j = 0; j <= 2 * P; j++)
			if (dp[i - 1][j] > 0)
			{
				dp[i][j - A[i]] = 1;
				dp[i][j + A[i]] = 2;
			}
	int n = T + P;
	for (int i = N - 1; i >= 2; i--)
	{
		ans.push_back(dp[i][n]);
		n = n + ((dp[i][n] == 1) ? A[i] : -A[i]);
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << '\n';
	cout << 1 << '\n';
}

// https://www.acmicpc.net/problem/2237