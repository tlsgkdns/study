#include <iostream>

using namespace std;

unsigned long long a, b, ans = 1;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		ans *= ((i + 1) * i) / 2;
		ans %= 14579;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14579