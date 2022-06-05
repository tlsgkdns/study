#include <iostream>

using namespace std;

int coin[6] = { 500, 100, 50, 10, 5, 1 };
int N, idx = 0, ans = 0;
int main()
{
	cin >> N;
	N = 1000 - N;
	while (N > 0)
	{
		while (coin[idx] <= N)
		{
			ans++;
			N -= coin[idx];
		}
		idx++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5585