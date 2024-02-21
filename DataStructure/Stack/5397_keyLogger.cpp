#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int L;
string S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L;
	while (L--)
	{
		cin >> S;
		stack<char> l, r;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == '<' && !l.empty())
			{
				r.push(l.top());
				l.pop();
			}
			if (S[i] == '>' && !r.empty())
			{
				l.push(r.top());
				r.pop();
			}
			if (S[i] == '-' && !l.empty()) l.pop();
			if (S[i] != '>' && S[i] != '<' && S[i] != '-')
				l.push(S[i]);
		}
		string ans = "";
		while (!l.empty())
		{
			ans += l.top();
			l.pop();
		}
		reverse(ans.begin(), ans.end());
		while (!r.empty())
		{
			ans += r.top();
			r.pop();
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/5397