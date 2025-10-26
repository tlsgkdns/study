#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;
string L;
int alp[26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, L);
		if (L == "#") break;
		memset(alp, 0, sizeof(alp));
		int ans = 0;
		for (int i = 0; i < L.size(); i++)
		{
			int idx = tolower(L[i]) - 'a';
			if (isalpha(L[i]) && alp[idx] == 0)
			{
				alp[idx]++;
				++ans;
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/7600