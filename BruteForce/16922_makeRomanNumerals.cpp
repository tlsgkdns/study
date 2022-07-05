#include <iostream>
#include <cstring>
using namespace std;

bool v[21][1001];
int rome[4] = { 1, 5, 10, 50 }, N, ans = 0;
void solve(int n, int num)
{
	if (v[n][num]) return;
	v[n][num] = true;
	if (n == 0)
	{
		ans++;
		return;
	}
	for (int i = 0; i < 4; i++)
		solve(n - 1, num + rome[i]);
}
int main()
{
	memset(v, false, sizeof(v));
	cin >> N;
	solve(N, 0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16922