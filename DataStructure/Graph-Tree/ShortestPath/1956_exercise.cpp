#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dist;
const int INF = 1000000000;
int v, e, ans = INF;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e;
	dist.resize(v + 1, vector<int>(v + 1, INF));
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for (int s = 1; s < v; s++)
		for (int e = s + 1; e <= v; e++)
			ans = min(dist[s][e] + dist[e][s], ans);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1956

/*
Floyd-Warshall using problem.
*/