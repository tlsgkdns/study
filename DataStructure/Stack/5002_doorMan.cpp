#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

stack<bool> s;
int X, ans = 0;
string L;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> X;
	cin >> L;
	for (int i = L.size() - 1; i >= 0; i--) s.push(L[i] == 'M');
	int mcnt = 0, wcnt = 0;
	while (!s.empty())
	{
		bool now = s.top();
		s.pop();
		if (now) mcnt++;
		else wcnt++;
		if (abs(mcnt - wcnt) > X)
		{
			if (now) mcnt--;
			else wcnt--;

			if (!s.empty() && s.top() != now)
			{
				bool n = s.top();
				s.pop();
				s.push(now);
				s.push(n);
			}
			else
			{
				break;
			}
		}
	}
	ans = wcnt + mcnt;
	cout << ans << '\n';
}


// https://www.acmicpc.net/problem/5002