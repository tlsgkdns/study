#include <iostream>

using namespace std;

string S;
int alp[26], ans = 0, cnt = 0;

void solve(int p)
{
	if (cnt == S.size())
	{
		++ans;
		return;
	}
	for (int i = 0; i < 26; i++)
		if (i != p && alp[i] > 0)
		{
			++cnt;
			alp[i]--;
			solve(i);
			--cnt;
			alp[i]++;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (char& c : S)
	{
		alp[c - 'a']++;
	}
	solve(27);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1342