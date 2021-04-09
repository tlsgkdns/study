#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<bool>> connect, int node, vector<bool>& visited)
{
	visited[node] = true;

	for (int i = 1; i < connect.size(); i++)
	{
		if (connect[i][node] && !visited[i])
			dfs(connect, i, visited);
	}
}
int main(void)
{
	int com, n;
	cin >> com;
	cin >> n;
	vector<vector<bool>> connect(com + 1, vector<bool>(com + 1, false));
	vector<bool> visited(com + 1);
	int com1, com2;

	for (int i = 0; i < n; i++)
	{
		cin >> com1 >> com2;
		connect[com1][com2] = true;
		connect[com2][com1] = true;
	}
	dfs(connect, 1, visited);
	int answer = count_if(visited.begin(), visited.end(), [](bool b) {return b; }) - 1;

	cout << answer << '\n';
}

// https://www.acmicpc.net/problem/2606
/*
practice of dfs
*/