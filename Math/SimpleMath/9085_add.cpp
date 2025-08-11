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
		int ans = 0, A;
		for (int i = 0; i < N; i++)
		{
			cin >> A;
			ans += A;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9085