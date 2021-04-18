#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
vector<vector<int>> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		deque<int> dq;
		string func, arrStr, buf;
		int n; bool front = false;
		cin >> func;
		cin >> n;
		cin >> arrStr;
		string s(arrStr.begin() + 1, arrStr.end() - 1);
		istringstream ss(s);
		while (getline(ss, buf, ','))
			dq.push_back(stoi(buf));
		for (char c : func)
		{
			if (c == 'R')
				front = !front;
			else if (c == 'D')
			{
				if (dq.empty())
				{
					dq.push_back(-1);
					break;
				}
				if (front)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		vector<int> a;
		while (!dq.empty())
		{
			if (front)
			{
				a.push_back(dq.back());
				dq.pop_back();
			}
			else
			{
				a.push_back(dq.front());
				dq.pop_front();
			}
		}
		ans.push_back(a);
	}
	for (vector<int> a : ans)
	{
		if (!a.empty() && a[0] == -1) cout << "error\n";
		else
		{
			cout << "[";
			for (int i = 0; i < a.size(); i++)
			{
				cout << a[i];
				if (i != a.size() - 1) cout << ",";
			}
			cout << "]" << '\n';
		}
	}
}

// https://www.acmicpc.net/problem/5430

/*
Deque use problem
*/