#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		cin >> N >> K;
		if (cin.eof()) break;
		int ans = 0;
		while (N >= K)
		{
			int d = (N / K);
			ans += d * K;
			N = d + (N % K);
		}
		cout << ans + N << '\n';
	}
}

// https://www.acmicpc.net/problem/1673