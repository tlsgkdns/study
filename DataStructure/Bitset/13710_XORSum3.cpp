#include <iostream>

using namespace std;

int N, A, S[100001], B[31];
long long ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		S[i] = S[i - 1] ^ A;
	}
	for (int i = 0; i < 30; i++)
		for (int idx = 0; idx <= N; idx++)
			if (S[idx] & (1 << i))
				B[i]++;
	for (int i = 0; i < 30; i++)
		ans += (1LL << i) * B[i] * (N + 1 - B[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13710