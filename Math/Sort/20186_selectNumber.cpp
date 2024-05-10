#include <iostream>
#include <algorithm>
using namespace std;

int N, K, A[5001], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	for (int i = N - 1; i > N - 1 - K; i--)
	{
		ans += A[i];
		ans -= N - 1 - i;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/20186