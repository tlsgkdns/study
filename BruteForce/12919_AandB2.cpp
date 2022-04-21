#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S, T;
int ans = 0;

void check()
{
	if (ans) return;
	if (S.size() == T.size())
	{
		if (S == T) ans = 1;
		return;
	}
	if (T.back() == 'A')
	{
		T.pop_back();
		check();
		T.push_back('A');
	}
	if (T.front() == 'B')
	{
		reverse(T.begin(), T.end());
		T.pop_back();
		check();
		T.push_back('B');
		reverse(T.begin(), T.end());
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	cin >> T;
	check();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12919