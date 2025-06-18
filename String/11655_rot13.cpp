#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string S, ans = "";

char ch(char b, char c)
{
	return (((c - b) + 13) % 26) + b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	getline(cin, S);
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == ' ' || isdigit(S[i])) ans.push_back(S[i]);
		else
		{
			if (isupper(S[i]))
				ans.push_back(ch('A', S[i]));
			else
				ans.push_back(ch('a', S[i]));
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/11655