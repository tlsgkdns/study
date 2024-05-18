#include <iostream>

using namespace std;

string P;

bool isPalindrome(string s)
{
	for (int i = 0; i < s.size() / 2; i++)
	{
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P;
	if (isPalindrome(P))
	{
		if (isPalindrome(string(P.begin(), P.end() - 1))) cout << -1 << '\n';
		else cout << P.size() - 1 << '\n';
	}
	else
		cout << P.size() << '\n';
}

// https://www.acmicpc.net/problem/15927