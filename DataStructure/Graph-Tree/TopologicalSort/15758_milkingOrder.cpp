#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> input[50001], ans, adj[100001];
int N, M, in[100001];

bool solve(int L, bool cmp)
{
	memset(in, 0, sizeof(in));
	for (int i = 1; i <= N; i++) adj[i].clear();
	for (int i = 1; i <= L; i++)
		for (int j = 1; j < input[i].size(); j++)
		{
			++in[input[i][j]];
			adj[input[i][j - 1]].push_back(input[i][j]);
		}
	priority_queue<int> pq;
	for (int i = 1; i <= N; i++)
		if (in[i] == 0)
			pq.push(-i);
	vector<int> tmp;
	while (!pq.empty())
	{
		int now = -pq.top();
		pq.pop();
		tmp.push_back(now);
		for (int i = 0; i < adj[now].size(); i++)
		{
			int nxt = adj[now][i];
			--in[nxt];
			if (in[nxt] == 0)
				pq.push(-nxt);
		}
	}
	if (cmp)
	{
		for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << " ";
		cout << '\n';
	}
	return (tmp.size() == N);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		int a = 0, n = 0;
		cin >> a;
		while (a--)
		{
			cin >> n;
			input[i].push_back(n);
		}
	}
	int l = 0, r = M + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (solve(m, false)) l = m;
		else r = m;
	}
	solve(l, true);
}

// https://www.acmicpc.net/problem/15758