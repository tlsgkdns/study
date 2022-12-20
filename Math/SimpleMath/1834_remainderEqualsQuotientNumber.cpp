#include <iostream>
using namespace std;
long long ans = 0, N;
int main()
{
	cin >> N;
	for (int i = 1; i < N; i++)
		ans += i * (N + 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1834