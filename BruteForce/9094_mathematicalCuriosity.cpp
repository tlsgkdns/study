#include <iostream>

using namespace std;

int T, N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		int ans = 0;
		cin >> N >> M;
		for (int a = 1; a < N; a++)
			for (int b = a + 1; b < N; b++)
				ans += (((a * a + b * b + M) % (a * b)) == 0);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9094