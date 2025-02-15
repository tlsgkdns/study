#include <iostream>

using namespace std;

int N, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int a = 1; a < N; a++)
		for (int b = a + 2; b < N; b++)
		{
			if (a + b >= N) continue;
			ans += !((N - (a + b)) % 2);
		}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/14568