#include <iostream>
#include <vector>
#include <string>
using namespace std;
string inp;
bool ans = false;
int rec(string s)
{
	if (s.size() == 1)
	{
		int a = stoi(s);
		ans = ((a % 3) == 0);
		return 0;
	}
	int ret = 0;
	for (char c : s)
		ret += c - '0';

	return rec(to_string(ret)) + 1;
}
int main()
{
	cin >> inp;
	cout << rec(inp) << '\n';
	if (ans)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

// https://www.acmicpc.net/problem/1769