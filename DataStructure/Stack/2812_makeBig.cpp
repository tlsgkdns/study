#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n, k, cnt = 0;
string s, ans = "";
stack<int> st;
int main()
{
	cin >> n >> k;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (cnt == k)
		{
			st.push(s[i]);
			continue;
		}
		if (st.empty())
			st.push(s[i]);
		else
		{
			while (!st.empty() && st.top() < s[i])
			{
				st.pop();
				cnt++;
				if (cnt == k) break;
			}
			st.push(s[i]);
		}
	}
	while (cnt != k)
	{
		cnt++;
		st.pop();
	}
	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2812