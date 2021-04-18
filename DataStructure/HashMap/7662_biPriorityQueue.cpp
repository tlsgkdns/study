#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	vector<string> ans;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		multiset<int> m;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			char cmd; int num;
			cin >> cmd >> num;
			if (cmd == 'I')
				m.insert(num);
			else
			{
				if (m.empty()) continue;
				if (num == 1)
					m.erase(--m.end());
				else
					m.erase(m.begin());
			}
		}
		if (m.empty()) ans.push_back("EMPTY");
		else ans.push_back(to_string(*m.rbegin()) + " " + to_string(*m.begin()));
	}
	for (auto a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/7662