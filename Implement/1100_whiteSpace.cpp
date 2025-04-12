#include <iostream>

using namespace std;

char ch;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> ch;
			ans += (ch == 'F' && !((i % 2) ^ (j % 2)));
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1100