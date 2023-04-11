#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[1001], ans;
int N, K, cnt = 0, S, D, v[1001];
string str[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> str[i];
		cnt = 0;
		for (int j = 0; j < str[i].size(); j++)
			cnt += (str[i][j] == '1');
		adj[cnt].push_back(i);
	}
	cin >> S >> D;
	queue<pair<int, int>> q;
	cnt = 0;
	for (int i = 0; i < str[S].size(); i++)
		cnt += (str[S][i] == '1');
	q.push({S, cnt});
	v[S] = S;
	while (!q.empty())
	{
		int here = q.front().first;
		int c = q.front().second;
		q.pop();
		if (c > 0)
			for (int i = 0; i < adj[c - 1].size(); i++)
			{
				if (v[adj[c - 1][i]] > 0) continue;
				int s = 0;
				for(int idx = 0; idx < K; idx++)
				{
					if (s > 1) break;
					s += (str[adj[c - 1][i]][idx] != str[here][idx]);
				}
				if (s > 1) continue;
				v[adj[c - 1][i]] = here;
				q.push({adj[c - 1][i], c - 1});
			}
		if (c < K)
			for (int i = 0; i < adj[c + 1].size(); i++)
			{
				if (v[adj[c + 1][i]] > 0) continue;
				int s = 0;
				for (int idx = 0; idx < K; idx++)
				{
					if (s > 1) break;
					s += (str[adj[c + 1][i]][idx] != str[here][idx]);
				}
				if (s > 1) continue;
				v[adj[c + 1][i]] = here;
				q.push({adj[c + 1][i], c + 1});
			}
	}
	if (v[D] < 0) cout << -1 << '\n';
	else
	{
		while (v[D] != D)
		{
			ans.push_back(D);
			D = v[D];
		}
		ans.push_back(S);
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2479