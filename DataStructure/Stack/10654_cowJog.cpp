#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

ll N, T, P, S;

stack<ll> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		cin >> P >> S;
		ll now = P + S * T;
		while (!s.empty() && s.top() >= now)
			s.pop();
		s.push(now);
	}
	cout << (int)s.size() << '\n';
}

// https://www.acmicpc.net/problem/10654