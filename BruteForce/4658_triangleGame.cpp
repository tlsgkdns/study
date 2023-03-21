#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T[6][3], ans = -1;
bool v[6];
char ch;

void solve(int prv, int d, int score, int f)
{
	if (d == 6)
	{
		if (prv == f) ans = max(ans, score);
		return;
	}
	for (int i = 1; i < 6; i++)
	{
		if (v[i]) continue;
		for (int idx = 0; idx < 3; idx++)
			if (T[i][idx] == prv)
			{
				v[i] = true;
				solve(T[i][(idx + 1) % 3], d + 1, score + T[i][(idx + 2) % 3], f);
				v[i] = false;
			}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		ans = -1;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				cin >> T[i][j];
		cin >> ch;
		for (int i = 0; i < 3; i++)
			solve(T[0][(i + 1) % 3], 1, T[0][(i + 2) % 3], T[0][i]);
		if (ans < 0) cout << "none\n";
		else cout << ans << '\n';
		if (ch == '$') break;
	}
}

// https://www.acmicpc.net/problem/4658