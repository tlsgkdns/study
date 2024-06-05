#include <iostream>
#include <stack>
#include <string>
using namespace std;

string L;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, L);
		if (L == ".") break;
		stack<char> S;
		string ans = "yes\n";
		for (int i = 0; i < L.size(); i++)
			if (L[i] == '[' || L[i] == '(')
			{
				S.push(L[i]);
			}
			else if (L[i] == ']')
			{
				if (S.empty() || S.top() != '[')
				{
					ans = "no\n";
					break;
				}
				else
					S.pop();
			}
			else if (L[i] == ')')
			{
				if (S.empty() || S.top() != '(')
				{
					ans = "no\n";
					break;
				}
				else
					S.pop();
			}
		if (!S.empty()) ans = "no\n";
		cout << ans;
	}
}

// https://www.acmicpc.net/problem/4949