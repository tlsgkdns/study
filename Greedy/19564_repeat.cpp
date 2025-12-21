#include <iostream>

using namespace std;
int ans = 1;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> S;
	for (int i = 1; i < S.size(); i++)
		ans += (S[i] <= S[i - 1]);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/19564