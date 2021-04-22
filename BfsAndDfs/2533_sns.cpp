#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> sns;
vector<bool> visited;
int n, k = 0;

bool dfs(int here)
{
	bool ret = false;
	visited[here] = true;
	for (auto next : sns[here])
	{
		if (visited[next]) continue;
		if (!dfs(next))
			ret = true;
	}
	if (ret) k++;
	return ret;
}
int main()
{
	cin >> n;

	sns.resize(n + 1, list<int>());
	visited.resize(n + 1, false);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		sns[b].push_back(a);
		sns[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
		if (!visited[i]) dfs(i);

	cout << k << '\n';

	return 0;
}

// https://www.acmicpc.net/problem/2533