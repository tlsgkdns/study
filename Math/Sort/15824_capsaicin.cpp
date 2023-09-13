#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll N, cnt = 0, ans = 0, arr[300002], P[300002];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	P[0] = 1;
	for (int i = 1; i <= N; i++) P[i] = P[i - 1] * 2 % MOD;
	for (int i = 0; i < N; i++)
	{
		ans += (P[i] * arr[i] + MOD - P[N - 1 - i] * arr[i]);
		ans %= MOD;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15824