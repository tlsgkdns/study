#include <iostream>

using namespace std;

bool v[26000001];
int K, G[13], S = 0, ans = 0;
void solve(int idx, int s)
{
	if (idx == K)
	{
		if (s < 0) return;
		v[s] = true;
		return;
	}
	solve(idx + 1, s + G[idx]);
	solve(idx + 1, s);
	solve(idx + 1, s - G[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> G[i];
		S += G[i];
	}
	solve(0, 0);
	for (int i = 1; i <= S; i++)
		ans += !v[i];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17610