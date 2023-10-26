#include <iostream>

using namespace std;

int X, N = 64, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X;
	while (X > 0)
	{
		if (X >= N)
		{
			X -= N;
			++ans;
		}
		N /= 2;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1094