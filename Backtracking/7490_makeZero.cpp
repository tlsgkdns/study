#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> ans;
char ops[3] = { '-', '+', ' ' };

int calc(string ex)
{
	int ret = 0;
	string tmp = "";
	bool plus = true, minus = false;
	for (int i = 0; i < ex.size(); i++)
	{
		if (isdigit(ex[i]))
			tmp.push_back(ex[i]);
		else if (ex[i] == '-' || ex[i] == '+')
		{
			if (plus) ret += stoi(tmp);
			else if (minus) ret -= stoi(tmp);
			plus = false; minus = false; tmp = "";
			if (ex[i] == '+') plus = true;
			else minus = true;
		}
	}
	if (plus) ret += stoi(tmp);
	else if (minus) ret -= stoi(tmp);

	return ret;
}
void backtrack(string exp, int d, int n, int id)
{
	if (n < d)
	{
		if (calc(exp) == 0)
			ans[id].push_back(exp);
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		exp.push_back(ops[i]);
		exp.push_back(d + '0');
		backtrack(exp, d + 1, n, id);
		exp.pop_back();
		exp.pop_back();
	}
}
int main()
{
	int t, N;
	cin >> t;
	ans.resize(t);
	for (int i = 0; i < t; i++)
	{
		cin >> N;
		backtrack("1", 2, N, i);
		sort(ans[i].begin(), ans[i].end());
	}
	for (vector<string> vs : ans)
	{
		for (string str : vs)
			cout << str << '\n';
		cout << '\n';
	}
}
// https://www.acmicpc.net/problem/7490