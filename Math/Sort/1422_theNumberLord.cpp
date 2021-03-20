#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int k, n, useing = 0, longest = 0;
string ans, repeat;

bool cmp(const string s1, const string s2)
{
	return (s2 + s1 < s1 + s2);
}
int main()
{
	cin >> k >> n;
	vector<string> nat(k);
	for (int i = 0; i < k; i++)
		cin >> nat[i];
	sort(nat.begin(), nat.end(), cmp);
	for (int i = 0; i < k; i++)
	{
		if (nat[i].size() > longest)
		{
			longest = nat[i].size();
			repeat = nat[i];
		}
	}
	for (int used = 0; used < n; used++)
	{
		if (useing + 1 == k)
		{
			ans += nat[useing];
			continue;
		}
		if (n - used == k - useing)
		{
			ans += nat[useing];
			useing++;
			continue;
		}
		ans += nat[useing];
		if (repeat != nat[useing])
			useing++;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1422

/*
Harder than I thought.
I thought this problem is easy.
But that wasn't. It was much harder than I thought.
I coded this with question's page.
And finally I did it!
The way of greed and sorting is much different than I first coded.
*/