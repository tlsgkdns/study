#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> unknown, unknown_seen;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		unknown.push_back(s);
	}
	sort(unknown.begin(), unknown.end());
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (binary_search(unknown.begin(), unknown.end(), s))
			unknown_seen.push_back(s);
	}

	cout << unknown_seen.size() << '\n';
	sort(unknown_seen.begin(), unknown_seen.end());
	for (string us : unknown_seen) cout << us << '\n';
}

// https://www.acmicpc.net/problem/1764

/*
Search, sort that's all.
*/