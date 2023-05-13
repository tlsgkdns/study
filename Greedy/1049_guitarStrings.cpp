#include <iostream>
#include <algorithm>
using namespace std;

int N, M, A, B, S1 = 10001, S2 = 10001, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		S1 = min(S1, A);
		S2 = min(S2, B);
	}
	if (S2 * 6 < S1) ans = N * S2;
	else ans = min((N / 6) * S1 + (N % 6) * S2, (N / 6 + 1) * S1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1049