#include <iostream>

using namespace std;
int E, F, C, B, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> E >> F >> C;
	B = E + F;
	while (B >= C)
	{
		int r = (B / C);
		B = r + (B % C);
		ans += r;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5032