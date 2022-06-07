#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int v[100001];
int N, K, M, num, ans = -1;
vector<int> station[100001];
vector<int> adj[1001], src;
bool dst[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(v, -1, sizeof(v));
	cin >> N >> K >> M;
	for (int m = 0; m < M; m++)
		for (int k = 0; k < K; k++)
		{
			cin >> num;
			if (num == 1) src.push_back(m);
			if (num == N) dst[m] = true;
			for (int i = 0; i < station[num].size(); i++)
			{
				adj[station[num][i]].push_back(m);
				adj[m].push_back(station[num][i]);
			}
			station[num].push_back(m);
		}
	queue<int> q;
	for (int i = 0; i < src.size(); i++)
	{
		q.push(src[i]);
		v[src[i]] = 1;
	}
	while (!q.empty())
	{
		int here = q.front();
		if (dst[here])
		{
			ans = v[here] + (N != 1);
			break;
		}
		q.pop();
		for (int i = 0; i < (int)adj[here].size(); i++)
		{
			int there = adj[here][i];
			if (v[there] != -1) continue;
			v[there] = v[here] + 1;
			q.push(there);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5214