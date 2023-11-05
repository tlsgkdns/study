#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
vector<int> adj[501];
int F[501][501], P[501], V[501][501];
int N, M, A, B, C, S, T, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		V[A][B] = C; V[B][A] = C;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	cin >> S >> T;
	while (true)
	{
		memset(P, -1, sizeof(P));
		queue<int> q;
		q.push(S);
		P[S] = S;
		while (!q.empty() && P[T] < 0)
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++)
			{
				int there = adj[here][i];
				if (V[here][there] - F[here][there] > 0 && P[there] < 0)
				{
					P[there] = here;
					q.push(there);
					if (there == T) break;
				}
			}
		}
		if (P[T] < 0) break;
		int f = INF;
		for (int now = T; now != S; now = P[now])
			f = min(f, V[P[now]][now] - F[P[now]][now]);
		for (int now = T; now != S; now = P[now])
		{
			F[P[now]][now] += f;
			F[now][P[now]] -= f;
		}
		ans += f;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14286