#include <iostream>
#include <stack>
using namespace std;

int N, ans = 0;
string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		stack<char> s;
		cin >> str;
		for (int idx = 0; idx < str.size(); idx++)
		{
			if (!s.empty() && s.top() == str[idx])
				s.pop();
			else
				s.push(str[idx]);
		}
		ans += (s.empty());
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/3986