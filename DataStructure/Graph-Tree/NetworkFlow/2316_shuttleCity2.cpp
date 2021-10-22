#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> cap;
int N, P;
const int INF = 1000000000;
int network(int src, int dst)
{
	vector<vector<int>> flow(2 * N + 1, vector<int>(2 * N + 1, 0));
	int ret = 0;
	while (true)
	{
		vector<int> parent(2 * N + 1, -1);
		queue<int> q;
		parent[src] = src;
		q.push(src);
		while (!q.empty() && parent[dst] == -1)
		{
			int here = q.front();
			q.pop();
			for (int there = 1; there <= 2 * N; there++)
			{
				if (cap[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[dst] == -1) break;
		for (int p = dst; p != src; p = parent[p])
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
	cap.resize(2 * N + 1, vector<int>(2 * N + 1, 0));
	int a, b;
	for (int i = 1; i <= N; i++)
		cap[i][i + N] = 1;
	for (int i = 0; i < P; i++)
	{
		cin >> a >> b;
		cap[a + N][b] = INF;
		cap[b + N][a] = INF;
	}
	cout << network(N + 1, 2) << '\n';
}
// https://www.acmicpc.net/problem/2316