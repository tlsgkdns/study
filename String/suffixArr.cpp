#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	vector<string> back;
	string s;
	cin >> s;
	for (auto i = s.begin(); i < s.end(); i++)
	{
		string tmp(i, s.end());
		back.push_back(tmp);
	}

	sort(back.begin(), back.end());
	for (string b : back)
		cout << b << '\n';

	return 0;
}
// https://www.acmicpc.net/problem/11656

/*
sort string
*/