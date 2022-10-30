#include <iostream>

using namespace std;

int N, C, ans = 0;
int main()
{
	cin >> N;
	for (int i = 0; i < 5; i++)
	{
		cin >> C;
		if (C % 10 == N) ans++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10797