#include <iostream>
#include <cctype>

using namespace std;
string L, ans = "";
int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	while (true)
	{
		cin >> L;
		if (L == "E-N-D") break;
		string tmp = "";
		L.push_back('/');
		for (int i = 0; i < L.size(); i++)
		{
			if (isalpha(L[i]) || L[i] == '-')
				tmp.push_back(L[i]);
			else
			{
				if (ans.size() < tmp.size())
					ans = tmp;
				tmp = "";
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		if (isalpha(ans[i]))
			ans[i] = tolower(ans[i]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/5637