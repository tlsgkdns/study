#include <iostream>

using namespace std;

int C, K, P, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> C >> K >> P;
	for (int i = 1; i <= C; i++)
		ans += K * i + P * i * i;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16673