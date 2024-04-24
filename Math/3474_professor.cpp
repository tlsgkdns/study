#include <iostream>
using namespace std;

int N, T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int ans = 0;
		for (int i = 5; i <= N; i *= 5)
			ans += (N / i);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/3474