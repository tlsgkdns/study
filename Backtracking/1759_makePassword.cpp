#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> ans;
vector<char> code;
int L, C;
char ch;

bool isVowel(char c)
{
	return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}

void solve(int idx, string& str)
{
	if ((int)str.size() == L)
	{
		int vw = 0, cn = 0;
		for (int i = 0; i < L; i++)
		{
			if (isVowel(str[i])) vw++;
			else cn++;
		}
		if (vw > 0 && cn >= 2) ans.push_back(str);
		return;
	}
	if (idx >= C) return;
	solve(idx + 1, str);
	str.push_back(code[idx]);
	solve(idx + 1, str);
	str.pop_back();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> ch;
		code.push_back(ch);
	}
	sort(code.begin(), code.end());
	string tmp = "";
	solve(0, tmp);
	sort(ans.begin(), ans.end());
	for (string a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/1759