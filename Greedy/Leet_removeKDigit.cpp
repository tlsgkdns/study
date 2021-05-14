#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string num, tmp = "";
	int k, idx = 0, i = 0;
	cin >> num;
	cin >> k;
	stack<char> s;
	for (i = 0; i < num.length(); i++)
	{
		if (k == 0) break;
		if (s.empty())
		{
			s.push(num[i]);
			continue;
		}
		while (!s.empty() && s.top() > num[i])
		{
			s.pop();
			k--;
		}
		s.push(num[i]);
	}
	for (; i < num.length(); i++)
		s.push(num[i]);
	while (k > 0)
	{
		s.pop();
		k--;
	}
	while (!s.empty())
	{
		tmp = s.top() + tmp;
		s.pop();
	}
	for (; idx < tmp.length(); idx++)
		if (tmp[idx] != '0')
			break;
	string ans(tmp.begin() + idx, tmp.end());
	if (ans.empty()) ans = "0";
	cout << ans << '\n';
}

//https://leetcode.com/problems/remove-k-digits/