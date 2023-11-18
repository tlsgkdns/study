#include <iostream>

using namespace std;

int N, K, A[1000001], cnt = 0, l = 0, r = 1, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	cnt = (A[0] % 2);
	while (r < N)
	{
		ans = (ans > (r - l) - cnt) ? ans : r - l - cnt;
		if (cnt == K && A[r] % 2 > 0)
		{
			while (l + 1 < r && cnt == K)
			{
				cnt -= (A[l] % 2);
				++l;
			}
			if (cnt == K && l + 1 == r)
			{
				++l; ++r;
				cnt = A[l] % 2;
			}
		}
		else
		{
			cnt += (A[r] % 2);
			++r;
		}
	}
	ans = (ans > r - l - cnt) ? ans : r - l - cnt;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/22862