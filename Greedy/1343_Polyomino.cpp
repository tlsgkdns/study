#include <iostream>

using namespace std;

string P, ans = "";
int cnt = 0;
bool f = false;
void chk()
{
	if (cnt == 0) return;
	if (cnt % 2 > 0)
	{
		f = true;
		return;
	}
	while (cnt >= 4)
	{
		ans += "AAAA";
		cnt -= 4;
	}
	if (cnt > 0) ans += "BB";
	cnt = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> P;
	P.push_back('.');
	for (int i = 0; i < P.size() && !f; i++)
	{
		if (P[i] == '.')
		{
			chk();
			if (i < P.size() - 1) ans.push_back('.');
		}
		else
		{
			++cnt;
		}
	}
	if (f) cout << -1 << '\n';
	else cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1343