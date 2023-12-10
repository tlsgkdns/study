#include <iostream>
#include <algorithm>
using namespace std;

int N, K, A[1000001], l = 0, r = 1, cnt = 0, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K; ans = N + 1;
	for (int i = 0; i < N; i++) cin >> A[i];
	cnt = (A[0] == 1);
	while (true)
	{
		if (cnt == K)
		{
			ans = min(ans, r - l);
			cnt -= (A[l++] == 1);
		}
		if (cnt < K)
		{
			if (r == N) break;
			cnt += (A[r++] == 1);
		}
	}
	if (ans == N + 1) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/15565