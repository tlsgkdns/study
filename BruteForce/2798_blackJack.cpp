#include <iostream>
#include <vector>
using namespace std;

vector<int> card;
vector<bool> sl;
int n, m, ans = -1;
void solve(int sum, int d)
{
	if (d == 3)
	{
		if (sum <= m && sum > ans) ans = sum;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (sl[i]) continue;
		sl[i] = true;
		solve(card[i] + sum, d + 1);
		sl[i] = false;
	}
}
int main()
{
	cin >> n >> m; card.resize(n);
	sl.resize(n, false);
	for (int i = 0; i < n; i++)
		cin >> card[i];
	solve(0, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2798
/*
simple bruteforce
*/