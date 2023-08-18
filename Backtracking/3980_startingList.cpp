#include <iostream>
#include <algorithm>
using namespace std;

int T, S[11][11], ans = 0;
bool v[11];
void solve(int d, int s)
{
	if (d == 11)
	{
		ans = max(ans, s);
		return;
	}
	for (int i = 0; i < 11; i++)
	{
		if (v[i] || S[d][i] == 0) continue;
		v[i] = true;
		solve(d + 1, s + S[d][i]);
		v[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> S[i][j];
		ans = 0;
		solve(0, 0);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/3980