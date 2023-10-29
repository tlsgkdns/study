#include <iostream>
#include <stack>
#include <set>
using namespace std;

stack<int> S;
string E, T;
set<string> ans;
bool v[201];
int P[201];
void solve(int idx)
{
	if (idx == E.size())
	{
		if (T != E)
			ans.insert(T);
		return;
	}
	if (v[idx])
	{
		solve(idx + 1);
		return;
	}
	T.push_back(E[idx]);
	solve(idx + 1);
	T.pop_back();
	if (E[idx] == '(')
	{
		v[P[idx]] = true;
		solve(idx + 1);
		v[P[idx]] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> E;
	for (int i = 0; i < E.size(); i++)
	{
		if (E[i] == '(') S.push(i);
		if (E[i] == ')')
		{
			P[S.top()] = i;
			S.pop();
		}
	}
	solve(0);
	for (string a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/2800