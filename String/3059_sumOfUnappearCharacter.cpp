#include <iostream>
#include <cstring>

using namespace std;
bool alp[26];
int T;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		memset(alp, true, sizeof(alp));
		cin >> S;
		for (int i = 0; i < S.size(); i++)
			alp[S[i] - 'A'] = false;
		int ans = 0;
		for (int i = 0; i < 26; i++)
			if (alp[i])
				ans += (i + 65);
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/3059