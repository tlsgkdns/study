#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(string p)
{
	int n = p.size();
	int j = 0;
	vector<int> pi(n, 0);
	for (int i = 1; i < n; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string& h, string& p)
{
	vector<int> ret;
	vector<int> pi = getPi(p);
	int n = h.size(), m = p.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && h[i] != p[j])
			j = pi[j - 1];
		if (h[i] == p[j])
		{
			if (j == m - 1)
			{
				ret.push_back(i - m + 2);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string t, p;
	getline(cin, t);
	getline(cin, p);
	vector<int> ans = kmp(t, p);
	cout << ans.size() << '\n';
	for (int a : ans)
		cout << a << " ";
}

// acmicpc.net/problem/1786

/*
Standard kmp problem
*/