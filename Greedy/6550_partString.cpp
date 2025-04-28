#include <iostream>
#include <algorithm>

using namespace std;

string S, T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> S >> T;
		if (cin.eof()) break;
		int idx = 0;
		string ans = "No\n";
		for (int i = 0; i < T.size(); i++)
			if (S[idx] == T[i])
			{
				++idx;
				if (idx == S.size())
				{
					ans = "Yes\n";
					break;
				}
			}
		cout << ans;
	}
}

// https://www.acmicpc.net/problem/6550