#include <iostream>
#include <set>

using ll = long long;
using namespace std;
set<ll> S;
ll A, B;
string ans = "";
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	S.insert(A);
	if (A == B) ans = "*";
	else if (A == 0) ans = "-";
	else
	{
		while (ans.size() < 120)
		{
			if (A == 0)
			{
				ans = "-1";
				break;
			}
			if (B / 2 < A)
			{
				ans.push_back('*');
				A = A + (A - B);
			}
			else
			{
				ans.push_back('-');
				A = (A + A) % B;
			}
		}
		for (int i = 1; i <= 60; i++)
		{
			string pattern(ans.begin(), ans.begin() + i);
			string str = "";
			while (str.size() < ans.size()) str += pattern;
			if (string(str.begin(), str.begin() + ans.size()) == ans)
			{
				ans = pattern;
				break;
			}
		}
		if (ans.size() > 60) ans = "-1";
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1341