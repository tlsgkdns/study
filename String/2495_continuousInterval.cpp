#include <iostream>
#include <algorithm>
using namespace std;

string S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> S;
		if (cin.eof()) break;
		S += '-';
		char c = ' ';
		int ans = 0, s = 0;
		for (int i = 0; i < S.size(); i++)
			if (c != S[i])
			{
				c = S[i];
				ans = max(ans, s);
				s = 1;
			}
			else
			{
				++s;
			}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/2495