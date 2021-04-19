#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
	vector<string> cmd;
	stack<string> s;
	string tmp;
	int n;
	cin >> n;
	getline(cin, tmp);

	for (int i = 0; i < n; i++)
	{
		getline(cin, tmp);
		cmd.push_back(tmp);
	}

	for (string c : cmd)
	{
		if (c.find("push") != string::npos)
		{
			istringstream ss(c);
			string buf;
			bool num = false;
			while (getline(ss, buf, ' '))
			{
				if (num)	s.push(buf);
				else num = true;
			}
		}

		else if (c == "size")
			cout << s.size() << endl;

		else if (c == "empty")
			cout << ((s.empty()) ? 1 : 0) << endl;
		else if (c == "pop")
		{
			if (s.empty()) cout << -1 << endl;
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else if (c == "top")
			cout << ((s.empty()) ? -1 : stoi(s.top())) << endl;
	}
}

// https://www.acmicpc.net/problem/10828