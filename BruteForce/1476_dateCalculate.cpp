#include <iostream>

using namespace std;

int E, S, M, ans = 1, e = 1, s = 1, m = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> E >> S >> M;
	while (true)
	{
		if (E == e && S == s && M == m) break;
		++e; ++s; ++m; ++ans;
		if (e > 15) e = 1;
		if (s > 28) s = 1;
		if (m > 19) m = 1;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1476