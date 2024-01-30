#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

set<int> S[30];
int D, P;
long long N = 1, ans = -1, d = 1;

void solve(int cnt)
{
	if (pow(2, (P - cnt)) * N > d
		|| pow(9, (P - cnt)) * N < ans || S[cnt].find(N) != S[cnt].end()) return;
	S[cnt].insert(N);
	if (cnt == P)
	{
		ans = max(ans, N);
		return;
	}
	for (int i = 2; i <= 9; i++)
	{
		if (N * i > d) break;
		N *= i;
		solve(cnt + 1);
		N /= i;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D >> P;
	d = pow(10, D); --d;
	solve(0);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1443