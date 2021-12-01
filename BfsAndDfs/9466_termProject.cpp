#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> team, group;
stack<int> st;
int T, N;

void dfs(int X, int g)
{
	group[X] = g;
	st.push(X);
	if (group[team[X]] == group[X])
	{
		while (true)
		{
			int t = st.top();
			st.pop();
			if (t == team[X]) break;
		}
	}
	else if (group[team[X]] == -1)
		dfs(team[X], g);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	vector<int> ans;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		team = vector<int>(N + 1);
		group = vector<int>(N + 1, -1);
		st = stack<int>();
		for (int i = 1; i <= N; i++)
			cin >> team[i];
		int cnt = 0, a = 0;
		for (int i = 1; i <= N; i++)
			if (group[i] == -1)
				dfs(i, cnt++);
		ans.push_back(st.size());
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/9466