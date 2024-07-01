#include <iostream>
#include <algorithm>
using namespace std;
int alp[26], T;
string S;

int id(char ch)
{
	return ch - 'A';
}
void solve(string& ans, char key, string word, char num)
{
	if (alp[id(key)] > 0)
	{
		int cnt = alp[id(key)];
		for (int i = 0; i < word.size(); i++)
			alp[id(word[i])] -= cnt;
		while (cnt--) ans.push_back(num);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> S;
		string ans = "";
		for (int i = 0; i < S.size(); i++) ++alp[id(S[i])];
		solve(ans, 'U', "FOUR", '4');
		solve(ans, 'X', "SIX", '6');
		solve(ans, 'Z', "ZERO", '0');
		solve(ans, 'W', "TWO", '2');
		solve(ans, 'G', "EIGHT", '8');
		solve(ans, 'F', "FIVE", '5');
		solve(ans, 'R', "THREE", '3');
		solve(ans, 'O', "ONE", '1');
		solve(ans, 'S', "SEVEN", '7');
		solve(ans, 'I', "NINE", '9');
		sort(ans.begin(), ans.end());
		cout << "Case #" << t << ": " << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/14369