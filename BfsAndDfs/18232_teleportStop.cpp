#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
vector<int> adj[300001];
int N, M, S, E, X, Y;
int v[300001], ans = 0;
queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	v[S] = 0;
	q.push(S);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		if (here == E)
		{
			ans = v[here];
			break;
		}
		if (here < N && v[here + 1] < 0)
		{
			v[here + 1] = v[here] + 1;
			q.push(here + 1);
		}
		if (here > 1 && v[here - 1] < 0)
		{
			v[here - 1] = v[here] + 1;
			q.push(here - 1);
		}
		for (int& there : adj[here])
		{
			if (v[there] >= 0) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/18232