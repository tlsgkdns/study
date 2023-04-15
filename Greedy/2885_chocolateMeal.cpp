#include <iostream>

using namespace std;

int K, ans1 = 1, ans2 = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	while (ans1 < K) ans1 *= 2;
	int b = ans1;
	while (K != b)
	{
		if (b <= K)
		{
			K -= b;
			continue;
		}
		b /= 2;
		++ans2;
	}
	cout << ans1 << " " << ans2 << '\n';
}

// https://www.acmicpc.net/problem/2885