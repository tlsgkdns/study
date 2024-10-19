#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

string S[2], ans = "";
deque<char> a, b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> S[0];
	cin >> S[1];
	ans = string(S[0].size(), '?');
	sort(S[0].begin(), S[0].end());
	sort(S[1].begin(), S[1].end(), greater<char>());
	for (int i = 0; i < S[0].size() / 2 + S[0].size() % 2; i++) a.push_back(S[0][i]);
	for (int i = 0; i < S[1].size() / 2; i++) b.push_back(S[1][i]);
	int idx1 = 0, idx2 = S[0].size() - 1, idx = 0;
	bool t = false;
	while (idx1 <= idx2)
	{
		if (!t)
		{
			if (b.empty() || a.front() < b.front())
			{
				ans[idx1++] = a.front();
				a.pop_front();
			}
			else
			{
				ans[idx2--] = a.back();
				a.pop_back();
			}
		}
		else
		{
			if (a.empty() || a.front() < b.front())
			{
				ans[idx1++] = b.front();
				b.pop_front();
			}
			else
			{
				ans[idx2--] = b.back();
				b.pop_back();
			}
		}
		t = !t;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/16890