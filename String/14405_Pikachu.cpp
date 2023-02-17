#include <iostream>

using namespace std;

string S, P[3] = { "pi", "ka", "chu" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	int idx = 0;
	while (idx < (int)S.size())
	{
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			string tmp(S.begin() + idx, S.begin() + idx + P[i].size());
			if (tmp == P[i])
			{
				idx += (int)P[i].size();
				break;
			}
		}
		if (i >= 3)
			break;
	}
	if (idx == S.size()) cout << "YES\n";
	else cout << "NO\n";
}

// https://www.acmicpc.net/problem/14405