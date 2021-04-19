#include <iostream>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
	bool leftPush = true;
	stack<char> ls, rs;
	list<char> l;
	string a, t, ans = "", s1 = "", s2 = "";
	cin >> a; cin >> t;
	for (int i = 0; i < t.size(); i++)
		l.push_back(t[i]);
	while (true)
	{
		if (l.empty()) break;
		if (leftPush)
		{
			s1.push_back(l.front());
			ls.push(l.front());
			l.pop_front();
			if (s1 == a)
			{
				for (int i = 0; i < s1.size(); i++)
					ls.pop();
				leftPush = false;
				s1 = "";
				while (!ls.empty() && s1.size() + 1 < a.size())
				{
					s1 = ls.top() + s1;
					ls.pop();
				}
				for (int i = 0; i < s1.size(); i++) ls.push(s1[i]);
			}
			else if (s1 != a.substr(0, s1.size()))
			{
				s1.erase(0, 1);
			}
		}
		else
		{
			s2 = l.back() + s2;
			rs.push(l.back());
			l.pop_back();
			if (s2 == a)
			{
				for (int i = 0; i < s2.size(); i++)
				{
					rs.pop();
				}
				leftPush = true;
				s2 = "";
				while (!rs.empty() && s2.size() + 1 < a.size())
				{
					s2 = s2 + rs.top();
					rs.pop();
				}
				for (int i = s2.size() - 1; i >= 0; i--) rs.push(s2[i]);
			}
			else if (s2 != a.substr(a.size() - s2.size(), s2.size()))
			{
				s2.erase(s2.size() - 1, 1);
			}
		}
	}
	while (!ls.empty())
	{
		rs.push(ls.top());
		ls.pop();
	}
	string wnd = "";

	while (!rs.empty())
	{
		wnd.push_back(rs.top());
		rs.pop();
		if (wnd.size() == a.size())
		{
			if (wnd != a)
			{
				ans += wnd[0];
				wnd.erase(0, 1);
			}
			else
			{
				int i = 0;
				while (!ans.empty() && i < a.size())
				{
					rs.push(ans.back());
					ans.pop_back();
					i++;
				}
				wnd.erase(0, i + 1);
			}
		}
	}
	if (wnd != a) ans += wnd;
	if (ans == a) ans = "";
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3111