#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;
int T, N;
string dp[1001], MAX = "", tmp;

bool cmp(string s1, string s2)
{
	if (s1.size() == s2.size())
	{
		for (int i = 0; i < (int)s1.size(); i++)
			if (s1[i] != s2[i])
				return s1[i] < s2[i];
	}
	return s1.size() < s2.size();
}
string solve(int v)
{
	string& ret = dp[v];
	if (!ret.empty()) return ret;
	if (v == 3) return ret = "56";
	if (v == 2) return ret = "34";
	if (v == 1) return ret = "12";
	if (v == 0) return ret = "";
	ret = MAX;
	for (int n = 1; n <= v; n++)
	{
		tmp = solve(n) + solve(v - n);
		if (cmp(tmp, ret)) ret = tmp;
	}
	if (v % 2 == 0)
	{
		tmp = '1' + solve(v / 2) + '2';
		if (cmp(tmp, ret)) ret = tmp;
	}
	if (v % 3 == 0)
	{
		tmp = '3' + solve(v / 3) + '4';
		if (cmp(tmp, ret)) ret = tmp;
	}
	if (v % 5 == 0)
	{
		tmp = '5' + solve(v / 5) + '6';
		if (cmp(tmp, ret)) ret = tmp;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i <= 1000; i++)
	{
		MAX.push_back('1');
		MAX.push_back('2');
	}
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		string a = "";
		solve(N);
		for (int i = 0; i < (int)dp[N].size(); i++)
		{
			char ch;
			switch (dp[N][i])
			{
			case '1':
				ch = '(';
				break;
			case '2':
				ch = ')';
				break;
			case '3':
				ch = '{';
				break;
			case '4':
				ch = '}';
				break;
			case '5':
				ch = '[';
				break;
			default:
				ch = ']';
			}
			a.push_back(ch);
		}
		ans.push_back(a);
	}
	for (string a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/17623