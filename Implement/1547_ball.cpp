#include <iostream>

using namespace std;
int X, Y, N, ans = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		if (X == ans) ans = Y;
		else if (Y == ans) ans = X;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1547