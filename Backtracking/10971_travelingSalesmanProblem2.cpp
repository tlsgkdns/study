#include <iostream>

using namespace std;

const int INF = 1000000000;
int W[11][11];
int N, ans = INF;
bool v[11];
void dfs(int cur, int s, int d, int st)
{
	if (ans < s) return;
	if (d == N)
	{
		if (W[cur][st] == 0 || ans < s + W[cur][st]) return;
		ans = s + W[cur][st];
		return;
	}
	for (int n = 0; n < N; n++)
	{
		if (v[n] || W[cur][n] == 0) continue;
		v[n] = true;
		dfs(n, s + W[cur][n], d + 1, st);
		v[n] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];
	for (int i = 0; i < N; i++)
	{
		v[i] = true;
		dfs(i, 0, 1, i);
		v[i] = false;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10971