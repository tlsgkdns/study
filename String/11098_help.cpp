#include <iostream>

using namespace std;

int T, C, P;
string S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> P;
		string ans = "";
		int c = 0;
		while (P--)
		{
			cin >> C >> S;
			if (c < C)
			{
				c = C;
				ans = S;
			}
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/11098