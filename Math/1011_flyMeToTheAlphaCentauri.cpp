#include <iostream>
#include <algorithm>
using namespace std;

int T, X, Y;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> X >> Y;
		int L = Y - X, tmp = L, ans = L, cnt = 0, n = 1;
		while (tmp > 0)
		{
			ans = min(ans, (tmp / n) + cnt + ((tmp % n) > 0));
			tmp -= (n * 2);
			cnt += 2;
			++n;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1011