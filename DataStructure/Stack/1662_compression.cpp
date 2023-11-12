#include <stack>
#include <iostream>

using namespace std;

stack<int> s1, s2;
string S;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S; s2.push(0);
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(')
		{
			--s2.top();
			s1.push(S[i - 1] - '0');
			s2.push(0);
		}
		else if (S[i] == ')')
		{
			int l = s2.top();
			s2.pop();
			s2.top() += s1.top() * l;
			s1.pop();
		}
		else
		{
			++s2.top();
		}
	}
	cout << s2.top() << '\n';
}

// https://www.acmicpc.net/problem/1662