#include <iostream>

using namespace std;

const int MAX = 100001;
int N, K, B, T, R[MAX], A[MAX], ans = MAX;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N >> K >> B;
	for (int i = 0; i < B; i++)
	{
		cin >> T;
		R[T] = 1;
	}
	for (int i = 1; i <= N; i++)
		A[i] = A[i - 1] + R[i];
	for (int i = K; i <= N; i++)
		ans = min(ans, A[i] - A[i - K]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14465