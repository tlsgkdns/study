#include <iostream>
#include <set>

using namespace std;
int N, ans = 0;
string s;
set<string> S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> s;
		if (s == "ENTER")
			S.clear();
		else if (S.find(s) == S.end())
		{
			++ans;
			S.insert(s);
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25192