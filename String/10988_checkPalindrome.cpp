#include <iostream>

using namespace std;
string S;
int ans = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size() / 2; i++)
	{
		if (S[i] != S[S.size() - 1 - i])
		{
			ans = 0;
			break;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10988