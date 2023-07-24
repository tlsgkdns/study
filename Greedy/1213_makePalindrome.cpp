#include <iostream>

using namespace std;

string str, ans = "";
int alp[27], odd = -1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		++alp[str[i] - 'A'];
	for (int i = 0; i < 27; i++)
	{
		if (alp[i] % 2 > 0)
		{
			if (odd == -1) odd = i;
			else odd = -2;
		}
	}
	if ((str.size() % 2 > 0 && odd >= 0) || (str.size() % 2 == 0 && odd == -1))
	{
		if (odd >= 0) --alp[odd];
		for (int i = 0; i < 27; i++)
		{
			alp[i] /= 2;
			while (alp[i] > 0)
			{
				ans.push_back(i + 'A');
				--alp[i];
			}
		}

		int s = ans.size();
		if (odd >= 0) ans.push_back(odd + 'A');
		for (int i = s - 1; i >= 0; i--) ans.push_back(ans[i]);
	}
	if (ans.empty()) ans = "I'm Sorry Hansoo";
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1213