#include <iostream>
using namespace std;
int T, N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int ans = 0;
		for (int i = 1; i <= N; i += 2)
			ans += i;
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9713