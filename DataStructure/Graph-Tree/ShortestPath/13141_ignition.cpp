#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 201, INF = 1000000001;
double ans = INF;
int adj[MAX][MAX];
int N, M, S[20001], E[20001], L[20001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i != j) adj[i][j] = INF;
	for (int i = 0; i < M; i++)
	{
		cin >> S[i] >> E[i] >> L[i];
		adj[S[i]][E[i]] = min(adj[S[i]][E[i]], L[i]);
		adj[E[i]][S[i]] = min(adj[E[i]][S[i]], L[i]);
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
	for (int i = 1; i <= N; i++)
	{
		double s = 0;
		for (int j = 0; j < M; j++)
			s = max(s, ((double)adj[i][S[j]] + (double)adj[i][E[j]] + (double)L[j]) / 2);
		ans = min(ans, s);
	}
	cout << fixed;
	cout.precision(1);
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/13141