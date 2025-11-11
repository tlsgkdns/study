#include <iostream>
#include <algorithm>

using namespace std;

int S[300001], N, Q, A[300001], L, R;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++)
		S[i] = S[i - 1] + A[i];
	for (int i = 0; i < Q; i++)
	{
		cin >> L >> R;
		cout << S[R] - S[L - 1] << '\n';
	}
}

// https://www.acmicpc.net/problem/17390