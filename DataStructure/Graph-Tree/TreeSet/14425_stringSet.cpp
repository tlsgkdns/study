#include <iostream>
#include <set>
using namespace std;

set<string> S;
int N, M, ans = 0;
string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	while (N--)
	{
		cin >> str;
		S.insert(str);
	}
	while (M--)
	{
		cin >> str;
		ans += (S.find(str) != S.end());
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/14425