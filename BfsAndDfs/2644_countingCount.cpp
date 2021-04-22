#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> relative;
vector<bool> visited;

int x, y;

int dfs(int cur)
{
	if (cur == y) return 0;
	if (visited[cur]) return -1;
	visited[cur] = true;
	for (auto e : relative[cur])
	{
		int r = dfs(e);
		if (r != -1)
			return r + 1;
	}

	return -1;
}
int main()
{
	int n, m;
	cin >> n;
	relative.resize(n + 1);
	visited.resize(n + 1);

	cin >> x >> y;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		relative[a].push_back(b);
		relative[b].push_back(a);
	}

	cout << dfs(x) << endl;
	return 0;
}

// https://www.acmicpc.net/problem/2644