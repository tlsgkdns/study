#include <iostream>
#include <vector>
using namespace std;

int T;
string s;
int solve(int idx1, int idx2, bool f)
{
	if (idx1 >= idx2) return 0;
	int ret = 2;
	if (s[idx1] == s[idx2])
		ret = solve(idx1 + 1, idx2 - 1, f);
	else if (!f && solve(idx1 + 1, idx2, true) == 0 || solve(idx1, idx2 - 1, true) == 0)
		ret = 1;
	return ret;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> s;
		cout << solve(0, s.size() - 1, false) << '\n';
	}
}

// https://www.acmicpc.net/problem/17609