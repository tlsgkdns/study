#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> cnt;
int X, ans = 1e9, n = 0;
bool v[10];
void solve(int d, int num)
{
	if (d == cnt.size())
	{
		if (num > X) ans = min(ans, num);
		return;
	}
	for (int i = 0; i < cnt.size(); i++)
	{
		if (v[i]) continue;
		v[i] = true;
		solve(d + 1, num * 10 + cnt[i]);
		v[i] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X;
	int tmp = X;
	while (tmp > 0)
	{
		cnt.push_back(tmp % 10);
		tmp /= 10;
	}
	solve(0, 0);
	if (ans == 1e9) ans = 0;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2992