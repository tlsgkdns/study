#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string S;
int ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		getline(cin, S);
		if (S == "#") break;
		ans = 0;
		for (int i = 0; i < S.size(); i++)
		{
			char c = tolower(S[i]);
			ans += (c == 'a' || c == 'e' || c == 'u' || c == 'i' || c == 'o');
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/1264