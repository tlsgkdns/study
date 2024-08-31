#include <iostream>

using namespace std;
const int INF = 1000000007;
int N, ans = 0;
int adj[51][51];
char ch;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> ch;
			adj[i][j] = (ch == 'Y') ? 1 : INF;
		}
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	for (int i = 0; i < N; i++)
	{
		int s = 0;
		for (int j = 0; j < N; j++)
			if (i != j && adj[i][j] <= 2)
				++s;
		ans = max(s, ans);
	}
	cout << ans << '\n';
}


// https://www.acmicpc.net/problem/1058