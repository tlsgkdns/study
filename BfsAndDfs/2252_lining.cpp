#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

vector<list<int>> line;
vector<bool> v;
stack<int> st;
void dfs(int s)
{
	v[s] = true;
	for (int l : line[s])
	{
		if (v[l]) continue;
		dfs(l);
	}

	st.push(s);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	line = vector<list<int>>(n + 1, list<int>());
	v = vector<bool>(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int f, s;
		cin >> f >> s;
		line[f].push_back(s);
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i]) continue;
		dfs(i);
	}
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}

// https://www.acmicpc.net/problem/2252

/*
Learning topological sort;
*/