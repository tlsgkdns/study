#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[304], b[304], P[304], dp[304][304][304];
int N, M, K, T, A, B;
int solve(int t, int f, int r)
{
	if (t == N + 1) return 0;
	if (P[t] >= T) return solve(t + 1, 0, r) + 1;
	if (P[t] + f >= T) return solve(t + 1, f, r) + 1;
	int& ret = dp[t][f][r];
	if (ret >= 0) return ret;
	ret = solve(t + 1, f, r);
	int L = T - P[t] - f;
	if (L <= r) ret = max(ret, solve(t + 1, L + f, r - L) + 1);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K >> T;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		++a[A]; ++b[B];
	}
	for (int i = 1; i <= N + 1; i++)
		P[i] = a[i] + P[i - 1] - b[i];
	cout << solve(1, 0, K) << '\n';
}

// https://www.acmicpc.net/problem/17258