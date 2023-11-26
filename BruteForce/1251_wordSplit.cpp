#include <iostream>

using namespace std;

string S, ans = "";

void solve(int idx1, int idx2)
{
	string tmp = "";
	for (int i = idx1; i >= 0; i--) tmp.push_back(S[i]);
	for (int i = idx2; i > idx1; i--)tmp.push_back(S[i]);
	for (int i = S.size() - 1; i > idx2; i--) tmp.push_back(S[i]);
	if (ans > tmp) ans = tmp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	for (int i = 0; i < S.size(); i++) ans.push_back('z');
	for (int i = 0; i < S.size(); i++)
		for (int j = i + 1; j < S.size() - 1; j++)
			solve(i, j);
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1251