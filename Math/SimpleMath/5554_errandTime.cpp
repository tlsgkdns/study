#include <iostream>

using namespace std;

int S, ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++)
	{
		cin >> S;
		ans += S;
	}
	cout << ans / 60 << '\n';
	cout << ans % 60 << '\n';
}

// https://www.acmicpc.net/problem/5554