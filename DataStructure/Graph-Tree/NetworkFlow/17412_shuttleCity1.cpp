#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> capa;

const int INF = 1000000000;
int N, P;
int networkFlow(int source, int sink)
{
	vector<vector<int>> flow(N + 1, vector<int>(N + 1, 0));
	int ret = 0;
	while (true)
	{
		vector<int> parent(N + 1, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty() && parent[sink] == -1)
		{
			int here = q.front();
			q.pop();
			for (int there = 1; there <= N; there++)
			{
				if (capa[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[sink] == -1) break;
		for (int p = sink; p != source; p = parent[p])
		{
			flow[parent[p]][p] += 1;
			flow[p][parent[p]] -= 1;
		}
		ret++;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> P;
	capa.resize(N + 1, vector<int>(N + 1, 0));
	int a, b;
	for (int i = 0; i < P; i++)
	{
		cin >> a >> b;
		capa[a][b] = 1;
	}
	cout << networkFlow(1, 2) << '\n';
}
// https://www.acmicpc.net/problem/17412