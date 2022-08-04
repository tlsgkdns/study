#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100001;
string stick;
stack<int> s;
int n = 0, ans = 0;
int h[MAX];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> stick;
	for (int i = 0; i < (int)stick.size(); i++)
	{
		if (stick[i] == '(')
			s.push(i);
		else
		{
			if (s.top() + 1 == i)
			{
				s.pop();
				h[(int)s.size()]++;
			}
			else
			{
				s.pop();
				h[(int)s.size()] += h[(int)s.size() + 1];
				ans += h[(int)s.size() + 1] + 1;
				h[(int)s.size() + 1] = 0;
			}
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/10799