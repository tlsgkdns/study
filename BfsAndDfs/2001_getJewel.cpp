#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 101;
vector<pair<int, int>> adj[MAX];
int N, M, K, A, B, C, ans = 0, J[MAX];
bool v[101][1 << 15];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> A;
		J[A] = i + 1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	v[1][0] = true;
	while (!q.empty())
	{
		int here = q.front().first;
		int jewel = q.front().second;
		q.pop();
		int cnt = 0;
		for (int i = 1; i <= jewel; (i = (i << 1)))
			if (jewel & i)
				++cnt;
		if (here == 1) ans = max(cnt, ans);
		if (J[here] > 0)
		{
			int nxtj = (jewel | (1 << J[here]));
			if (!v[here][nxtj])
			{
				v[here][nxtj] = true;
				q.push({ here, nxtj });
			}
		}
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int lim = adj[here][i].second;
			if (cnt > lim) continue;
			if (!v[there][jewel])
			{
				v[there][jewel] = true;
				q.push({ there, jewel });
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2001