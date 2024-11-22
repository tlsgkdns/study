#include <iostream>
#include <algorithm>

using namespace std;

int T, N, X;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int n = 101, x = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> X;
			n = min(X, n);
			x = max(X, x);
		}
		cout << 2 * (x - n) << '\n';
	}
}

// https://www.acmicpc.net/problem/5054