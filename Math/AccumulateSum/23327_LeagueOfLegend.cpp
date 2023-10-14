#include <iostream>

using namespace std;

long long N, Q, A[100001], B[100001], C[100001], D[100001], L, R;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		B[i] = B[i - 1] + A[i];
	}
	for (int i = 1; i < N; i++)
	{
		C[i] = A[i] * (B[N] - B[i]);
		D[i] = D[i - 1] + C[i];
	}
	D[N] = D[N - 1];
	while (Q--)
	{
		cin >> L >> R;
		cout << (D[R] - D[L - 1]) - ((B[R] - B[L - 1]) * (B[N] - B[R])) << '\n';
	}
}

// https://www.acmicpc.net/problem/23327