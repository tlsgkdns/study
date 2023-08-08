#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000001;
vector<int> adj[4001];
int N, M, A, B, ans = INF;
bool adj2[4001][4001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
		adj2[A][B] = true;
		adj2[B][A] = true;
	}
	for (int a = 1; a <= N; a++)
		for (int i = 0; i < adj[a].size(); i++)
		{
			int b = adj[a][i];
			for (int idx = 0; idx < adj[b].size(); idx++)
			{
				int c = adj[b][idx];
				if (!adj2[a][c]) continue;
				ans = min((int)(adj[a].size() + adj[b].size() + adj[c].size()) - 6, ans);
			}
		}
	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17089