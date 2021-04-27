#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
string s, bomb, ans = "";
stack<char> st, trash;
int idx = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	cin >> bomb;
	for (char c : s)
	{
		st.push(c);
		if (c == bomb.back() && st.size() >= bomb.size())
		{
			int i = bomb.size() - 1;
			while (i >= 0 && bomb[i] == st.top())
			{
				trash.push(st.top());
				st.pop();
				i--;
			}
			while (i >= 0 && i < bomb.size() - 1)
			{
				st.push(trash.top());
				trash.pop();
				i++;
			}
		}
	}
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	if (!ans.empty())
		cout << ans << '\n';
	else
		cout << "FRULA" << '\n';
}

// https://www.acmicpc.net/problem/9935