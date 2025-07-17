#include <iostream>

using namespace std;

string S;
int ans = 10;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 1; i < S.size(); i++)
		if (S[i] != S[i - 1])
			ans += 10;
		else
			ans += 5;
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/7567