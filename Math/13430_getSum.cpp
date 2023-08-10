#include <iostream>

using namespace std;
using ll = long long;
const int MOD = 1000000007;
ll arr[55][55], arr2[55][55], ans = 0;
int N, K;

void mul(ll a[55][55], ll b[55][55])
{
	int tmp[55][55] = { 0, };
	for (int i = 0; i <= K + 1; i++)
		for (int j = 0; j <= K + 1; j++)
			for (int k = 0; k <= K + 1; k++)
				tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % MOD;
	for (int i = 0; i <= K + 1; i++)
		for (int j = 0; j <= K + 1; j++)
			a[i][j] = tmp[i][j];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	for (int i = 0; i <= K + 1; i++) arr[i][i] = 1;
	for (int i = 0; i <= K + 1; i++)
		for (int j = 0; j <= i; j++)
			arr2[i][j] = 1;
	--N;
	while (N > 0)
	{
		if (N % 2) mul(arr, arr2);
		mul(arr2, arr2);
		N /= 2;
	}
	for (int i = 0; i <= K + 1; i++)
		ans = (ans + arr[K + 1][i]) % MOD;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13430