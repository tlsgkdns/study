#include <iostream>

using namespace std;
int N, K, ans = 0, L = 0;
int main()
{
	cin >> N >> K;
	for (int n = 1; n <= N; n++)
		if (N % n == 0)
		{
			L++;
			if (L == K)
			{
				ans = n;
				break;
			}
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2501