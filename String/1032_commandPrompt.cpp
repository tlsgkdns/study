#include <iostream>

using namespace std;

int N;
string S, ans = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> S;
		if (ans.empty()) ans = S;
		for (int i = 0; i < S.size(); i++)
			if (ans[i] != S[i])
				ans[i] = '?';
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1032