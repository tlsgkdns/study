#include <iostream>
#include <stack>

using namespace std;
int N, X, Y, ans = 0;
int h[50001];
stack<int> s;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;
		h[i] = Y;
	}
	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && s.top() > h[i])
			s.pop();
		if (!s.empty() && s.top() == h[i]) continue;
		if (h[i] > 0)
		{
			s.push(h[i]);
			ans++;
		}
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1863