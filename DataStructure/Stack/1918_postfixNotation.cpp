#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int prior(char o)
{
	switch (o)
	{
	case '(':
		return 2;
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}
int main()
{
	string s, ans, tmp;
	stack<char> ops;
	cin >> s;
	for (char c : s)
	{
		if (c == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				ans.push_back(ops.top());
				ops.pop();
			}
			if (!ops.empty()) ops.pop();
		}
		else if (isalpha(c))
			ans.push_back(c);
		else
		{
			if (ops.empty() || prior(ops.top()) < prior(c))
				ops.push(c);
			else
			{
				while (!ops.empty() && prior(ops.top()) >= prior(c) && ops.top() != '(')
				{
					ans.push_back(ops.top());
					ops.pop();
				}
				ops.push(c);
			}
		}
	}
	while (!ops.empty())
	{
		ans.push_back(ops.top());
		ops.pop();
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1918