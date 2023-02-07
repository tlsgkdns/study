#include <iostream>
#include <stack>
using namespace std;

long long ans = 0;
string str;
int pos[40], i = 0;
long long solve(int s, int e)
{
	if (e <= s) return 1;
	if (s != pos[e]) return solve(s, pos[s]) + solve(pos[s] + 1, e);
	if (str[s] == '(') return 2 * solve(s + 1, e - 1);
	if (str[s] == '[') return 3 * solve(s + 1, e - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	stack<int> s;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[') s.push(i);
		if (str[i] == ')')
		{
			if (s.empty() || str[s.top()] != '(') break;
			pos[i] = s.top();
			pos[s.top()] = i;
			s.pop();
		}
		if (str[i] == ']')
		{
			if (s.empty() || str[s.top()] != '[') break;
			pos[i] = s.top();
			pos[s.top()] = i;
			s.pop();
		}
	}
	if (i == str.size() && s.empty()) ans = solve(0, str.size() - 1);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2504