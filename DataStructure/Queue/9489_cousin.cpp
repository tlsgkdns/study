#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K, T[1002], C[1002], P[1002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> K;
		if (N == 0 && K == 0) break;
		memset(C, 0, sizeof(C));
		vector<int> adj[1001];
		int idx = 1, target = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> T[i];
			if (T[i] == K) target = i;
		}
		queue<int> q;
		q.push(0);
		P[0] = -1;
		while (!q.empty() && idx < N)
		{
			int parent = q.front();
			q.pop();
			q.push(idx);
			P[idx] = parent;
			adj[parent].push_back(idx);
			int cnt = 1;
			while (idx < N - 1 && T[idx] + 1 == T[idx + 1])
			{
				idx++;
				adj[parent].push_back(idx);
				P[idx] = parent;
				q.push(idx);
			}
			++idx;
		}
		if (P[target] == -1 || P[P[target]] == -1) cout << 0 << '\n';
		else
		{
			int PoP = P[P[target]], ans = 0;
			for (int i = 0; i < adj[PoP].size(); i++)
			{
				if (adj[PoP][i] == P[target]) continue;
				ans += adj[adj[PoP][i]].size();
			}
			cout << ans << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/9489