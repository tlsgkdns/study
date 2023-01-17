#include <iostream>
using namespace std;

int N, ans = 0, a, b, c;
char ch;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 1; n <= N; n++)
	{
		if (n < 100) ++ans;
		else
		{
			int tmp = n;
			a = tmp / 100;
			tmp %= 100;
			b = tmp / 10;
			c = tmp % 10;
			ans += (a - b == b - c);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1065