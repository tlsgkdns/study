#include <iostream>
#include <string>
using namespace std;

string code[8] = { "000000", "001111", "010011", "011100",
				  "100110", "101001", "110101", "111010" };
string letter, ans;
int N, wrongIdx = -1;

void decode(string enc)
{
	int cnt[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
			if (enc[j] != code[i][j])
				cnt[i]++;
	}
	char c = '?';
	for (int i = 0; i < 8; i++)
	{
		if (cnt[i] <= 1)
		{
			if (c != '?')
			{
				ans.push_back('?');
				break;
			}
			else
				c = i + 'A';
		}
	}
	ans.push_back(c);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> letter;
	for (int i = 0; i < N; i++)
	{
		int s = i * 6;
		string alp(letter.begin() + s, letter.begin() + s + 6);
		decode(alp);
		if (ans.back() == '?')
		{
			wrongIdx = i + 1;
			break;
		}
	}
	if (wrongIdx == -1) cout << ans << '\n';
	else cout << wrongIdx << '\n';
}

// https://www.acmicpc.net/problem/2596