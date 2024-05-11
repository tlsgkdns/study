#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s1, s2;
int solve(int idx)
{
	if (idx + s2.size() > s1.size()) return 0;
	string tmp(s1.begin() + idx, s1.begin() + idx + s2.size());
	int ret = 0;
	if (tmp == s2)  ret = solve(idx + s2.size()) + 1;
	else ret = solve(idx + 1);
	return ret;
}
int main()
{
	getline(cin, s1);
	getline(cin, s2);
	cout << solve(0) << '\n';
}

// https://www.acmicpc.net/problem/1543