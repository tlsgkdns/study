#include <iostream>

using namespace std;

long long N, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int t = 1, p = 9;
	while (N > p)
	{
		ans += (p * t++);
		N -= p;
		p *= 10;
	}
	ans += (N * t);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1748