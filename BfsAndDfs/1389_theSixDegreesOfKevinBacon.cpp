#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

bool adj[101][101];
int v[101];
int N, M, A, B, ans, cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(adj, false, sizeof(adj));
	cin >> N >> M;
	cnt = (N * N) + 1;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A][B] = true;
		adj[B][A] = true;
	}
	for (int n = 1; n <= N; n++)
	{
		memset(v, -1, sizeof(v));
		queue<int> q;
		int num = 0;
		q.push(n);
		v[n] = 0;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int i = 1; i <= N; i++)
			{
				if (v[i] == -1 && adj[cur][i])
				{
					v[i] = v[cur] + 1;
					q.push(i);
				}
			}
		}
		for (int i = 1; i <= N; i++)
			num += v[i];
		if (cnt > num)
		{
			cnt = num;
			ans = n;
		}
	}
	cout << ans << '\n';
}

//https://www.acmicpc.net/problem/1389