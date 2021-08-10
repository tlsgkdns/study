#include <iostream>
#include <vector>

using namespace std;

bool isEnd(string& game)
{
	for (int i = 0; i < 3; i++)
	{
		char c = game[i];
		bool b = false;
		for (int j = i; j < 9; j += 3)
			if (c != game[j] || game[j] == '.') b = true;
		if (!b) return true;
	}
	for (int i = 0; i < 9; i += 3)
	{
		char c = game[i];
		bool b = false;
		for (int j = i; j < i + 3; j++)
			if (c != game[j] || game[j] == '.') b = true;
		if (!b) return true;
	}
	return (game[0] == game[4] && game[4] == game[8]
		&& (game[0] != '.') && (game[4] != '.') && (game[8] != '.')) ||
		((game[2] == game[4]) && (game[4] == game[6])
			&& (game[2] != '.') && (game[4] != '.') && (game[6] != '.'));
}
bool solve(string& dst, string& src, bool turn, int O, int X)
{
	if (src == dst)
	{
		if (O + X == src.size()) return true;
		return isEnd(src);
	}
	bool ret = false;
	char t = (turn) ? 'O' : 'X';
	for (int i = 0; i < src.size(); i++)
	{
		if (dst[i] == src[i] || dst[i] != t) continue;
		if (isEnd(src)) continue;
		char tmp = src[i];
		src[i] = dst[i];
		ret |= solve(dst, src, !turn, O, X);
		src[i] = tmp;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str, src = ".........";
	vector<bool> ans;
	while (true)
	{
		cin >> str;
		if (str == "end") break;
		int o = 0, x = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'O') o++;
			else if (str[i] == 'X') x++;
		}
		ans.push_back(solve(str, src, false, o, x));
		src = ".........";
	}
	for (bool a : ans)
		if (a) cout << "valid" << '\n';
		else cout << "invalid" << '\n';
}
// https://www.acmicpc.net/problem/7682