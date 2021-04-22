#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(bool* visited, bool** connected, int node, queue<int>& order, int size)
{
	order.push(node);
	for (int i = 1; i < size; i++)
	{
		if (connected[i][node] && !visited[i])
		{
			visited[i] = true;
			dfs(visited, connected, i, order, size);
		}
	}
}

void bfs(bool* visited, bool** connected, int node, queue<int>& order, int size)
{
	queue<int> q;

	q.push(node);

	while (!q.empty())
	{
		int f = q.front();
		q.pop();

		for (int i = 1; i < size; i++)
		{
			if (connected[f][i] && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}

		order.push(f);
	}
}
int main(void)
{
	int n, m, v;

	bool** connected;
	bool* visited1, * visited2;
	queue<int> order1, order2;

	cin >> n >> m >> v;

	connected = new bool* [n + 1];
	visited1 = new bool[n + 1];
	visited2 = new bool[n + 1];

	fill(visited1, visited1 + n + 1, false);
	fill(visited2, visited2 + n + 1, false);

	for (int i = 0; i < n + 1; i++)
	{
		connected[i] = new bool[n + 1];
		fill(connected[i], connected[i] + n + 1, false);
	}


	for (int i = 0; i < m; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		connected[c1][c2] = true;
		connected[c2][c1] = true;
	}
	visited1[v] = true;
	visited2[v] = true;

	dfs(visited1, connected, v, order1, n + 1);
	bfs(visited2, connected, v, order2, n + 1);

	while (!order1.empty())
	{
		cout << order1.front() << ' ';
		order1.pop();
	}

	cout << '\n';

	while (!order2.empty())
	{
		cout << order2.front() << ' ';
		order2.pop();
	}

	cout << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/1260