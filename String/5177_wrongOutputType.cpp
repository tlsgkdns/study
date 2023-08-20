#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int K;
string s1, s2;

string solve(string& str)
{
	string ret = "";
	int idx = 0;
	while (idx < str.size())
	{
		if (isalpha(str[idx])) ret.push_back(tolower(str[idx]));
		else if (str[idx] == '(' || str[idx] == '{' || str[idx] == '[')
			ret.push_back('(');
		else if (str[idx] == ',' || str[idx] == ';')
			ret.push_back(',');
		else if (str[idx] == ')' || str[idx] == '}' || str[idx] == ']')
			ret.push_back(')');
		else if (str[idx] == ' ')
		{
			int sidx = idx, eidx = idx;
			while (eidx < str.size() && str[eidx] == ' ') ++eidx;
			if (sidx > 0 && eidx < str.size() && isalnum(str[sidx - 1]) && isalnum(str[eidx + 1])) ret.push_back(' ');
			idx = eidx - 1;
		}
		else ret.push_back(str[idx]);
		++idx;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	cin.ignore();
	for (int i = 1; i <= K; i++)
	{
		string ans = "not equal";
		getline(cin, s1);
		getline(cin, s2);
		if (solve(s1) == solve(s2)) ans = "equal";
		cout << "Data Set " << i << ": " << ans << '\n' << '\n';
	}
}

// https://www.acmicpc.net/problem/5177