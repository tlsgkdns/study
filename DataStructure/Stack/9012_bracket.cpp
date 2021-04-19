#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	stack<char> st;
	vector<bool> r;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (string s : v)
	{
		for (char c : s)
		{
			if (c == '(')
				st.push('(');
			else if (c == ')')
			{
				if (st.empty()) { st.push('d'); break; }
				st.pop();
			}

		}
		r.push_back(st.empty());
		while (!st.empty()) st.pop();
	}
	string no = "NO", yes = "YES";

	for (bool re : r)
	{
		string result = (re) ? yes : no;
		cout << result << '\n';
	}
	return 0;
}

// https://www.acmicpc.net/problem/9012