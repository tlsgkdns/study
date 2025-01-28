#include <iostream>
#include <cmath>

using namespace std;

int P, N, ans = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P;
		ans += (P - 1);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2010