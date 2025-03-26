#include <iostream>

using namespace std;
int T, N, M;

int solve(int n)
{
	int ret = (n == 0);
	while (n > 0)
	{
		if (n % 10 == 0) ++ret;
		n /= 10;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		int ans = 0;
		for (int n = N; n <= M; n++)
			ans += solve(n);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/11170