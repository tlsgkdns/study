#include <iostream>
using namespace std;
int N, ans = 0;

int solve(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		int d = (n % 10);
		cnt += (d > 0 && d % 3 == 0);
		n /= 10;
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 1; n <= N; n++)
		ans += solve(n);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17614