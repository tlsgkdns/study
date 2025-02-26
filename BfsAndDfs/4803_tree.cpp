#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> adj[501];
int N, M, t = 0, A, B;
bool v[501];
bool dfs(int here, int p)
{
	bool ret = true;
	for (int& there : adj[here])
	{
		if (there == p) continue;
		if (v[there]) return false;
		v[there] = true;
		ret = ret && dfs(there, here);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) adj[i].clear();
		memset(v, false, sizeof(v));
		t++;
		int ans = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> A >> B;
			adj[A].push_back(B);
			adj[B].push_back(A);
		}
		for (int i = 1; i <= N; i++)
			if (!v[i])
			{
				v[i] = true;
				ans += dfs(i, -1);
			}
		cout << "Case " << t << ": ";
		if (ans == 0) cout << "No trees.\n";
		else if (ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of " << ans << " " << "trees.\n";
	}
}

// https://www.acmicpc.net/problem/4803