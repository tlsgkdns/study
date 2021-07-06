#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string s;
	vector<int> ans;
	while (true)
	{
		int a = 0;
		cin >> s;
		stack<char> st;
		if (s[0] == '-') break;
		for (char c : s)
		{
			if (c == '{') st.push(c);
			else if (st.empty())
			{
				a++;
				st.push(c);
			}
			else st.pop();
		}

		a += (st.size() / 2);
		ans.push_back(a);
	}
	for (int i = 1; i <= ans.size(); i++)
		cout << i << ". " << ans[i - 1] << '\n';
}
// https://www.acmicpc.net/problem/4889