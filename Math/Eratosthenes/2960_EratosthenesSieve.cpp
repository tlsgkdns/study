#include <iostream>

using namespace std;

int N, K, cnt = 0, ans = -1;
bool sieve[1001];
int main()
{
	cin >> N >> K;
	for (int n = 2; n <= N; n++)
	{
		if (ans >= 0) break;
		if (sieve[n]) continue;
		for (int num = n; num <= N; num += n)
		{
			if (sieve[num]) continue;
			sieve[num] = true;
			cnt++;
			if (cnt == K)
			{
				ans = num;
				break;
			}
		}
	}
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/2960