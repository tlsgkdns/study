#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> h;
stack<ll> s;
int N, H;
ll ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> H;
		h.push_back(H);
	}
	for (int i = 0; i < N; i++)
	{
		if (s.empty() || h[s.top()] > h[i])
			s.push(i);
		else
		{
			while (!s.empty() && h[s.top()] <= h[i])
			{
				ans += i - s.top() - 1;
				s.pop();
			}
			s.push(i);
		}
	}
	while (!s.empty())
	{
		ans += N - s.top() - 1;
		s.pop();
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/6198