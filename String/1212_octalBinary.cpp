#include <iostream>
#include <algorithm>

using namespace std;
string b[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
string S, ans = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		ans += b[S[i] - '0'];
	}
	if (ans[0] == '0') ans = string(ans.begin() + 1, ans.end());
	if (ans[0] == '0') ans = string(ans.begin() + 1, ans.end());
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1212