#include <iostream>

using namespace std;
int T;
char a, c, b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> a >> c >> b;
		cout << (a - '0') + (b - '0') << '\n';
	}
}

// https://www.acmicpc.net/problem/10953