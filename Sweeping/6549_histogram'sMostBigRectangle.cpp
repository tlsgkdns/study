#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using ll = long long;

vector<ll> ans;
int n;
int main()
{
	while (true)
	{
		vector<ll> h;
		stack<ll> s;
		ll a = 0;
		cin >> n;
		if (n == 0) break;
		h.resize(n + 1);
		for (int i = 0; i < n; i++)
			cin >> h[i];
		h.push_back(0);
		for (int i = 0; i < n + 1; i++)
		{
			while (!s.empty() && h[s.top()] >= h[i])
			{
				int j = s.top();
				s.pop();
				int width = -1;
				if (s.empty())
					width = i;
				else
					width = (i - s.top() - 1);
				a = max(a, h[j] * width);
			}
			s.push(i);
		}
		ans.push_back(a);
	}
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/6549