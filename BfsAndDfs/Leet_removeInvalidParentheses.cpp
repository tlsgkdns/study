#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<string, bool> um;
	bool isValid(string s)
	{
		stack<char> st;
		for (char c : s)
		{
			switch (c)
			{
			case '(':
				st.push('(');
				break;
			case ')':
				if (st.empty()) return false;
				st.pop();
				break;
			}
		}
		return st.empty();
	}
	vector<string> removeInvalidParentheses(string s)
	{
		vector<string> ret;
		queue<string> q;
		q.push(s);
		int m = -1;
		while (!q.empty())
		{
			string f = q.front();
			q.pop();
			int sz = f.size();
			if (m > sz) continue;
			if (isValid(f))
			{
				m = f.size();
				ret.push_back(f);
			}
			string tmp = f;
			for (int i = 0; i < tmp.size(); i++)
			{
				if (*(f.begin() + i) == '(' || *(f.begin() + i) == ')')
				{
					f.erase(f.begin() + i);
					if (um.count(f) == 0)
					{
						q.push(f);
						um[f] = true;
					}
				}
				f = tmp;
			}
		}
		return ret;
	}
};
int main()
{
	string st;
	Solution s;
	cin >> st;
	vector<string> ans = s.removeInvalidParentheses(st);
	for (string a : ans)
		cout << a << '\n';
}

// https://leetcode.com/problems/remove-invalid-parentheses/