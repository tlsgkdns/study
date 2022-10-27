#include <iostream>

using namespace std;
string S, T;
const string notAceept = " is not acceptable.\n";
const string accept = " is acceptable.\n";
bool isVowel(char ch)
{
	return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'u') || (ch == 'o'));
}
bool solve(string& str)
{
	int c = 0, v = 0;
	bool f = false;
	for (int i = 0; i < str.size(); i++)
	{
		if (i > 0 && str[i - 1] == str[i] && str[i] != 'e' && str[i] != 'o')
			return false;
		if (isVowel(str[i]))
		{
			f = true;
			c = 0;
			v++;
			if (v >= 3) return false;
		}
		else
		{
			v = 0;
			c++;
			if (c >= 3) return false;
		}
	}
	return f;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> S;
		if (S == "end") break;
		if (solve(S)) T = accept;
		else T = notAceept;
		cout << "<" << S << ">" << T;
	}
}

// https://www.acmicpc.net/problem/4659