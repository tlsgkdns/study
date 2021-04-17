#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cout.tie(NULL);
	int l = 0;
	vector<string> inp;
	string ans;
	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s; l = max(l, (int)s.size());
		inp.push_back(s);
	}
	for (int i = 0; i < l; i++)
		for (string s : inp)
		{
			if (s.size() <= i) continue;
			ans.push_back(s[i]);
		}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10798