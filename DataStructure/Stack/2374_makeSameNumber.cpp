#include <iostream>
#include <stack>

using ll = long long;
using namespace std;
ll A[1001], N, ans = 0;
stack<ll> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
	{
		if (s.empty() || s.top() > A[i])
			s.push(A[i]);
		else if (s.top() < A[i])
		{
			ans += (A[i] - s.top());
			while (!s.empty() && s.top() < A[i]) s.pop();
			s.push(A[i]);
		}
	}
	ll now = s.top();
	s.pop();
	while (!s.empty())
	{
		ans += s.top() - now;
		now = s.top();
		s.pop();
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2374