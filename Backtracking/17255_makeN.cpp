#include <iostream>
#include <string>
using namespace std;
int N;
string str, now = "";
int ans = 0, alp[10];
void solve()
{
	if (now == str)
	{
		ans++;
		return;
	}
	for (int i = 0; i < 10; i++)
		if (alp[i] > 0)
		{
			alp[i]--;
			now.push_back(i + '0');
			string tmp = now;
			solve();
			now.pop_back();
			string nxt = (char)('0' + i) + now;
			if (tmp != nxt)
			{
				now = nxt;
				solve();
				now = string(now.begin() + 1, now.end());
			}
			alp[i]++;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N; str = to_string(N);
	for (int i = 0; i < str.size(); i++)
		alp[str[i] - '0']++;
	solve();
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/17255