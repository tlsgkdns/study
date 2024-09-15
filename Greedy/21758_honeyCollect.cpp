#include <iostream>
#include <algorithm>

using namespace std;

int N, A[100001], S1 = 0, ans = 0, S2 = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 1; i < N; i++) S1 += A[i];
	S2 = S1;
	for (int i = 1; i < N; i++)
	{
		S2 -= A[i];
		ans = max(ans, S1 - A[i] + S2);
	}
	S1 -= A[N - 1]; S1 += A[0];
	S2 = S1;
	for (int i = N - 2; i >= 0; i--)
	{
		S2 -= A[i];
		ans = max(ans, S1 - A[i] + S2);
	}
	S1 -= A[0];
	for (int i = 1; i < N - 1; i++)
		ans = max(ans, S1 + A[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/21758