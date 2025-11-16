#include <iostream>

using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int r = N % 100;
		if ((N + 1) % r == 0) cout << "Good\n";
		else cout << "Bye\n";
	}
}

// https://www.acmicpc.net/problem/31090