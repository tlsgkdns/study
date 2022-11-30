#include <iostream>

using namespace std;
int X, Y, T;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> X >> Y;
		if (X < Y) cout << "NO BRAINS\n";
		else cout << "MMM BRAINS\n";
	}
}

// https://www.acmicpc.net/problem/4562