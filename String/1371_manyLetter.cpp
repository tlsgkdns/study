#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string str;
int alp[26];
vector<pair<int, char>> a;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	while (true)
	{
		cin >> str;
		if (cin.eof()) break;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ') continue;
			++alp[str[i] - 'a'];
		}
	}
	for (int i = 0; i < 26; i++)
		if (alp[i] > 0)
			a.push_back({ -alp[i], (i + 'a') });
	sort(a.begin(), a.end());
	int m = a[0].first, idx = 0;
	while (idx < 26 && a[idx].first == m)
	{
		cout << a[idx++].second;
	}
}

// https://www.acmicpc.net/problem/1371