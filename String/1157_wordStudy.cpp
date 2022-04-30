#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

string str;
int cnt[26], pre = -1;
char ans;
int main()
{
	memset(cnt, 0, sizeof(cnt));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		if (islower(str[i]))
			cnt[str[i] - 'a']++;
		else
			cnt[str[i] - 'A']++;
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] > pre)
		{
			pre = cnt[i];
			ans = i + 'A';
		}
		else if (cnt[i] == pre)
			ans = '?';
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1157