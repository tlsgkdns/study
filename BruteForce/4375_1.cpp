#include <iostream>

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (cin.eof()) break;
		int a = 1, ans = 1;
		while (true)
		{
			a %= N;
			if (a == 0) break;
			a = 10 * a + 1;
			++ans;
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/4375