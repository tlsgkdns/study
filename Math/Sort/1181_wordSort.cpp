#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int main()
{
	cin >> n;
	vector<pair<int, string>> dic;
	vector<string> rep;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (find(rep.begin(), rep.end(), s) != rep.end())
			continue;
		dic.push_back(make_pair(s.size(), s));
		rep.push_back(s);
	}
	sort(dic.begin(), dic.end());
	for (auto d : dic)
		cout << d.second << '\n';
}

// https://www.acmicpc.net/problem/1181

/*
just sort paired length and string
*/