#include <iostream>

using namespace std;

int N, ans = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		ans *= 2;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/24723