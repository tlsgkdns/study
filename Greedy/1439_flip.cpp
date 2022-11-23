#include <iostream>

using namespace std;

string S;
char ch = 'S';
int cnt[2] = { 0, 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
		if (ch != S[i])
		{
			ch = S[i];
			cnt[S[i] - '0']++;
		}
	if (cnt[0] < cnt[1]) cout << cnt[0] << '\n';
	else cout << cnt[1] << '\n';
}

// https://www.acmicpc.net/problem/1439