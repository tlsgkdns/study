#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
ll N, T[100003], ans = 0;
stack<int> S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> T[i];
	T[N] = 0;
	for (int i = 0; i <= N; i++)
	{
		while (!S.empty() && T[S.top()] >= T[i])
		{
			ll now = S.top();
			S.pop();
			ll w = (S.empty()) ? i : i - S.top() - 1;
			ans = max(ans, T[now] * w);
		}
		S.push(i);
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/12846