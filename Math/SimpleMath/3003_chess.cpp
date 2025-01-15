#include <iostream>

using namespace std;
using ll = long long;
ll A, S = 0, ans = 0;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		ans += (S * A);
		S += A;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/13900