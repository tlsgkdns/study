#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getPi(string str)
{
	int m = (int)str.size(), j = 0;
	vector<int> pi(m - j, 0);
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && str[i] != str[j])
			j = pi[j - 1];
		if (str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int ans = 0;
	string str;
	cin >> str;
	for (int s = 0; s < str.size(); s++)
	{
		string tmp(str.begin() + s, str.end());
		vector<int> pi = getPi(tmp);
		for (int i = 0; i < pi.size(); i++)
			ans = max(pi[i], ans);
	}
	cout << ans << '\n';
}
// https://www.acmicpc.net/problem/1701