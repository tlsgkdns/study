#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0) ++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

int main()
{
	vector<string> inp;
	vector<int> ans;
	string in;
	while (in != ".")
	{
		cin >> in;
		inp.push_back(in);
	}
	inp.pop_back();
	for (int i = 0; i < inp.size(); i++)
	{
		int l = inp[i].length();
		vector<int> tbl = getPartialMatch(inp[i]);
		string head(inp[i].begin(), inp[i].end() - tbl.back());
		if (head.size() == l || l % head.size() != 0)
			ans.push_back(1);
		else
			ans.push_back(l / head.size());
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/4354

/*
My first KMP problem.
To solve this problem I came up with KMP
But, I have some misunderstood thought on the algorithm.
So, I have some trial and error, and Finally solved this problem.
*/