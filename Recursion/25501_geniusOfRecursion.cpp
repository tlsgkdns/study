#include <iostream>

using namespace std;

int T, cnt = 0;
string S;
int solve(int l, int r)
{
	++cnt;
	if (r <= l) return 1;
	if (S[l] == S[r]) return solve(l + 1, r - 1);
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--)
	{
		cnt = 0;
		cin >> S;
		cout << solve(0, S.size() - 1) << " ";
		cout << cnt << '\n';
	}
}

// https://www.acmicpc.net/problem/25501