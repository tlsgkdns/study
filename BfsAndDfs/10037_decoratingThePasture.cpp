#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ai, bi;

vector<vector<int>> adj;
vector<int> sig;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	adj.resize(N + 1); sig.resize(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		cin >> ai >> bi;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	int ans = 0;
	for (int n = 1; n <= N; n++)
	{
		if (sig[n] != 0) continue;
		int m1 = 1, m2 = 0;
		sig[n] = 1;
		queue<int> q;
		q.push(n);
		while (!q.empty())
		{
			if (ans == -1) break;
			int node = q.front();
			q.pop();
			for (int i = 0; i < adj[node].size(); i++)
			{
				int next = adj[node][i];
				if (sig[next] == sig[node])
				{
					ans = -1;
					break;
				}
				if (sig[next] == 0)
				{
					sig[next] = -sig[node];
					if (sig[next] == 1) m1++;
					else m2++;
					q.push(next);
				}
			}
		}
		if (ans == -1) break;
		ans += max(m1, m2);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10037